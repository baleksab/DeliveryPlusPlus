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
        for (auto &id : map.second)
            if (Path::getPathById(id)->getType() == pathType) {
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

    if (packages.empty())
        throw UnexpectedBehavior("There are no packages to deliver!");

    if (vehicles.empty())
        throw UnexpectedBehavior("There are no vehicles to do deliveries!");

    cout << "- Searching for packages" << endl;

    for (auto *package : packages) {
        cout << "--------------------------------------------" << endl;
        cout << "- Found package: " << endl;
        cout << "\t";
        package->getInfo();

        bool shouldSkip = false;

        while (true) {
            PathSolver pathSolver(package->getSource(), unordered_set<Path::Type> {});

            if (!pathSolver.isCityReachable(package->getDestination())) {
                cout << "- Impossible to deliver this package, "
                    << City::getCityById(package->getDestination())->getName()
                    << " is not reachable from "
                    << City::getCityById(package->getSource())->getName();

                shouldSkip = true;

                break;
            }

            cout << "- Found the most optimal path to destination, checking if there adequate vehicles for the found path types..." << endl;

            unordered_map<int, int> previousCity = pathSolver.getPreviousCity();
            unordered_map<int, int> pathToCity = pathSolver.getPathToPreviousCity();

            int index = package->getDestination();
            bool restartProcess = false;

            while (previousCity[index] != UNDEFINED) {
                Path *path = Path::getPathById(pathToCity[index]);

                cout << "\t- Checking for path '" << path->getName() << "' of type " << Path::typeToString(path->getType())
                    << " between " << City::getCityById(index)->getName() << " and " << City::getCityById(previousCity[index])->getName() << endl;

                bool pathIsGood = false;

                for (auto *vehicle : vehicles) {
                    if (vehicle->getPathType() == Path::getPathById(pathToCity[index])->getType()) {
                        PathSolver vehicleSolver(vehicle->getLocatedAt(), unordered_set<Path::Type> { vehicle->getPathType() });

                        if (vehicleSolver.isCityReachable(index)) {
                            cout << "\t\t- Found vehicle of path type "
                                << Path::typeToString(vehicle->getPathType()) << " that is connected to this path!" << endl;
                            pathIsGood = true;

                            break;
                        }
                    }
                }

                if (!pathIsGood) {
                    cout << "\t\t- No vehicle found with the path type that is connected to this path!" << endl;
                    cout << "\t\t\t- Disabling the path and starting to calculate most optimal path again!" << endl;

                    Path::getPathById(pathToCity[index])->setPathDisabled(true);

                    restartProcess = true;

                    break;
                }

                index = previousCity[index];
            }

            if (restartProcess)
                continue;

            break;
        }

        if (shouldSkip) {
            cout << "- Skipping this package because it's impossible to deliver it with current vehicle selection!" << endl;

            continue;
        } else
            cout << "- Optimal path is okay, starting delivery..." << endl;

        PathSolver finalPath(package->getDestination(), unordered_set<Path::Type> {});
        unordered_map<int, int> previousCity = finalPath.getPreviousCity();
        unordered_map<int, int> pathToPreviousCity = finalPath.getPathToPreviousCity();

        cout << "- Finished delivering this package!" << endl;
        cout << "--------------------------------------------" << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "\t\tFinished deliveries..." << endl;
    cout << "--------------------------------------------\n\n" << endl;

    for (auto &it : Path::getPaths())
        it.second->setPathDisabled(false);
}

const int Vehicle::getLocatedAt() const {
    return locatedAt;
}

void Vehicle::setLocatedAt(const int city) {
    if (!City::doesCityExist(city))
        throw UnexpectedBehavior("Failed moving vehicle " + getName() + " to city id: " + to_string(locatedAt) + ", city does not exist!");

    locatedAt = city;
}

const bool Vehicle::operator<(const Vehicle &other) {
    return getMaxWeight() < other.getMaxWeight();
}
