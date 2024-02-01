#include "simul.h"
#include "ui_simul.h"
#include "simul.h"
#include "jo.h"
#include "mainwindow.h"
#include "arrondissement.h"
#include "aboutus.h"

#include <QMessageBox>
#include <QDir>
#include <QJsonDocument>

simul::simul(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simul)
{
    ui->setupUi(this);


    //Add some json files to combobox as option for easier use
    QStringList jsonFiles = {"","place.json"}; // Add more JSON file names here
    ui->jSONComboBox->addItems(jsonFiles);

    // Connect the currentIndexChanged signal to a slot
    connect(ui->jSONComboBox, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onJsonFileSelected(const QString &)));

    //Setup background image
    QPixmap backgroundImage(QDir::currentPath() +"/images/simuu.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);

    
    //Init of simulation
    connect(ui->pushButton_startSimul, &QPushButton::clicked, this, &simul::startSimulation);
    //Step simulation
    connect(ui->pushButton_stepSimul, &QPushButton::clicked, this, &simul::oneStepSimulation);
    //End simulation
    connect(ui->pushButton_endSimul, &QPushButton::clicked, this, &simul::endSimulation);

    connect(ui->AboutUsButton, &QPushButton::clicked, this, &simul::on_AboutUSButton_clicked);

}

simul::~simul()
{
    delete ui;
    connect(ui->arrondissementButton, &QPushButton::clicked, this, &simul::on_arrondissementButton_clicked);
    connect(ui->JOButton, &QPushButton::clicked, this, &simul::on_JOButton_clicked);
    connect(ui->onHomeButton, &QPushButton::clicked, this, &simul::goToMainWindow);
}


void simul::on_JOButton_clicked()
{
    hide();
    JO *jo = new JO(this);
    jo->show();
}

void simul::on_arrondissementButton_clicked()
{
    hide();
    arrondissement *arrondissements = new arrondissement(this);
    arrondissements -> show();
}

void simul::goToMainWindow()
{
    // Créez une instance de MainWindow et montrez-la
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Fermez la fenêtre actuelle (arrondissement)
    this->close();
}

void simul::on_AboutUSButton_clicked()
{
    hide();
    AboutUS *AboutUs = new AboutUS(this);
    AboutUs -> show();
}
void simul::onJsonFileSelected(const QString &fileName)
{
    selectedJsonFilePath = ":/places/Json/" + fileName; // Store the file path in the member variable

    QFile file(selectedJsonFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));
}

void simul::startSimulation()
{   
    //  /!\ gives segmentation fault.
    // //Delete previous simul
    // qDebug()<<"delete ancien model si existant";
    // if(cityModel){
    //     qDebug()<<"delete car existe";
    //     delete cityModel;
    //     qDebug()<<"delete successful";
    //     cityModel = nullptr;
    // }
    qDebug()<<"recupere path pour json file";
    QString filePath;
    if (selectedJsonFilePath.isEmpty()) {
        filePath = ui->jSONPathLineEdit->text(); // Use the line edit text if no file is selected in the combo box
    } else {
        filePath = selectedJsonFilePath; // Use the selected file path otherwise
    }
    //QString filePath = ":/places/place.json";
    qDebug()<<"recupere nombre de persons a init dans la solution";
    int popSize = ui->numberOfPeopleLineEdit->text().toInt();
    qDebug()<<"Appele constructeur";
    if(filePath!=""&&popSize){
        cityModel = new CityModel(filePath,popSize);
         qDebug()<<"CityModel bien créer";

        //Verification places initialisation
        cityModel->displayInfoPlaces();
    
    QMessageBox::information(this, "Simulation", "Initialization successful");
    }else{
        QMessageBox::information(this,"Simulation","Missing parameters!!");
    }
    

}

void simul::oneStepSimulation()
{
    //Verification si cityModel existe (pas pointeur null)
    if(cityModel){
        cityModel->runSimulation(1);
        displayPlacesAndStats();
    }else{
        qWarning("CityModel not yet initialized, press start button first");
    }
}

//Segmentation fault 
void simul::endSimulation(){
    // if(cityModel != nullptr) {
    //     delete cityModel;
    //     qDebug()<<"delete succesfull";
    //     cityModel = nullptr;
    // }else{
    //     qDebug()<<"CityModel not defined yet";
    // }
    QMessageBox::information(this, "Simulation", "Not Implemented Yet");
}

void simul::displayPlacesAndStats(){
    //Get all locations first
    auto listPlaces = cityModel->getAllLocations();
    //Create places size number of row
    ui->tableWidget->setRowCount(listPlaces.size());
    //Set 3 columns because 3 elements to display
    ui->tableWidget->setColumnCount(4);
    QStringList headers;
    //Define different headers (columns)
    headers << "Place (name)" << "Number of People" << "Total Wait Time (minutes)"<<"Queue time(or mean waiting time)";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int i = 0; i < listPlaces.size(); ++i) {
        auto place = listPlaces[i];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(place->getName()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(place->getPeopleHere())));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(place->getTotalWaitingHere())));
        if(place->getPeopleHere() != 0) { // Avoid division by zero
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(place->getTotalWaitingHere() / place->getPeopleHere())));
        } else {
            ui->tableWidget->setItem(i, 3, new QTableWidgetItem("0"));
        }
    }
    //Resize
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}