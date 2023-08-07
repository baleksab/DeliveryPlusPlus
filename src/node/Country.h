//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___COUNTRY_H
#define DELIVERY___COUNTRY_H

#include "City.h"
#include "../enums/Continent.h"
#include <iostream>
#include <vector>

class Country {
public:
    Country(string, Continent::Type);

    string getName();
    Continent::Type getContinent();
    vector<City *> getCities();
    void addCity(City *);
    int getCountryID();
    static vector<Country *> getCountries();
    void displayInfo();
private:
    string name;
    Continent::Type continent;
    vector<City *> cities;
    int countryID;
    static int _countryID;
    static vector<Country *> countries;
};

#endif //DELIVERY___COUNTRY_H
