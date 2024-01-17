#include "mainwindow.h"
#include "ui_mainwindow.h"

//export PATH=/home/zclem/Qt/6.6.1/gcc_64/bin:$PATH

#include <QPixmap>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainStackedWidget = ui->mainStackedWidget;

    //MAP display
    QPixmap pix(QDir::currentPath() + "/images/paris_map.png");
    qDebug() << QDir::currentPath() + "/images/paris_map.png";

    if (pix.isNull()) {
    qDebug() << "Failed to load image file";
    } 
    else {
        QLabel *mapLabel = new QLabel(this); // Create a new QLabel
        mapLabel->setPixmap(pix); // Set the QPixmap to the QLabel
        ui->verticalLayout_map->addWidget(mapLabel); // Add the QLabel to your layout
    }

    //Create an action with menu
    QAction* accueilAction = ui->menuMenu->addAction("Accueil Page");
    QAction* settingsAction = ui->menuMenu->addAction("Simulation Settings Page");
    QAction* analyseAction = ui->menuMenu->addAction("Analyse Page");
    QAction* overviewAction = ui->menuMenu->addAction("Overview Page");

    connect(accueilAction, &QAction::triggered, this, &MainWindow::showFirstPage);
    connect(settingsAction, &QAction::triggered, this, &MainWindow::showMainPage);
    connect(analyseAction, &QAction::triggered, this, &MainWindow::showAnalysePage);
    connect(overviewAction, &QAction::triggered, this, &MainWindow::showOverviewPage);

//////
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Index set to alphabetical order
void MainWindow::showFirstPage(){
    mainStackedWidget->setCurrentIndex(0);
}
void MainWindow::showOverviewPage(){
    mainStackedWidget->setCurrentIndex(1);
}
void MainWindow::showAnalysePage(){
    mainStackedWidget->setCurrentIndex(2);
}
void MainWindow::showMainPage(){
    mainStackedWidget->setCurrentIndex(3);
}
