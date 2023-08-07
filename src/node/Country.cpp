//
// Created by C425 on 05/08/2023.
//

#include "Country.h"

int Country::_countryID = 0;
vector<Country *> Country::countries;

Country::Country(string name, Continent::Type continent):name(name), countryID(++_countryID), continent(continent) {
    countries.push_back(this);
}

string Country::getName() {
    return name;
}

Continent::Type Country::getContinent() {
    return continent;
}

vector<City *> Country::getCities() {
    return cities;
}

void Country::addCity(City *city) {
    city->setOwnerID(getCountryID());
    cities.push_back(city);
}

int Country::getCountryID() {
    return countryID;
}

vector<Country *> Country::getCountries() {
    return countries;
}

void Country::displayInfo() {
    cout << "--------------------------------------------" << endl;

    cout << "Information about " << getName() << ": "
            << "\n\tID: " << getCountryID()
            << "\n\tContinent: " << Continent::toString(getContinent())
            << "\n\tCities: ";

    for (auto *city : getCities())
        cout << "\n\t\t" << city->getName() << ", ID: " << city->getCityID();

    cout << "\n--------------------------------------------\n" << endl;
}