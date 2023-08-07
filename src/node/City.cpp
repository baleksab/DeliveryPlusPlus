//
// Created by C425 on 05/08/2023.
//

#include "City.h"
#include "Country.h"
#include "Connection.h"
#include "../exception/CountryDoesNotExist.h"

int City::_cityID = 0;

City::City(string name):name(name), cityID(++_cityID) {

}

string City::getName() {
    return name;
}

int City::getCityID() {
    return cityID;
}

int City::getOwnerID() {
    return ownerID;
}

void City::setOwnerID(int countryID) {
    bool countryExists = false;

    for (auto *country : Country::getCountries())
        if (country->getCountryID() == countryID) {
            countryExists = true;
            break;
        }

    if (!countryExists)
        throw CountryDoesNotExist();

    ownerID = countryID;
}

vector<Connection *> City::getConnections() {
    return connections;
}

void City::addConnection(Connection *connection) {
    connections.push_back(connection);
}

void City::displayConnections() {
    cout << "--------------------------------------------" << endl;

    cout << name << " is connected to: " << endl;

    for (auto *conn : connections)
        conn->displayInfo();

    cout << "\n--------------------------------------------" << endl;
}
