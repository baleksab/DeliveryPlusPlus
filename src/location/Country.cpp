//
// Created by c425 on 8/9/23.
//

#include "Country.h"

int Country::sid = 1;
unordered_map<int, Country *> Country::countries;
const string Country::continentNames[] = {
        "Europe",
        "Asia",
        "North America",
        "South America",
        "Australia",
        "Antarctica"
};

Country::Country(const string name, const Continent continent):Location(name), continent(continent), id(sid++) {

}

const int Country::getId() const {
    return id;
}

const Country::Continent Country::getContinent() const {
    return continent;
}

void Country::getInfo() const {
    cout << "--------------------------------------------" << endl;

    cout << "Information about " << getName() << ": "
         << "\n\tCountry ID: " << getId()
         << "\n\tContinent: " << continentToString(getContinent())
         << "\n\tCities:\n";

        for (auto *city : getCities()) {
            cout << "\t\t";
            city->getInfo();
        }

    cout << "--------------------------------------------\n" << endl;
}

unordered_map<int, Country *> Country::getCountries() {
    return countries;
}

const Country *Country::getCountryById(const int index) {
    if (!doesCountryExist(index))
        throw CountryDoesNotExist();

    return countries.at(index);
}

const int Country::createCountry(const string name, const Continent continent) {
    Country *country = new Country(name, continent);

    countries.insert({country->getId(), country});

    return country->getId();
}

const string Country::continentToString(const Continent cont) {
    return continentNames[cont];
}

const vector<City *> Country::getCities() const {
    vector<City *> cities;

    for (auto &it : City::getCities())
        if (it.second->getCountry() == getId())
            cities.push_back(it.second);

    return cities;
}

const bool Country::doesCountryExist(const int index) {
    if (countries.find(index) == countries.end())
        return false;

    return true;
}


