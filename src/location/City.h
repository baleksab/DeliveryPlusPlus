//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include "../interface/Entity.h"
#include "Country.h"
#include "Path.h"
#include "../exception/UnexpectedBehaviour.h"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Country;

class City : public Entity {
public:
    const int getCountry() const;
    void getInfo() const;
    void getConnectionsInfo() const;
    unordered_map<int, vector<int>> getConnections() const;

    const bool doesConnectionExist(const int) const;
    static unordered_map<int, City *> getCities();
    static City * getCityById(const int);
    static const int createCity(const string, const int);
    static const bool doesCityExist(const int);
    static void connectTwoCities(const int, const int, const string, const double, const Path::Type);
    static void clearCities();
private:
    City(const string, const int);
    ~City() = default;

    const int country;
    unordered_map<int, vector<int>> connections;
    static unordered_map<int, City *> cities;

    void addConnection(const int, const int);
};


#endif //DELIVERY___CITY_H
