//
// Created by c425 on 8/9/23.
//

#include "Country.h"

unordered_map<int, Country *> Country::countries;
const string Country::continentNames[] = {
        "Evropa",
        "Azija",
        "Severna Amerika",
        "Juzna Amerika",
        "Australija",
        "Antarktika"
};

Country::Country(const string name, const Continent continent): Entity(name), continent(continent) {

}

const Country::Continent Country::getContinent() const {
    return continent;
}

void Country::getInfo() const {
    cout << "--------------------------------------------" << endl;

    cout << "Informacije o drzavi " << getName() << ": "
         << "\n\tID: " << getId()
         << "\n\tKontinent: " << continentToString(getContinent())
         << "\n\tGradovi:\n";

        for (auto *city : getCities()) {
            cout << "\t\t";
            cout << city->getName();
            cout << "\n";
        }

    cout << "--------------------------------------------\n" << endl;
}

unordered_map<int, Country *> Country::getCountries() {
    return countries;
}

const Country *Country::getCountryById(const int index) {
    if (!doesCountryExist(index))
        throw UnexpectedBehavior("Drzava sa datim id-om: " + to_string(index)  + " ne postoji!");

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

void Country::clearCountries() {
    for (auto &it : countries)
        delete it.second;
}


