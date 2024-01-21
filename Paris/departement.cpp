// departement.cpp
#include "departement.h"

// Constructeur
Departement::Departement()
{
}

Departement::Departement(const QString& nom, const QString& description)
    : nom(nom), description(description) {

}
// Méthodes d'accès aux attributs
QString Departement::getNom() const {
    return nom;
}

QString Departement::getDescription() const {
    return description;
}


