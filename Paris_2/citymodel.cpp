#include "citymodel.h"
#include <QDebug>
#include <QJsonDocument>
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>

CityModel::CityModel(): timeSimul(0) {}

CityModel::CityModel(const QString& filePath, int popSize):timeSimul(0),totalWaitingTime(0){
    qDebug() << "load from json file:"<< filePath;
    loadDataFromJson(filePath);
    initPopulation(popSize);
}
CityModel::~CityModel() {
    for (Place* place : places) {
        delete place->getActivity();  // Assuming you have a getter for the activity
        delete place;
    }

}


QVector<Place*> CityModel::getAllLocations(){
    return places;
}


void CityModel::runSimulation(int Steps){
    for (int i = 0; i < Steps; ++i)
    {
        qDebug() << "Simulation Step: " << timeSimul;

        //We move people to each places randomly
        movePeople();
        //We get the evolution of waitingTime for the people in simul
        updateWaitingTimes();
        //One step = 30 mins
        timeSimul+= 30;
    }
}


void CityModel::movePeople(){
    for(Person* person : getPersons()){
        QVector<Place*> availablePlaces = getAllLocations();
        person->move(availablePlaces);
    }
}


void CityModel::updateWaitingTimes(){
    totalWaitingTime=0;
    for (Person* person : getPersons()){
        totalWaitingTime+= person->getWaitTime();
        //qDebug()<<person->getWaitTime();
        //person->displayInfo();
    }
}



void CityModel::loadDataFromJson(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc(QJsonDocument::fromJson(data));

    QJsonArray placesArray = doc.array();
    for (int i = 0; i < placesArray.size(); ++i) {
        QJsonObject placeObj = placesArray[i].toObject();

        int id = placeObj["id"].toInt();
        QString name = placeObj["name"].toString();
        int capacity = placeObj["capacity"].toInt();
        int popularity = placeObj["popularity"].toInt();
        QString activityType = placeObj["activity"].toString();

        Activity* activity;
        if (activityType == "dining") {
            activity = new DiningActivity();
        } else if (activityType == "sightseeing") {
            activity = new SightseeingActivity();
        } else {
            qWarning() << "Unknown activity type: " << activityType;
            continue;  // Skip this place
        }

        Place* place = new Place(id, name);
        place->setCapacity(capacity);
        place->setPopularity(popularity);
        place->setActivity(activity);

        places.append(place);
    }
}


void CityModel::initPopulation(int sizePopulation){
    for(int i=0;i<sizePopulation; ++i){
        Person* person = new Person(i,"Person"+QString::number(i+1));
        persons.append(person);
    }
}


void CityModel::displayInfoPlaces(){
    for(Place* place : getAllLocations()){
        place->displayInfo();
    }
}
