#include "jo.h"
#include "ui_jo.h"
#include "arrondissement.h"
#include "simul.h"
#include "aboutus.h"
#include <QMessageBox>
#include "mainwindow.h"
#include <QDir>

JO::JO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JO)
{
    ui->setupUi(this);
    QPixmap backgroundImage(QDir::currentPath() +"/images/joo.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);

    QGraphicsScene *siteOlympiqueScene = new QGraphicsScene(this);
    QGraphicsScene *zoneCouleurScene = new QGraphicsScene(this);

    QPixmap siteOlympiqueImage(QDir::currentPath() +"/images/cartejo.png");
    siteOlympiqueScene->addPixmap(siteOlympiqueImage);

    QPixmap zoneCouleurImage(QDir::currentPath() +"/images/carte_jo1.png");
    zoneCouleurScene->addPixmap(zoneCouleurImage);

    ui->siteOlympiqueView->setScene(siteOlympiqueScene);
    ui->zoneCouleurView->setScene(zoneCouleurScene);

    connect(ui->AboutUSButton, &QPushButton::clicked, this, &JO::on_AboutUSButton_clicked);
    connect(ui->arrondissementButton, &QPushButton::clicked, this, &JO::on_arrondissementButton_clicked);
    connect(ui->simButton, &QPushButton::clicked, this, &JO::on_simButton_clicked);

    connect(ui->RButton, &QPushButton::clicked, this, &JO::on_zonesRougesButton_clicked);
    connect(ui->BButton, &QPushButton::clicked, this, &JO::on_zonesBleuesButton_clicked);
    connect(ui->GButton, &QPushButton::clicked, this, &JO::on_zonesGrisButton_clicked);
    connect(ui->onHomeButton, &QPushButton::clicked, this, &JO::goToMainWindow);

}

JO::~JO()
{
    delete ui;
}


void JO::on_arrondissementButton_clicked()
{
    hide();
    arrondissement *arrondissements = new arrondissement(this);
    arrondissements -> show();
}

void JO::on_simButton_clicked()
{
    hide();
    simul *simulation = new simul(this);
    simulation->show();
}


void JO::on_AboutUSButton_clicked()
{
    hide();
    AboutUS *AboutUs = new AboutUS(this);
    AboutUs -> show();
}
void JO::on_zonesRougesButton_clicked()
{
    afficherInformationsZone("Zones Rouges");
}

void JO::on_zonesBleuesButton_clicked()
{
    afficherInformationsZone("Zones Bleues");
}

void JO::on_zonesGrisButton_clicked()
{
    afficherInformationsZone("Zones Grises");
}

void JO::afficherInformationsZone(const QString &nomZone)
{
    QString informations;

    if (nomZone == "Zones Rouges")
    {
        informations = "Zone Rouge : La circulation sera interdite, sauf dérogation, par exemple, au niveau du Parc des Princes, du Village des athlètes à Saint-Denis, de l’Accor Arena ou du Stade Yves-du-Manoir à Colombes (Hauts-de-Seine).";
    }
    else if (nomZone == "Zones Bleues")
    {
        informations = "Zone Bleue : La circulation ne sera pas interdite mais réglementée pour éviter «les circulations de transit». Ne pourront y accéder en voiture que les personnes qui vivent, travaillent ou veulent se rendre dans un commerce ou un restaurant de cette zone.";
    }
    else if (nomZone == "Zones Grises")
    {
        informations = "Zone Grise : Ne pourront y rentrer que les athlètes, les personnes accréditées par l’organisateur Paris 2024 et les spectateurs munis de billet.";
    }

    // Affiche les informations dans une boîte de dialogue
    QMessageBox::information(this, "Informations Zone", informations);
}

void JO::on_pushButton_clicked()
{
    QString informations = "Durant les JO , Paris sera délimité en plusieurs zones et selon la zone il faudra avoir une dérogation :( . Faites attention ";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_8_clicked()
{
    QString informations = "Athlétisme\n\nDu jeudi 1er août au dimanche 11 août.\n\n"
                           "Décathlon hommes : 2 et 3 août\n"
                           "Finale 100 m femmes : 3 août\n"
                           "Finale 100 m hommes : 4 août\n"
                           "Saut à la perche hommes : 5 août\n"
                           "Finale relais 4x100m femmes et hommes : 9 août\n"
                           "Marathon hommes : 10 août\n"
                           "Marathon femmes : 11 août";

    QMessageBox::information(this,"Informations",informations);
}


void JO::on_pushButton_9_clicked()
{
    QString informations = "Du samedi 27 juillet au samedi 3 août. Finales à partir du 31 juillet.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_2_clicked()
{
    QString informations = "Du samedi 27 juillet au lundi 5 août.";
    QMessageBox::information(this,"Informations JO",informations);

}


void JO::on_pushButton_10_clicked()
{
    QString informations = "Du mardi 30 juillet au lundi 5 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_12_clicked()
{
    QString informations = "Du samedi 27 juillet au dimanche 11 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_17_clicked()
{
    QString informations = "Du samedi 27 juillet au samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_13_clicked()
{
    QString informations = "Mardi 30 et mercredi 31 juillet.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_14_clicked()
{
    QString informations = "Jeudi 1er et vendredi 2 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_3_clicked()
{
    QString informations = "Du samedi 27 juillet au samedi 10 août.\n\n""Finale femmes 75 kg : 10 août\n"
                               "Finale hommes +92 kg : 10 août\n";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_11_clicked()
{
    QString informations = "Vendredi 9 et samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_16_clicked()
{
    QString informations = "Du samedi 27 juillet au lundi 5 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_15_clicked()
{
    QString informations = "Du mardi 6 août au samedi 10 août. Finales : 8, 9 et 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_18_clicked()
{
    QString informations = "Du samedi 27 juillet au dimanche 4 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_19_clicked()
{
    QString informations = "Du lundi 5 août au dimanche 11 août";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_4_clicked()
{
    QString informations = "Du lundi 5 août au samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_20_clicked()
{
    QString informations = "Du samedi 27 juillet au dimanche 4 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_21_clicked()
{
    QString informations = "Du mercredi 24 juillet au samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_22_clicked()
{
    QString informations = "Du jeudi 1er août au samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_23_clicked()
{
    QString informations = "Du samedi 27 juillet au lundi 5 août pour rythmique \n ""Gymnastique trampoline : Vendredi 2 août.\n";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_24_clicked()
{
    QString informations = "Du jeudi 25 juillet au dimanche 11 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_5_clicked()
{
    QString informations = "Du mercredi 7 août au dimanche 11 août. Médailles chaque jour.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_25_clicked()
{
    QString informations = "Du samedi 27 juillet au vendredi 9 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_26_clicked()
{
    QString informations = "Du samedi 27 juillet au samedi 3 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_27_clicked()
{
    QString informations = "Du lundi 5 août au dimanche 11 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_28_clicked()
{
    QString informations = "Du jeudi 8 août au dimanche 11 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_29_clicked()
{
    QString informations = "Du samedi 27 juillet au samedi 10 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_6_clicked()
{
    QString informations = "Du samedi 27 juillet au dimanche 4 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_30_clicked()
{
    QString informations = "Du mercredi 24 juillet au mardi 30 juillet.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_31_clicked()
{
    QString informations = "Samedi 27 et dimanche 28 juillet, mardi 6 et mercredi 7 août.";
    QMessageBox::information(this,"Informations JO",informations);
}


void JO::on_pushButton_32_clicked()
{
    QString informations = "Du samedi 27 juillet au mardi 6 août.";
    QMessageBox::information(this,"Informations JO",informations);
}

void JO::goToMainWindow()
{
    // Créez une instance de MainWindow et montrez-la
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    // Fermez la fenêtre actuelle (arrondissement)
    this->close();
}
