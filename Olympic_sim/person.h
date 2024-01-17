#ifndef PERSON_H
#define PERSON_H
#include "place.h"
#include "citymodel.h"
class Person
{
public:
    Person();
    void move();
    void wait();
    Place *choose_new_location();

private:
    Place *Endroit;
    int waiting_time;
};

#endif // PERSON_H
