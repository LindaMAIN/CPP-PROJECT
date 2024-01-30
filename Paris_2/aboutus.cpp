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
#include "ui_aboutus.h"
#include "jo.h"
#include "arrondissement.h"
#include "simul.h"
#include "mainwindow.h"


AboutUS::AboutUS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AboutUS)
{
    ui->setupUi(this);
    QPixmap backgroundImage("/home/lilyn/Desktop/final/CPP-PROJECT/Paris_2/wau.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);
    connect(ui->onHomeButton,&QPushButton::clicked, this, &AboutUS::goToMainWindow);
    connect(ui->JOButton, &QPushButton::clicked, this, &AboutUS::on_JOButton_clicked);
    connect(ui->arrondissementButton, &QPushButton::clicked, this, &AboutUS::on_arrondissementButton_clicked);
    connect(ui->simButton, &QPushButton::clicked, this, &AboutUS::on_simButton_clicked);
}


AboutUS::~AboutUS()
{
    delete ui;
}

void AboutUS::on_JOButton_clicked()
{
    hide();
    JO *jo = new JO(this);
    jo->show();
}

void AboutUS::on_arrondissementButton_clicked()
{
    hide();
    arrondissement *arrondissements = new arrondissement(this);
    arrondissements -> show();
}


void AboutUS::on_simButton_clicked()
{
    hide();
    simul *simulation = new simul(this);
    simulation->show();
}

void AboutUS::goToMainWindow()
{
    hide();
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
}
