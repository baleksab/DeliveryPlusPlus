//
// Created by C425 on 05/08/2023.
//

#include "City.h"
#include "Country.h"
#include "../exception/CountryDoesNotExist.h"

int City::sid = 0;
vector<City *> City::cities;

City::City(const string name): IDescriptive(name), cityID(++sid) {
    cities.push_back(this);
}

void City::setOwnerID(const int id) {
    bool countryExists = false;

    for (auto *country : Country::getCountries())
        if (country->getCountryID() == id) {
            countryExists = true;
            break;
        }

    if (!countryExists)
        throw CountryDoesNotExist();

    ownerID = id;
}

int City::getCityID() const {
    return cityID;
}

int City::getOwnerID() const {
    return ownerID;
}

void City::displayInfo() const {
    cout << getName() << ", City ID: " << getCityID() << endl;
}

vector<City *> City::getCities() {
    return cities;
}
