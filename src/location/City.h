//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include "Location.h"
#include "Country.h"
#include "../exception/CityDoesNotExist.h">
#include <unordered_map>
#include <iostream>

using namespace std;

class Country;

class City : public Location {
public:
    const int getId() const;
    const int getCountry() const;
    void getInfo() const;
    static unordered_map<int, City *> getCities();
    static const City * getCityById(const int);
    static const int createCity(const string, const int);
    static const bool doesCityExist(const int);
private:
    City(const string, const int);

    const int id;
    const int country;
    static int sid;
    static unordered_map<int, City *> cities;
};


#endif //DELIVERY___CITY_H
