//
// Created by c425 on 8/12/23.
//

#include "Package.h"

Package::Package(const string name, const double weight): Entity(name), weight(weight) {

}

const double Package::getWeight() const {
    return weight;
}

void Package::getInfo() const {

}

