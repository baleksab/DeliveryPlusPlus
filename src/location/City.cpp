//
// Created by c425 on 8/9/23.
//

#include "City.h"

unordered_map<int, City *> City::cities;

City::City(const string name, const int country): Entity(name), country(country) {

}

const int City::getCountry() const {
    return country;
}

void City::getInfo() const {
    cout << getName() << " ( " << Country::getCountryById(country)->getName() << " )";
}

unordered_map<int, City *> City::getCities() {
    return cities;
}

City *City::getCityById(const int index) {
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

const bool City::doesConnectionExist(const int index) const {
    if (connections.find(index) == connections.end())
        return false;

    return true;
}


void City::connectTwoCities(const int city1, const int city2, Path *path) {
    if (city1 == city2)
        throw SameCityNotAllowed();

    City *sCity = getCityById(city1);
    City *dCity = getCityById(city2);

    sCity->addConnection(city2, path);
    dCity->addConnection(city1, path);
}

void City::addConnection(const int destination, Path *path) {
    if (!doesConnectionExist(destination))
        connections[destination] = vector<Path *>();

    connections[destination].push_back(path);
}

void City::getConnectionsInfo() const {
    cout << "--------------------------------------------" << endl;

    getInfo();

    cout << " is directly connected to: " << endl;

    for (auto &it : getConnections()) {
        cout << "\t* ";
        City::getCityById(it.first)->getInfo();
        cout << " by: \n";

        for (auto *path : it.second) {
            path->getInfo();
        }
    }

    cout << "--------------------------------------------" << endl;
}

unordered_map<int, vector<Path *>> City::getConnections() const {
    return connections;
}
