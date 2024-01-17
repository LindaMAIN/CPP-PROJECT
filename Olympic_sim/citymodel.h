#ifndef CITYMODEL_H
#define CITYMODEL_H
#include <vector>
#include "place.h"
class CityModel
{
public:
    CityModel();
    std::vector<Place*> getAllLocations();

private:
    std::vector<Place*> places;
};

#endif // CITYMODEL_H
