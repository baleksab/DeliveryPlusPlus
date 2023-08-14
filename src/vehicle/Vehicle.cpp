//
// Created by c425 on 8/12/23.
//

#include "Vehicle.h"

Vehicle::Vehicle(const string name, const string typeName, const double maxWeight, const double rentCost, const double pricePerKM, const Path::Type pathType, const int locatedAt):Entity(name), typeName(typeName),
    maxWeight(maxWeight), pathType(pathType), rentCost(rentCost), pricePerKM(pricePerKM), locatedAt(locatedAt) {

    if (!City::doesCityExist(locatedAt))
        throw UnexpectedBehavior("Failed creating vehicle " + name + " at city id: " + to_string(locatedAt) + ", city does not exist!");

    bool adequatePathType = false;

    for (auto &map : City::getCityById(locatedAt)->getConnections())
        for (auto *path : map.second)
            if (path->getType() == pathType) {
                adequatePathType = true;
                break;
            }

    if (!adequatePathType)
        throw UnexpectedBehavior("Failed creating vehicle " + name + " at city id: " + to_string(locatedAt) + ", city has no paths with type " + Path::typeToString(pathType));
}

const string Vehicle::getTypeName() const {
    return typeName;
}

const double Vehicle::getMaxWeight() const {
    return maxWeight;
}

const Path::Type Vehicle::getPathType() const {
    return pathType;
}

void Vehicle::getInfo() const {
    cout << "Vehicle: "
        << "\n\t- Name: " << getName()
        << "\n\t- Type: " << getTypeName()
        << "\n\t- Path Type: " << Path::typeToString(getPathType())
        << "\n\t- Current location: ";
    City::getCityById(locatedAt)->getInfo();
    cout << "\n\t- Max weight: " << getMaxWeight() << " kg "
        << "\n\t- Rent cost: " << getRentCost() << " euros "
        << "\n\t- Price per km: " << getPricePerKM() << " euros "
        << endl;
}

const double Vehicle::getRentCost() const {
    return rentCost;
}

const double Vehicle::getPricePerKM() const {
    return pricePerKM;
}

void Vehicle::deliverPackages(vector<Package *> packages, vector<Vehicle *> vehicles) {
    cout << "\n\n--------------------------------------------" << endl;
    cout << "\t\tStarting deliveries..." << endl;
    cout << "--------------------------------------------" << endl;

    cout << "- Searching for packages" << endl;

    for (auto *package : packages) {
        cout << "- Found package: " << endl;
        cout << "\t";
        package->getInfo();
        cout << "- Searching for available vehicles: " << endl;

        vector<Vehicle *> suitableVehicles;

        for (auto *vehicle : vehicles) {
            PathSolver pathFinder(vehicle->getLocatedAt(), unordered_set<Path::Type> { vehicle->getPathType() });

            if (!pathFinder.isCityReachable(package->getSource()))
                continue;

            cout << "- Found candidate: " << endl;
            cout << "\t";
            vehicle->getInfo();
            suitableVehicles.push_back(vehicle);
        }

        break;
    }
}

const int Vehicle::getLocatedAt() const {
    return locatedAt;
}

void Vehicle::setLocatedAt(const int city) {
    if (!City::doesCityExist(city))
        throw UnexpectedBehavior("Failed moving vehicle " + getName() + " to city id: " + to_string(locatedAt) + ", city does not exist!");

    locatedAt = city;
}
