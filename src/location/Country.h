//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___COUNTRY_H
#define DELIVERY___COUNTRY_H

#include "City.h"
#include "../interfaces/IDescriptive.h"
#include <iostream>
#include <vector>

class Country : public IDescriptive {
public:
    enum Continent {
        EUROPE,
        ASIA,
        NORTH_AMERICA,
        SOUTH_AMERICA,
        AUSTRALIA,
        ANTARCTICA
    };

    Country(const string, const Continent);

    Continent getContinent() const;
    vector<City *> getCities() const;
    void addCity(City *);
    int getCountryID() const;
    static vector<Country *> getCountries();
    void displayInfo() const override;
    static string continentToString(Continent);
private:
    const Continent continent;
    vector<City *> cities;
    const int countryID;
    static int sid;
    static vector<Country *> countries;
    static string continentNames[6];
};

#endif //DELIVERY___COUNTRY_H
