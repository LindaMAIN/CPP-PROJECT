#ifndef PLACE_H
#define PLACE_H

#include "coordinate.h"
#include "entity.h"
#include "activity.h"

class Person;  // Forward declaration

class Place : public Entity {
private:
    int capacity;
    int popularity;
    Activity* activity;
    QVector<Person*> listPerson;

public:
    Place(); // Default constructor
    Place(Activity* activity);
    Place(int id, const QString& name);
    ~Place();

    int getNumPeopleBeforeYou();
    int getPeopleHere(){return listPerson.size();};
    int getCapacity() const {return capacity;};
    double getTotalWaitingHere();

    //initialization
    void addPersonToList(Person* person);
    void suprPersonOfList(Person* person);

    //define after virtual function
    void displayInfo() const override;

    //Setter
    void setCapacity(int newCapacity);
    void setPopularity(int newPopularity);
    void setActivity(Activity* newActivity);
    Activity* getActivity() const { return activity;};
};

#endif // PLACE_H
