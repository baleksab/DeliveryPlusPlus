//
// Created by c425 on 8/9/23.
//

#include "City.h"

int City::sid = 1;
unordered_map<int, City *> City::cities;

City::City(const string name, const int country): Location(name), id(sid++), country(country) {

}

const int City::getId() const {
    return id;
}

const int City::getCountry() const {
    return country;
}

void City::getInfo() const {
    cout << "City " << getName() << " ( " << getId() << " ) belongs to country "
    << Country::getCountryById(getCountry())->getName() << " ( " << getCountry() << " )" << endl;
}

unordered_map<int, City *> City::getCities() {
    return cities;
}

const City *City::getCityById(const int index) {
    if (!doesCityExist(index))
        throw CityDoesNotExist();

    return cities.at(index);
}

const int City::createCity(const string name, const int countryId) {
    if (!Country::doesCountryExist(countryId))
        throw CountryDoesNotExist();

    City *city = new City(name, countryId);

    cities.insert({city->getId(), city});

    return city->getId();
}

const bool City::doesCityExist(const int index) {
    if (cities.find(index) == cities.end())
        return false;

    return true;
}
