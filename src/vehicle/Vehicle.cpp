//
// Created by c425 on 8/12/23.
//

#include "Vehicle.h"

Vehicle::Vehicle(const string name, const string typeName, const double maxWeight, const Path::Type pathType):Entity(name), typeName(typeName), maxWeight(maxWeight), pathType(pathType) {

}

const string Vehicle::getTypeName() const {
    return typeName;
}

const double Vehicle::getMaxWeight() const {
    return maxWeight;
}

double Vehicle::getCurWeight() const {
    return curWeight;
}

const Path::Type Vehicle::getPathType() const {
    return pathType;
}

void Vehicle::getInfo() const {
    cout << "Information about vehicle " << getName() << ": "
        << "\n\t - Type: " << getTypeName()
        << "\n\t - Path Type: " << Path::typeToString(getPathType())
        << "\n\t - Max weight: " << getMaxWeight() << " kg "
        << endl;
}

