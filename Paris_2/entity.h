#ifndef ENTITY_H
#define ENTITY_H

#include <QString>
#include <QVector>

class Entity {
private:
    int id;
    QString name;

public:
    Entity(); // Default constructor
    Entity(int id, const QString& name);
    virtual ~Entity();

    int getID() const;
    QString getName() const;

    virtual void displayInfo() const = 0;


};

#endif //ENTITY_H
