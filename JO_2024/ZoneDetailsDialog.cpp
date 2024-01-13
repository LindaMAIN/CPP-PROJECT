#include "ZoneDetailsDialog.h"

ZoneDetailsDialog::ZoneDetailsDialog(QWidget *parent)
    : QDialog(parent),
    ui(new ZoneDetailsDialog)
{
    ui->setupUi(this);
    // Chargement des données
    loadZoneDetails();

    // Connexion de signaux et slots si nécessaire
    connect(ui->someButton, &QPushButton::clicked, this, &ZoneDetailsDialog::onSomeButtonClick);
}

ZoneDetailsDialog::~ZoneDetailsDialog()
{
    // Libération des ressources si nécessaire
    releaseResources();

    // Déconnexion de signaux si nécessaire
    disconnect(ui->someButton, &QPushButton::clicked, this, &ZoneDetailsDialog::onSomeButtonClick);
}
