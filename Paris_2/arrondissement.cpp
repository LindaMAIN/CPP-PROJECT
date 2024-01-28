#include <QGraphicsScene>
#include <QGraphicsSvgItem>
#include <QGraphicsSceneMouseEvent>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>
#include <QDebug>
#include "aboutus.h"
#include "arrondissement.h"
#include "ui_arrondissement.h"
#include "jo.h"
#include "simul.h"

arrondissement::arrondissement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arrondissement)
{
    ui->setupUi(this);
    //connect(ui->homeButton, &QPushButton::clicked, this, &arrondissement::on_homeButton_clicked);
    connect(ui->JOButton, &QPushButton::clicked, this, &arrondissement::on_JOButton_clicked);
    connect(ui->simButton, &QPushButton::clicked, this, &arrondissement::on_simButton_clicked);
}

arrondissement::~arrondissement()
{
    delete ui;
}


void arrondissement::on_JOButton_clicked()
{
    hide();
    JO *jo = new JO(this);
    jo->show();
}

void arrondissement::on_simButton_clicked()
{
    hide();
    simul *simulation = new simul(this);
    simulation->show();
}
