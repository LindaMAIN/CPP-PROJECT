#include "simul.h"
#include "ui_simul.h"
#include "simul.h"
#include "jo.h"

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
    QMainWindow *mainWindow = new QMainWindow(this);
    mainWindow->show();
}
