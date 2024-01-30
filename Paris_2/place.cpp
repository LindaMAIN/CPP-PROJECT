#include "place.h"
#include <QDebug>
#include "person.h"

Place::Place() : Entity(), capacity(0), popularity(0), activity(nullptr) {
}
Place::Place(Activity* activity) : Entity(), capacity(10), popularity(0), activity(activity) {
}
Place::Place(int id, const QString& name): Entity(id,name),capacity(0), popularity(0), activity(nullptr) {
}
Place::~Place() {
    delete activity; // or use std::unique_ptr
}



void Place::addPersonToList(Person* person){
    listPerson.append(person);
}

void Place::suprPersonOfList(Person* person){
    listPerson.removeOne(person);
}

int Place::getNumPeopleBeforeYou(){
    return listPerson.count();
}

double Place::getTotalWaitingHere(){
    double waitingTime = 0;
    for(Person* person : listPerson){
        waitingTime+= person->getWaitTime();
    }
    return waitingTime;
}

void Place::displayInfo() const {
    qDebug() << "Place ID: " << getID();
    qDebug() << "Place Name: " << getName();
    qDebug() << "Capacity: " << capacity;
    qDebug() << "Popularity: " << popularity;
    qDebug() << "Number of People: " << listPerson.size();
    activity->displayInfo();
}

void Place::setCapacity(int newCapacity){
    capacity = newCapacity;
}
void Place::setPopularity(int newPopularity){
    popularity = newPopularity;
}
void Place::setActivity(Activity* newActivity){
    activity=newActivity;
}
