#ifndef CITYMODEL_H
#define CITYMODEL_H
#include <QVector>
#include "place.h"
#include "person.h"



class CityModel
{
public:
    CityModel();
    CityModel(const QString& filePath, int popSize);
    ~CityModel();
    //Will run a simulation based on number of steps given (1 step = 30 mins)
    void runSimulation(int Steps);
    //From a JSON containing Places, extract and create the vector places.
    void loadDataFromJson(const QString& filePath);
    //Create the popularity based on number given
    void initPopulation(int sizePopulation);

    //Getter
    QVector<Place*> getAllLocations();
    int getNumberPeople() const {return persons.count();};
    QVector<Person*> getPersons(){return persons;};
    double getTotalWait(){return totalWaitingTime;};
    double getTimeSimul(){return timeSimul;};

    //Display info related to the attribute of class instance
    void displayInfoPlaces();


private:
    QVector<Place*> places;
    QVector<Person*> persons;
    double timeSimul;
    double totalWaitingTime;

    void movePeople(); //moving function using person method
    void updateWaitingTimes(); //update waitingTime based on waiting times for people

};

#endif // CITYMODEL_H
