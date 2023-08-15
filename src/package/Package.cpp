//
// Created by c425 on 8/12/23.
//

#include "Package.h"

Package::Package(const string name, const double weight, const int source, const int destination): Entity(name), weight(weight), source(source), destination(destination) {
    if (weight <= 0)
        throw UnexpectedBehavior("Paket mora imati tezinu, ne sme biti jednaka ili ispod 0");

    if (!City::doesCityExist(source))
        throw UnexpectedBehavior("Greska pri pravljenju paketa, izvorisni grad sa id-om: " + to_string(source) + " ne postoji!");

    if (!City::doesCityExist(destination))
        throw UnexpectedBehavior("Greska pri pravljenju paketa, odredisni grad sa id-om: " + to_string(destination) + " ne postoji!");
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
    cout << "Paket: "
        << "\n\t- Naziv: " << getName()
        << "\n\t- Tezina: " << getWeight() << " kg"
        << "\n\t- Od: ";
        City::getCityById(source)->getInfo();
        cout << "\n\t- Destinacija: ";
        City::getCityById(destination)->getInfo();
        cout << endl;
}

