#include "simul.h"
#include "ui_simul.h"
#include "simul.h"
#include "jo.h"
#include "mainwindow.h"
#include "arrondissement.h"

simul::simul(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::simul)
{
    ui->setupUi(this);
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
