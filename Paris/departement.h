// departement.h
#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H

#include <QString>

class Departement {
public:
    // Constructeur
    Departement();
    Departement(const QString& nom, const QString& description);

    // Méthodes d'accès aux attributs
    QString getNom() const;
    QString getDescription() const;
private:
    // Attributs
    QString nom;
    QString description;
};

#endif // DEPARTEMENT_H
