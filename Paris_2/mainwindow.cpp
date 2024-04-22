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
#include <QFileDialog>
#include <QLineEdit>
#include <QGraphicsPixmapItem>
#include <QTranslator>
#include <QLocale>
#include <QCoreApplication>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include "arrondissement.h"
#include "jo.h"
#include "aboutus.h"
#include <QFile>
#include <QDir>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap backgroundImage(":/images/images/w1.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);

    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    connect(ui->playVideoButton, &QPushButton::clicked, this, &MainWindow::on_playVideoButton_clicked);

    scene = new MyGraphicsScene;
    svgItem = new QGraphicsSvgItem(":/images/images/map.svg");
    svgItem->setFlag(QGraphicsItem::ItemIgnoresTransformations);
    scene->addItem(svgItem);

    // Associer à la vue ui graphicsView
    ui->graphicsView->setScene(scene);



    connect(ui->arrondissementButton, &QPushButton::clicked, this, &MainWindow::on_arrondissementButton_clicked);
    //connect(ui->zonesButton, &QPushButton::clicked, this, &MainWindow::zonesButton);
    connect(ui->AboutUSButton, &QPushButton::clicked, this, &MainWindow::on_AboutUSButton_clicked);


    ui->comboBoxLanguage->addItem("French", "fr_FR");
    ui->comboBoxLanguage->addItem("English", "en_US");
    ui->comboBoxLanguage->addItem("Chinese", "zh_CN");
    ui->comboBoxLanguage->addItem("Arabic", "ar_AR");
    ui->comboBoxLanguage->addItem("Spanish", "es_ES");
    ui->comboBoxLanguage->addItem("German", "de_DE");


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
    QMessageBox::information(this, "About Us", "The creators");
}

void MainWindow::JOButton()
{
    QMessageBox::information(this, "Les sites JO", "JO SITES");
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
        qDebug() << "Loaded translation file: Paris_" + languageCode + ".qm";
        qDebug() << "Translated text for 'Welcome to Paris': " << welcomeText;
    }
}



void MainWindow::onMediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    qDebug() << "Media status changed: " << status;

    if (status == QMediaPlayer::EndOfMedia) {
        qDebug() << "End of media reached. Returning to main window.";

        player->stop();

        if (ui->centralwidget) {
            setCentralWidget(ui->centralwidget);
            qDebug() << "Application should be back to main window.";
        } else {
            qDebug() << "Central widget is null.";
        }
    }
}

void MainWindow::playVideo()
{
    player->setMedia(QUrl("qrc:/videos/videos/paris.mp4"));


    // Afficher le lecteur vidéo
    setCentralWidget(videoWidget);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onMediaStatusChanged);

    // Lancer la lecture
    player->play();
}

void MainWindow::on_zonesButton_clicked()
{
    hide();
    zones = new zone(this);
    zones -> show();
}


void MainWindow::on_playVideoButton_clicked()
{
    QString videoFilePath = ":/videos/videos/paris.mp4";

    // Utilisez les membres de la classe plutôt que de créer de nouvelles instances
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl(videoFilePath));

    // Afficher le widget vidéo
    setCentralWidget(videoWidget);

    connect(player, &QMediaPlayer::mediaStatusChanged, this, &MainWindow::onMediaStatusChanged);

    // Lancer la lecture
    player->play();
}
