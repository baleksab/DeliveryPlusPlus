//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___COUNTRY_H
#define DELIVERY___COUNTRY_H

#include "../entity/Entity.h"
#include "City.h"
#include "../exception/UnexpectedBehaviour.h"
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class City;

class Country : public Entity {
public:
    enum Continent {
        EUROPE,
        ASIA,
        NORTH_AMERICA,
        SOUTH_AMERICA,
        AUSTRALIA,
        ANTARCTICA
    };

    const Continent getContinent() const;
    void getInfo() const override;
    const vector<City *> getCities() const;
    static unordered_map<int, Country *> getCountries();
    static const Country * getCountryById(const int);
    static const int createCountry(const string, const Continent);
    static const string continentToString(const Continent);
    static const bool doesCountryExist(const int);
    static void clearCountries();
private:
    Country(const string, const Continent);

    const Continent continent;
    static unordered_map<int, Country *> countries;
    static const string continentNames[6];
};


#endif //DELIVERY___COUNTRY_H
