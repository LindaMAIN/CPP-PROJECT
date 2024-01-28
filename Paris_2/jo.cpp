#include "jo.h"
#include "ui_jo.h"
#include "arrondissement.h"
#include "simul.h"
#include "aboutus.h"

JO::JO(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::JO)
{
    ui->setupUi(this);
   // connect(ui->AboutUSButton, &QPushButton::clicked, this, &JO::on_AboutUSButton_clicked);
    connect(ui->arrondissementButton, &QPushButton::clicked, this, &JO::on_arrondissementButton_clicked);
    connect(ui->simButton, &QPushButton::clicked, this, &JO::on_simButton_clicked);
}

JO::~JO()
{
    delete ui;
}


void JO::on_arrondissementButton_clicked()
{
    hide();
    QMainWindow *mainWindow = new QMainWindow(this);
    mainWindow->show();
}

void JO::on_simButton_clicked()
{
    hide();
    simul *simulation = new simul(this);
    simulation->show();
}
