
#include <QMessageBox>
#include <QDebug>
#include "aboutus.h"
#include "arrondissement.h"
#include "ui_arrondissement.h"
#include "mainwindow.h"
#include "jo.h"
#include "simul.h"
#include <QDir>

arrondissement::arrondissement(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::arrondissement)
{
    ui->setupUi(this);

    QPixmap backgroundImage(QDir::currentPath() +"/images/warr1.png");
    backgroundImage = backgroundImage.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, backgroundImage);
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(palette);
    connect(ui->onHomeButton, &QPushButton::clicked, this, &arrondissement::goToMainWindow);
    connect(ui->JOButton, &QPushButton::clicked, this, &arrondissement::on_JOButton_clicked);
    connect(ui->simButton, &QPushButton::clicked, this, &arrondissement::on_simButton_clicked);
    connect(ui->AboutUSButton, &QPushButton::clicked, this, &arrondissement::on_AboutUSButton_clicked);
}

arrondissement::~arrondissement()
{
    delete ui;
}
void arrondissement::goToMainWindow()
{
    hide();
    // Créez une instance de MainWindow et montrez-la
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
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

void arrondissement::on_AboutUSButton_clicked()
{
    hide();
    AboutUS *AboutUs = new AboutUS(this);
    AboutUs -> show();
}



void arrondissement::on_pushButton_8_clicked()
{
    QString informations = "1er arrondissement :\n\n"
                           "Description : Le 1er arrondissement est situé au cœur de Paris et est connu pour le Louvre.\n"
                           "Smileys : 😊🏰🛍️";
    QMessageBox::information(this, "1er arrondissement", informations);
}


void arrondissement::on_pushButton_21_clicked()
{
    QString informations = "2ème arrondissement :\n\n"
                           "Description : Le 2ème arrondissement est un quartier animé avec des commerces et des restaurants.\n"
                           "Smileys : 😃🛍️🍽️";
    QMessageBox::information(this, "2ème arrondissement", informations);
}
void arrondissement::on_pushButton_19_clicked()
{
    QString informations = "3ème arrondissement :\n\n"
                           "Description : Le 2ème arrondissement est un quartier animé avec des commerces et des restaurants.\n"
                           "Smileys : 😃🛍️🍽️";
    QMessageBox::information(this, "3ème arrondissement", informations);
}


void arrondissement::on_pushButton_20_clicked()
{
    QString informations = "4ème arrondissement :\n\n"
                           "Description : Le 4ème arrondissement abrite le quartier du Marais, connu pour son architecture médiévale.\n"
                           "Smileys : 😍🏰🏳️‍🌈";
    QMessageBox::information(this, "4ème arrondissement", informations);
}

void arrondissement::on_pushButton_18_clicked()
{
    QString informations = "5ème arrondissement :\n\n"
                           "Description : Le 5ème arrondissement est le quartier latin, riche en histoire et en institutions académiques.\n"
                           "Smileys : 📚🏛️🍷";
    QMessageBox::information(this, "5ème arrondissement", informations);
}

void arrondissement::on_pushButton_17_clicked()
{
    QString informations = "6ème arrondissement :\n\n"
                           "Description : Le 6ème arrondissement est connu pour son élégance et ses jardins, notamment le Jardin du Luxembourg.\n"
                           "Smileys : 😍🏰🌹";
    QMessageBox::information(this, "6ème arrondissement", informations);
}


void arrondissement::on_pushButton_16_clicked()
{
    QString informations = "7ème arrondissement :\n\n"
                           "Description : Le 7ème arrondissement est célèbre pour la Tour Eiffel et son élégance parisienne.\n"
                           "Smileys : 😍🗼🍾";
    QMessageBox::information(this, "7ème arrondissement", informations);
}

void arrondissement::on_pushButton_9_clicked()
{
    QString informations = "8ème arrondissement :\n\n"
                           "Description : Le 8ème arrondissement est un quartier chic avec des avenues bordées d'arbres et des boutiques de luxe.\n"
                           "Smileys : 😎🛍️💎";
    QMessageBox::information(this, "8ème arrondissement", informations);
}

void arrondissement::on_pushButton_10_clicked()
{
    QString informations = "9ème arrondissement :\n\n"
                           "Description : Le 9ème arrondissement est connu pour ses théâtres, ses cabarets et le quartier Pigalle.\n"
                           "Smileys : 🎭🎶💃";
    QMessageBox::information(this, "9ème arrondissement", informations);
}

void arrondissement::on_pushButton_11_clicked()
{
    QString informations = "10ème arrondissement :\n\n"
                           "Description : Le 10ème arrondissement est un quartier multiculturel avec des marchés animés et des cafés.\n"
                           "Smileys : 🌍🍜🍻";
    QMessageBox::information(this, "10ème arrondissement", informations);
}


void arrondissement::on_pushButton_12_clicked()
{
    QString informations = "11ème arrondissement :\n\n"
                           "Description : Le 11ème arrondissement est dynamique avec une vie nocturne animée et des restaurants branchés.\n"
                           "Smileys : 🌃🍹🎉";
    QMessageBox::information(this, "11ème arrondissement", informations);
}

void arrondissement::on_pushButton_23_clicked()
{
    QString informations = "12ème arrondissement :\n\n"
                           "Description : Le 12ème arrondissement est verdoyant avec le Bois de Vincennes et des espaces de loisirs.\n"
                           "Smileys : 🌳🏞️🚴";
    QMessageBox::information(this, "12ème arrondissement", informations);
}

void arrondissement::on_pushButton_22_clicked()
{
    QString informations = "13ème arrondissement :\n\n"
                           "Description : Le 13ème arrondissement est connu pour ses fresques murales et Chinatown.\n"
                           "Smileys : 🎨🏮🍜";
    QMessageBox::information(this, "13ème arrondissement", informations);
}

void arrondissement::on_pushButton_27_clicked()
{
    QString informations = "14ème arrondissement :\n\n"
                           "Description : Le 14ème arrondissement est résidentiel avec des parcs et la Cité Universitaire.\n"
                           "Smileys : 🏡🌳📚";
    QMessageBox::information(this, "14ème arrondissement", informations);
}


void arrondissement::on_pushButton_25_clicked()
{
    QString informations = "15ème arrondissement :\n\n"
                           "Description : Le 15ème arrondissement est familial avec des espaces verts et la Tour Montparnasse.\n"
                           "Smileys : 👨‍👩‍👧‍👦🌿🗼";
    QMessageBox::information(this, "15ème arrondissement", informations);
}

void arrondissement::on_pushButton_26_clicked()
{
    QString informations = "16ème arrondissement :\n\n"
                           "Description : Le 16ème arrondissement est chic avec des ambassades et des musées.\n"
                           "Smileys : 😎👜🏛️";
    QMessageBox::information(this, "16ème arrondissement", informations);
}

void arrondissement::on_pushButton_24_clicked()
{
    QString informations = "17ème arrondissement :\n\n"
                           "Description : Le 17ème arrondissement est résidentiel et calme, avec le Parc Monceau.\n"
                           "Smileys : 🏡🌳😌";
    QMessageBox::information(this, "17ème arrondissement", informations);
}

void arrondissement::on_pushButton_13_clicked()
{
    QString informations = "18ème arrondissement :\n\n"
                           "Description : Le 18ème arrondissement est bohème avec Montmartre et le Sacré-Cœur.\n"
                           "Smileys : 🎨🍷⛪";
    QMessageBox::information(this, "18ème arrondissement", informations);
}

void arrondissement::on_pushButton_14_clicked()
{
    QString informations = "19ème arrondissement :\n\n"
                           "Description : Le 19ème arrondissement est diversifié avec le Parc de la Villette et la Cité des Sciences.\n"
                           "Smileys : 🌈🎭🚀";
    QMessageBox::information(this, "19ème arrondissement", informations);
}

void arrondissement::on_pushButton_15_clicked()
{
    QString informations = "20ème arrondissement :\n\n"
                           "Description : Le 20ème arrondissement est dynamique avec des quartiers populaires et le Père Lachaise.\n"
                           "Smileys : 🌆🎸🌳";
    QMessageBox::information(this, "20ème arrondissement", informations);

}

void arrondissement::on_pushButton_5_clicked()
{
    QString informations = "Lieux Culturels à visiter :\n\n"
                           "1er arrondissement :\n"
                           "- Musée du Louvre\n"
                           "- Palais Royal\n\n"
                           "2ème arrondissement :\n"
                           "- Musée des Arts et Métiers\n"
                           "- Bibliothèque Nationale de France\n"

                           "20ème arrondissement :\n"
                           "- La Bellevilloise\n"
                           "- Parc de Belleville\n"
                           ;

    QMessageBox::information(this, "Lieux Culturels à visiter", informations);
}

void arrondissement::on_pushButton_6_clicked()
{
    QString informations = "Restaurants à tester et dans quels arrondissements :\n\n"
                           "1er arrondissement :\n"
                           "- Le Comptoir du Relais (Cuisine française)\n"
                           "- Le Fumoir (Cuisine internationale)\n\n"
                           "2ème arrondissement :\n"
                           "- Le Grand Véfour (Cuisine gastronomique)\n"
                           "- Chez L'Ami Jean (Cuisine basque)\n"

                           "20ème arrondissement :\n"
                           "- Le Pavillon du Lac (Cuisine française)\n"
                           "- Le Chinois de Belleville (Cuisine asiatique)\n"
                           ;

    QMessageBox::information(this, "Restaurants à tester et dans quels arrondissements", informations);
}

void arrondissement::on_pushButton_7_clicked()
{
    QString informations = "Activités à Paris et dans quel arrondissement :\n\n"
                           "1er arrondissement :\n"
                           "- Laser Game dans le quartier des Halles\n"
                           "- Bowling près du Louvre\n\n"
                           "2ème arrondissement :\n"
                           "- Escape Game dans le Marais\n"
                           "- Patinoire près de République\n"

                           "20ème arrondissement :\n"
                           "- Parc de la Villette (nombreuses activités)\n"
                           "- Piscine Georges Vallerey (Piscine olympique)\n"
                          ;

    QMessageBox::information(this, "Activités à Paris et dans quel arrondissement", informations);
}
