//
// Created by C425 on 05/08/2023.
//

#include "Country.h"

int Country::sid = 0;
vector<Country *> Country::countries;
string Country::continentNames[] = {
        "Europe",
        "Asia",
        "North America",
        "South America",
        "Australia",
        "Antarctica"
};

Country::Country(const string name, const Continent continent): IDescriptive(name), countryID(++sid), continent(continent) {
    countries.push_back(this);
}

Country::Continent Country::getContinent() const {
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
            << "\n\tCountry ID: " << getCountryID()
            << "\n\tContinent: " << continentToString(getContinent())
            << "\n\tCities:\n";

    for (auto *city : getCities()) {
        cout << "\t\t";
        city->displayInfo();
    }

    cout << "--------------------------------------------\n" << endl;
}

string Country::continentToString(Continent iContinent) {
    return continentNames[iContinent];
}