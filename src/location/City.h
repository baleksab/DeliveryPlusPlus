//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include "Location.h"
#include "Country.h"
#include "Path.h"
#include "../exception/CityDoesNotExist.h"
#include "../exception/SameCityNotAllowed.h"
#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Country;

class City : public Location {
public:
    const int getId() const;
    const int getCountry() const;
    void getInfo() const;
    void getConnectionsInfo() const;
    unordered_map<int, vector<Path *>> getConnections() const;
    const bool doesConnectionExist(const int) const;
    static unordered_map<int, City *> getCities();
    static City * getCityById(const int);
    static const int createCity(const string, const int);
    static const bool doesCityExist(const int);
    static void connectTwoCities(const int, const int, Path *);
private:
    City(const string, const int);

    const int id;
    const int country;
    static int sid;
    unordered_map<int, vector<Path *>> connections;
    static unordered_map<int, City *> cities;

    void addConnection(const int, Path *);
};


#endif //DELIVERY___CITY_H
