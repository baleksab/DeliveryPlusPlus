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
        throw UnexpectedBehavior("City with given id: " + to_string(index) + " does not exist!");

    return cities.at(index);
}

const int City::createCity(const string name, const int countryId) {
    if (!Country::doesCountryExist(countryId))
        throw UnexpectedBehavior("Failed creating city: " + name + ", country with id: " + to_string(countryId) + " does not exist!");

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


void City::connectTwoCities(const int city1, const int city2, const string pathName, const double pathDistance, const Path::Type pathType) {
    int pathID = Path::createPath(pathName, pathDistance, pathType);

    try {
        City *sCity = getCityById(city1);
        City *dCity = getCityById(city2);

        sCity->addConnection(city2, pathID);

        if (city1 != city2)
            dCity->addConnection(city1, pathID);
    } catch (UnexpectedBehavior err) {
        throw UnexpectedBehavior("Failed connecting cities, city with id: " + to_string(city1) + " and/or city with id: " +  to_string(city2) + " do/does not exist!");
    }
}

void City::addConnection(const int destination, const int pathID) {
    if (!doesConnectionExist(destination))
        connections[destination] = vector<int>();

    connections[destination].push_back(pathID);
}

void City::getConnectionsInfo() const {
    cout << "--------------------------------------------" << endl;

    getInfo();

    cout << " is directly connected to: " << endl;

    for (auto &it : getConnections()) {
        cout << "\t* ";
        City::getCityById(it.first)->getInfo();
        cout << " by: \n";

        for (auto &id: it.second) {
            Path::getPathById(id)->getInfo();
        }
    }

    cout << "--------------------------------------------" << endl;
}

unordered_map<int, vector<int>> City::getConnections() const {
    return connections;
}

void City::clearCities() {
    for (auto &it : cities)
        delete it.second;

    cities.clear();
}
