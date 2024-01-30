#include "person.h"
#include "place.h"
#include <QDebug>
#include <QRandomGenerator>

Person::Person() : currentLocation(nullptr), waitingTime(0), budget(1000.0) {
}
Person::Person(int id, const QString& name):Entity(id,name),currentLocation(nullptr), waitingTime(0){
    budget = QRandomGenerator::global()->bounded(1000,5000);
}
void Person::move(QVector<Place*>& listPlaces) {
    if(getWaitTime() != 0){
        // qDebug()<<"Waiting time still not 0";
        currentLocation = currentLocation;
        //Decrease according to the steps of simulation
        waitingTime -= 30;
    }
    else{
        // Change location of person based on criteria (random for now)
        // qDebug()<<"waitTime = 0";
        // qDebug()<<"We delete from first place";
        if(currentLocation){
            currentLocation->suprPersonOfList(this);
        }
        // qDebug()<<"Get new location";
        currentLocation = chooseNewLocation(listPlaces);

        // Calculate waiting time based on the number of people before you and place capacity
        // qDebug()<<"Get waiting time based on location where arrived";
        waitingTime = calculateWaitingTime(currentLocation);

        // Perform the activity associated with the new location (budget and waiting time given by ref)
        // qDebug()<<"Perform activity";
        currentLocation->getActivity()->performActivity(budget, waitingTime);

        // Append the person to the listPerson associated with the new location
        // qDebug()<<"Append to new place";
        currentLocation->addPersonToList(this);
        // Stay for test for now
        // qDebug() << "Person moved to " << currentLocation->getName();
    }
}



Place* Person::chooseNewLocation(QVector<Place*>& listPlaces) {
    // "Random" place change for now
    int randomIndex = QRandomGenerator::global()->bounded(listPlaces.size());
    return listPlaces[randomIndex];
}


int Person::calculateWaitingTime(Place* currentPlace) const {
    // Implement your logic to calculate waiting time based on the number of people before you
    // and place capacity
    int numPeopleBeforeYou = currentPlace->getNumPeopleBeforeYou();
    int placeCapacity = currentPlace->getCapacity();

    // If there is space left, we enter directly and begin activity
    if (numPeopleBeforeYou < placeCapacity)
        return 0;
    else {
        // For simplicity, let's assume a linear relationship
        //We get activity first
        Activity* act = currentPlace->getActivity();
        //We take every people in queue (not in restaurant) and multiply by activity time
        return (placeCapacity - numPeopleBeforeYou) * act->getTimeActivity();
    }
}



void Person::displayInfo() const {
    qDebug() << "Person ID: " << getID();
    qDebug() << "Person Name: " << getName();
    qDebug() << "Current Location: " << (currentLocation ? currentLocation->getName() : "None");
    qDebug() << "Waiting Time: " << waitingTime;
    qDebug() << "Budget: " << budget;
}
