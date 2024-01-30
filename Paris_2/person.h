#ifndef PERSON_H
#define PERSON_H

#include <QVector>
#include "entity.h"
class Place;  // Forward declaration

class Person :public Entity{
public:
    Person();
    Person(int id, const QString& name);
    void move(QVector<Place*>& listPlaces);
    Place* chooseNewLocation(QVector<Place*>& listPlaces);
    int calculateWaitingTime(Place* currentPlace) const;

    int getWaitTime(){return waitingTime;};

    void displayInfo() const override;

private:
    Place* currentLocation;
    int waitingTime;
    double budget;


};

#endif // PERSON_H
