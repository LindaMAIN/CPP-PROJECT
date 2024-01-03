#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>
#include <QDebug>
#include <QDir>
#include "zones.h"
#include "restaurants.h"
#include "villagejodetailsdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    //ptrzone(new zones()),
    ptrRestaurant(new RESTAURANTS())
{
    ui->setupUi(this);

    // Ajout d'une image de fond pour la carte de Paris
    QPixmap background("/home/lilyn/Desktop/projet_cpp/JO_2024/images/paris_map.png");

    // Calculer la taille ajustée tout en maintenant les proportions de l'image
    QSize adjustedSize = background.size();
    adjustedSize.scale(this->size(), Qt::KeepAspectRatio);

    // Ajuster la taille de la QLabel en fonction de la taille ajustée
    ui->mapLabel->setPixmap(background.scaled(adjustedSize));
    ui->mapLabel->setScaledContents(true);

    if (background.isNull()) {
        qDebug() << "Failed to load background image.";
    }



    // Ajout d'emojis mignons pour chaque arrondissement
    //addEmojiToArrondissement(ui->emojiLabel1, "/home/lilyn/Desktop/projet_cpp/JO_2024/images/emoji1.png");
    //addEmojiToArrondissement(ui->emojiLabel2, "/home/lilyn/Desktop/projet_cpp/JO_2024/images/emoji2.png");
    //addEmojiToArrondissement(ui->emojiLabel3, "/home/lilyn/Desktop/projet_cpp/JO_2024/images/emoji3.png");
    //addEmojiToArrondissement(ui->emojiLabel4, "/home/lilyn/Desktop/projet_cpp/JO_2024/images/emoji4.png");
    connect(ui->HomeButton, &QPushButton::clicked, this, &MainWindow::onHomeButtonClicked);
    connect(ui->villageJOButton, &QPushButton::clicked, this, &MainWindow::onJOButtonClicked);
    connect(ui->UsButton, &QPushButton::clicked, this, &MainWindow::onUsButtonClicked);
    connect(ui->restaurantsButton, &QPushButton::clicked, this, &MainWindow::onRestaurantsButtonClicked);
    connect(ui->zonesButton, &QPushButton::clicked, this, &MainWindow::onzonesButtonClicked);

    connect(ui->searchlineEdit, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->villageJOButton, &QPushButton::clicked, this, &MainWindow::onVillageJOButtonClick);

    connectArrondissementLabel(ui->emojiLabel1);
    connectArrondissementLabel(ui->emojiLabel2);
    connectArrondissementLabel(ui->emojiLabel3);
    connectArrondissementLabel(ui->emojiLabel4);
}


MainWindow::~MainWindow()
{
    delete ptrzone;
    delete ptrRestaurant;
    delete ui;
}


void MainWindow:: addEmojiToArrondissement(QLabel* label,const QString& emojiPath)
{
    QPixmap emoji(emojiPath);

    if (emoji.isNull()) {
        qDebug() << "Failed to load image:" << emojiPath;
        return;
    }

    label->setPixmap(emoji.scaled(50, 50, Qt::KeepAspectRatio));
    label->setScaledContents(true);
}

void MainWindow::connectArrondissementLabel(QLabel* label)
{
    label->installEventFilter(this);
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        QLabel* label = qobject_cast<QLabel*>(obj);
        if (label)
            onArrondissementClicked();
    }

    // Pass the event to the base class
    return QMainWindow::eventFilter(obj, event);
}


QString MainWindow::getArrondissementInfo(QLabel *label)
{
    QString arrondissementName = label->objectName();
    QString arrondissementNumber = arrondissementName.right(arrondissementName.length() - 10);  // "emojiLabel" has a length of 10 characters
    return "Informations sur l'arrondissement " + arrondissementNumber;
}

void MainWindow::onArrondissementClicked()
{
    QLabel *clickedLabel = qobject_cast<QLabel *>(sender());

    if (clickedLabel) {
        QString arrondissementInfo = getArrondissementInfo(clickedLabel);
        QMessageBox::information(this, "Informations sur l'Arrondissement", arrondissementInfo);
    }
}
void MainWindow::onHomeButtonClicked()
{
    QMessageBox::information(this, "ACCUEIL", "BIENVENUES A PARIS ET JOYEUX JO!");
}
void MainWindow::onJOButtonClicked()
{
    QMessageBox::information(this, "DATES ET ACTIVITES", "Ca va suer!!!");
}

void MainWindow::onUsButtonClicked()
{
    QMessageBox::information(this, "About Us", "Deux etudiants qui veulent valider leur année");
}

void MainWindow::onRestaurantsButtonClicked()
{
    QMessageBox::information(this, "Oui Oui Cuisine à Paris", "Liste restaurants paris!");
}

void MainWindow::onzonesButtonClicked()
{
    QMessageBox::information(this, "ZONES ET ACCESSIBILITE", "Chaud à Paris!");
}
void MainWindow::onLieuxButtonClicked()
{
    QMessageBox::information(this, "LIEUX CULTURELS", "Culture, joie et oui oui baguette");
}


void MainWindow::onSearchTextChanged(const QString &text)
{
    // Parcourez les QLabel d'arrondissement et montrez/cachez en fonction de la recherche
    for (QLabel *label : {ui->emojiLabel1, ui->emojiLabel2, ui->emojiLabel3, ui->emojiLabel4}) {
        QString labelText = label->objectName().right(1);  // Obtenez le numéro d'arrondissement à partir du nom du QLabel
        bool match = labelText.contains(text, Qt::CaseInsensitive);  // Recherche insensible à la casse

        // Montrez ou cachez le QLabel en fonction de la correspondance avec la recherche
        label->setVisible(match);
    }
}

void MainWindow::onVillageJOButtonClick(){
    VillageJODetailsDialog villageJODetailsDialog(this);
    villageJODetailsDialog.exec();
}


