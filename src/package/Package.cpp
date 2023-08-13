//
// Created by c425 on 8/12/23.
//

#include "Package.h"

Package::Package(const string name, const double weight, const int source, const int destination): Entity(name), weight(weight), source(source), destination(destination) {

}

const double Package::getWeight() const {
    return weight;
}

const int Package::getSource() const {
    return source;
}

const int Package::getDestination() const {
    return destination;
}

void Package::getInfo() const {
    cout << "Package: "
        << "\n\t- Name: " << getName()
        << "\n\t- Weight: " << getWeight()
        << "\n\t- From: ";
        City::getCityById(source)->getInfo();
        cout << "\n\t- Destination: ";
        City::getCityById(destination)->getInfo();
        cout << endl;
}

