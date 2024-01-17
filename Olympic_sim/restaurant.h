#ifndef RESTAURANT_H
#define RESTAURANT_H
#include <string>
#include "place.h"
class Restaurant : public Place
{
public:
    Restaurant();
private:
    std::string nom;
    Coordinate location;
    std::string logoPath;

};

#endif // RESTAURANT_H
