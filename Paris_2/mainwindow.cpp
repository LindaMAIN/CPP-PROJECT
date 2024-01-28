#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include "arrondissement.h"
#include "jo.h"
#include "aboutus.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
 //   parisDepartementInfo("Paris", "Description")
{
    ui->setupUi(this);

    // Créer une scène personnalisée + item svg
   scene = new MyGraphicsScene;
   svgItem = new QGraphicsSvgItem("/home/lilyn/Desktop/Paris/map.svg");
    //svgItem = new QGraphicsSvgItem("paris.svg");
    svgItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    scene->addItem(svgItem);

    // Associer à la vue ui graphicsView
    ui->graphicsView->setScene(scene);



    connect(ui->onHomeButton, &QPushButton::clicked, this, &MainWindow::goToHome);

    connect(ui->arrondissementButton, &QPushButton::clicked, this, &MainWindow::on_arrondissementButton_clicked);
    connect(ui->zonesButton, &QPushButton::clicked, this, &MainWindow::zonesButton);
    connect(ui->AboutUSButton, &QPushButton::clicked, this, &MainWindow::on_AboutUSButton_clicked);

    ui->comboBoxLanguage->addItem("English", "en_US");
    ui->comboBoxLanguage->addItem("French", "fr_FR");
    ui->comboBoxLanguage->addItem("Chinese", "zh_CN");
    ui->comboBoxLanguage->addItem("Arabic", "ar_AR");
    ui->comboBoxLanguage->addItem("Spanish", "es_ES");
    ui->comboBoxLanguage->addItem("German", "de_DE");
    QString initialText = tr("Bienvenue à Paris, la ville lumière, connue pour son histoire riche, son architecture emblématique et son art incomparable. Nichée sur les rives de la Seine, Paris séduit avec ses célèbres monuments tels que la Tour Eiffel, le Louvre et la cathédrale Notre-Dame. Explorez les charmants arrondissements, dégustez une cuisine exquise et plongez-vous dans la culture artistique de cette métropole captivante.En 2024, Paris accueille fièrement les Jeux Olympiques, un événement mondial célébrant l'unité, l'excellence sportive et la diversité. Les Jeux Olympiques de 2024 promettent des moments inoubliables, mettant en avant l'esprit sportif, l'innovation et l'hospitalité française. Rejoignez-nous pour célébrer cette occasion unique où le monde entier se réunit dans la magnifique capitale française.Que vous soyez passionné de sport, d'histoire ou de culture, Paris a quelque chose à offrir à chacun. Profitez de l'atmosphère électrique des Jeux Olympiques et explorez la magie intemporelle de Paris, une ville qui continue de captiver et d'inspirer.");
    ui ->labelText->setText(initialText);

    // Connect the language selection signal to the onLanguageChanged slot
    connect(ui->comboBoxLanguage, QOverload<int>::of(&QComboBox::activated), this, &MainWindow::onLanguageChanged);

    //connect(ui->arrondissement1, &QPushButton::clicked, this, &MainWindow::handleArrondissementButton);
    QTranslator translator;
    translator.load("Paris_en_US.qm");
    QCoreApplication::installTranslator(&translator);


}

void MainWindow::goToHome()
{
    // Créer un effet de fondu enchaîné
    QGraphicsOpacityEffect *fadeEffect = new QGraphicsOpacityEffect(this);
    ui->graphicsView->setGraphicsEffect(fadeEffect);

    // Créer une animation pour modifier l'opacité de 1.0 (opaque) à 0.0 (transparent)
    QPropertyAnimation *fadeOutAnimation = new QPropertyAnimation(fadeEffect, "opacity");
    fadeOutAnimation->setDuration(500); // Durée de l'animation en millisecondes
    fadeOutAnimation->setStartValue(1.0);
    fadeOutAnimation->setEndValue(0.0);

    // Connecter un slot pour exécuter après l'animation
    connect(fadeOutAnimation, &QPropertyAnimation::finished, [=]() {
        // Effacer la scène et ajouter l'élément SVG
        scene->clear();
        scene->addItem(svgItem);

        // Créer une animation pour modifier l'opacité de 0.0 (transparent) à 1.0 (opaque)
        QPropertyAnimation *fadeInAnimation = new QPropertyAnimation(fadeEffect, "opacity");
        fadeInAnimation->setDuration(500); // Durée de l'animation en millisecondes
        fadeInAnimation->setStartValue(0.0);
        fadeInAnimation->setEndValue(1.0);

        // Démarrer l'animation de fondu enchaîné
        fadeInAnimation->start(QPropertyAnimation::DeleteWhenStopped);
    });

    // Démarrer l'animation de fondu enchaîné
    fadeOutAnimation->start(QPropertyAnimation::DeleteWhenStopped);
}

// Add these functions to the MainWindow class in mainwindow.cpp

void MainWindow::arrondissementButton()
{
    QMessageBox::information(this, "Arrondissements", "Displaying Arrondissements Information");
}

void MainWindow::zonesButton()
{
    QMessageBox::information(this, "Zones", "Displaying Zones Information");
}

void MainWindow::AboutUSButton()
{
    QMessageBox::information(this, "About Us", "This is an example application created by You!");
}

void MainWindow::JOButton()
{
    QMessageBox::information(this, "Les sites JO", "This is an example application created by You!");
}
void MainWindow::handleArrondissementButton()
{
    // Action lorsque le bouton de l'arrondissement est cliqué
    QMessageBox::information(this, "Arrondissement 1", "Informations sur l'arrondissement 1");
}
MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_JOButton_clicked()
{
    hide();
    jo = new JO(this);
    jo -> show();
}


void MainWindow::on_AboutUSButton_clicked()
{
    hide();
    ABoutUs = new AboutUS(this);
    ABoutUs -> show();
}


void MainWindow::on_arrondissementButton_clicked()
{
    hide();
    arrondissements = new arrondissement(this);
    arrondissements -> show();
}



void MainWindow::on_simButton_clicked()
{
    hide();
    simulation = new simul(this);
    simulation -> show();
}


void MainWindow::onLanguageChanged(int)
{
    // Get the selected language code from the combo box
    QString languageCode = ui->comboBoxLanguage->currentData().toString();

    // Load the translation for the selected language
    QTranslator translator;
    if (translator.load("Paris_"+ languageCode + ".qm"))
    {
        // Install the translator for the application
        QCoreApplication::installTranslator(&translator);

        // Update the UI to reflect the new language
        ui->retranslateUi(this);
        QString welcomeText = tr("Welcome to Paris");
        ui->labelText->setText(welcomeText);
        qDebug() << "Loaded translation file: Paris_" + languageCode + ".qm";
        qDebug() << "Translated text for 'Welcome to Paris': " << welcomeText;
    }
}

void MainWindow::on_zonesButton_clicked()
{
    hide();
    zones = new zone(this);
    zones -> show();
}

