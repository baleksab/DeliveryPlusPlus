//
// Created by C425 on 05/08/2023.
//

#include "City.h"
#include "Country.h"
#include "../exception/CountryDoesNotExist.h"

int City::sid = 0;

City::City(const string name): Node(name), cityID(++sid) {

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
    cout << getName() << ", ID: " << getCityID() << endl;
}