//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___COUNTRY_H
#define DELIVERY___COUNTRY_H

#include "City.h"
#include "../enums/Continent.h"
#include "Node.h"
#include <iostream>
#include <vector>

class Country : public Node {
public:
    Country(string, Continent::Type);

    Continent::Type getContinent() const;
    vector<City *> getCities() const;
    void addCity(City *);
    int getCountryID() const;
    static vector<Country *> getCountries();
    void displayInfo() const override;
private:
    const Continent::Type continent;
    vector<City *> cities;
    const int countryID;
    static int sid;
    static vector<Country *> countries;
};

#endif //DELIVERY___COUNTRY_H
