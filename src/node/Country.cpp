//
// Created by C425 on 05/08/2023.
//

#include "Country.h"

int Country::sid = 0;
vector<Country *> Country::countries;

Country::Country(string name, Continent::Type continent):Node(name), countryID(++sid), continent(continent) {
    countries.push_back(this);
}

Continent::Type Country::getContinent() const {
    return continent;
}

vector<City *> Country::getCities() const {
    return cities;
}

void Country::addCity(City *city) {
    city->setOwnerID(getCountryID());
    cities.push_back(city);
}

int Country::getCountryID() const {
    return countryID;
}

vector<Country *> Country::getCountries() {
    return countries;
}

void Country::displayInfo() const {
    cout << "--------------------------------------------" << endl;

    cout << "Information about " << getName() << ": "
            << "\n\tID: " << getCountryID()
            << "\n\tContinent: " << Continent::toString(getContinent())
            << "\n\tCities:\n";

    for (auto *city : getCities()) {
        cout << "\t\t";
        city->displayInfo();
    }

    cout << "--------------------------------------------\n" << endl;
}