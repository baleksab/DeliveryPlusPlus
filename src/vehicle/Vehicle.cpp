//
// Created by c425 on 8/12/23.
//

#include "Vehicle.h"

Vehicle::Vehicle(const string name, const string typeName, const double maxWeight, const double pricePerKM, const Path::Type pathType, const int locatedAt):Entity(name), typeName(typeName),
    maxWeight(maxWeight), pathType(pathType), pricePerKM(pricePerKM), locatedAt(locatedAt) {

    if (!City::doesCityExist(locatedAt))
        throw UnexpectedBehavior("Greska pri kreiranju vozila " + name + " u gradu sa id-om: " + to_string(locatedAt) + ", grad ne postoji!");

    bool adequatePathType = false;

    for (auto &map : City::getCityById(locatedAt)->getConnections())
        for (auto &id : map.second)
            if (Path::getPathById(id)->getType() == pathType) {
                adequatePathType = true;
                break;
            }

    if (!adequatePathType)
        throw UnexpectedBehavior("Greska pri kreiranju vozila " + name + " u gradu sa id-om: " + to_string(locatedAt) + ", grad nema ni jedan put sa tipom " + Path::typeToString(pathType));
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
    cout << "Vozilo: "
        << "\n\t- Ime: " << getName()
        << "\n\t- Tip: " << getTypeName()
        << "\n\t- Tip puta: " << Path::typeToString(getPathType())
        << "\n\t- Trenutna lokacija: ";
    City::getCityById(locatedAt)->getInfo();
    cout << "\n\t- Maksimalni kapacitet: " << getMaxWeight() << " kg "
        << "\n\t- Cena po kilometru: " << getPricePerKM() << " evra " << endl;
}

const double Vehicle::getPricePerKM() const {
    return pricePerKM;
}

void Vehicle::deliverPackages(vector<Package *> packages, vector<Vehicle *> vehicles) {
    cout << "\n\n--------------------------------------------" << endl;
    cout << "\t\tPocinjem isporuke..." << endl;
    cout << "--------------------------------------------" << endl;

    if (packages.empty())
        throw UnexpectedBehavior("Nema paketa za isporuku!");

    if (vehicles.empty())
        throw UnexpectedBehavior("Nema vozila dostupnih za isporuku!");

    cout << "- Trazim pakete..." << endl;

    for (auto *package : packages) {
        cout << "--------------------------------------------" << endl;
        cout << "- Nasao sam paket: " << endl;
        cout << "\t";
        package->getInfo();

        bool shouldSkip = false;

        while (true) {
            PathSolver pathSolver(package->getSource(), unordered_set<Path::Type> {});

            if (!pathSolver.isCityReachable(package->getDestination())) {
                cout << "- Nemoguce je isporuciti ovaj paket, "
                    << City::getCityById(package->getDestination())->getName()
                    << " nije dostizan iz grada "
                    << City::getCityById(package->getSource())->getName();
                cout << endl;

                shouldSkip = true;

                break;
            }

            cout << "- Nasao sam najoptimalniju putanju, proveravam da li imaju odgovarajuca vozila za ovu putanju..." << endl;

            unordered_map<int, int> previousCity = pathSolver.getPreviousCity();
            unordered_map<int, int> pathToCity = pathSolver.getPathToPreviousCity();

            int index = package->getDestination();
            bool restartProcess = false;

            while (previousCity[index] != UNDEFINED) {
                Path *path = Path::getPathById(pathToCity[index]);

                cout << "\t- Proveravam put '" << path->getName() << "' tipa " << Path::typeToString(path->getType()) << " izmedju grada ";
                City::getCityById(index)->getInfo();
                cout << endl;
                cout << " i grada ";
                City::getCityById(previousCity[index])->getInfo();
                cout << endl;

                bool pathIsGood = false;

                for (auto *vehicle : vehicles) {
                    if (vehicle->getPathType() == Path::getPathById(pathToCity[index])->getType()) {
                        PathSolver vehicleSolver(vehicle->getLocatedAt(), unordered_set<Path::Type> { vehicle->getPathType() });

                        if (vehicleSolver.isCityReachable(index)) {
                            cout << "\t\t- Nasao sam vozilo tipa "
                                << Path::typeToString(vehicle->getPathType()) << " koji je povezan sa ovim putem!" << endl;
                            pathIsGood = true;

                            break;
                        }
                    }
                }

                if (!pathIsGood) {
                    cout << "\t\t- Ne postoji vozilo koje je povezano sa ovim tipom puta!" << endl;
                    cout << "\t\t\t- Iskljucujem ovu stazu iz sledeceg trazenja najoptimalnijeg puta!" << endl;

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
            cout << "- Donosim zakljucak da nije moguce isporuciti ovaj paket sa ovim izborom vozila!" << endl;

            continue;
        } else
            cout << "- Optimalni put je ok, pocinjem sa isporukom..." << endl;

        PathSolver finalPath(package->getSource(), unordered_set<Path::Type> {});
        unordered_map<int, int> previousCity = finalPath.getPreviousCity();
        unordered_map<int, int> pathToPreviousCity = finalPath.getPathToPreviousCity();
        unordered_map<int, double> distances = finalPath.getDistances();

        double totalPrice = 0;

        startShipping(package, vehicles, package->getDestination(), previousCity, pathToPreviousCity, &totalPrice);

        cout << "- Paket je stigao iz grada u svoje odrediste ";
        City::getCityById(package->getDestination())->getInfo();
        cout << endl;
        cout << "- Isporuka ovog paketa je zavrsena!" << endl;
        cout << "- Ukupno je predjeno " << distances[package->getDestination()] << " km" << endl;
        cout << "- Ukupno za naplatu je " << totalPrice << " evra" << endl;
        cout << "--------------------------------------------" << endl;
    }

    cout << "--------------------------------------------" << endl;
    cout << "\t\tZavrsene su sve isporuke..." << endl;
    cout << "--------------------------------------------\n\n" << endl;

    for (auto &it : Path::getPaths())
        it.second->setPathDisabled(false);
}

const int Vehicle::getLocatedAt() const {
    return locatedAt;
}

void Vehicle::setLocatedAt(const int city) {
    if (!City::doesCityExist(city))
        throw UnexpectedBehavior("Greska pri pomeranju vozila " + getName() + " u grad sa id-om: " + to_string(locatedAt) + ", grad ne postoji!");

    bool adequatePathType = false;

    for (auto &map : City::getCityById(locatedAt)->getConnections())
        for (auto &id : map.second)
            if (Path::getPathById(id)->getType() == pathType) {
                adequatePathType = true;
                break;
            }

    if (!adequatePathType)
        throw UnexpectedBehavior("Greska pri pomeranju vozila " + getName() + " u grad sa id-om: " + to_string(locatedAt) + ", grad nema ni jedan put sa tipom " + Path::typeToString(pathType));

    locatedAt = city;
}

void Vehicle::startShipping(Package *package, vector<Vehicle *> vehicles, const int curCity, unordered_map<int, int> previousCity, unordered_map<int, int> pathToPreviousCity, double *totalPrice) {
    int prevCity = previousCity[curCity];

    if (previousCity[prevCity] != UNDEFINED)
        startShipping(package, vehicles, prevCity, previousCity, pathToPreviousCity, totalPrice);

    Vehicle *suitableVehicle = nullptr;

    for (auto *vehicle : vehicles) {
        if (Path::getPathById(pathToPreviousCity[curCity])->getType() != vehicle->getPathType())
            continue;

        PathSolver pathSolver(vehicle->getLocatedAt(), unordered_set<Path::Type> {vehicle->getPathType()});

        if (!pathSolver.isCityReachable(prevCity))
            continue;

        if (suitableVehicle == nullptr || suitableVehicle->getMaxWeight() < vehicle->getMaxWeight()) {
            suitableVehicle = vehicle;

            if (suitableVehicle->getMaxWeight() >= package->getWeight())
                break;
        }
    }

    cout << "- Paket " << package->getName() << ", tezine " << package->getWeight() << " kg, se trenutno nalazi u gradu ";
    City::getCityById(prevCity)->getInfo();
    cout << endl;
    cout << "- Trenutna cena je: " << *totalPrice << " evra" << endl;
    cout << "- Sledeca destinacija paketa je grad ";
    City::getCityById(curCity)->getInfo();
    cout << endl;
    cout << "- Razdaljina izmedju ova dva grada je " << Path::getPathById(pathToPreviousCity[curCity])->getDistance()
        << " kg i tip veze je " << Path::typeToString(suitableVehicle->getPathType()) << endl;
    cout << "- Saljem vozilo " << suitableVehicle->getName() << " iz grada ";
    City::getCityById(suitableVehicle->getLocatedAt())->getInfo();
    cout << " sa maksimalnim kapacitetom " << suitableVehicle->getMaxWeight()
        << " kg i cenom " << suitableVehicle->getPricePerKM() << " evra po km u grad ";
    City::getCityById(prevCity)->getInfo();
    cout << endl;


    PathSolver pathSolver(prevCity, unordered_set<Path::Type> {});
    unordered_map<int, int> vehiclePreviousCity = pathSolver.getPreviousCity();
    int curLocation = suitableVehicle->getLocatedAt();

    if (curLocation == prevCity) {
        cout << "\t- Vozilo se vec nalazi u gradu ";
        City::getCityById(prevCity)->getInfo();
        cout << endl;
    } else {
        while (curLocation != prevCity) {
            cout << "\t- Pomeram se iz grada ";
            City::getCityById(curLocation)->getInfo();
            cout << " u grad ";
            City::getCityById(vehiclePreviousCity[curLocation])->getInfo();
            cout << endl;
            curLocation = vehiclePreviousCity[curLocation];
        }

        cout << "\t- Vozilo je stiglo u grad ";
        City::getCityById(prevCity)->getInfo();
        cout << endl;
    }

    double weight = package->getWeight();

    if (weight <= suitableVehicle->getMaxWeight()) {
        cout << "- Utovarujem ceo paket tezine " << weight << " kg u vozilo." << endl;
        cout << "\t- Pomeram paket u grad: ";
        City::getCityById(curCity)->getInfo();
        cout << endl;
        cout << "\t- Istovarujem paket u grad ";
        City::getCityById(curCity)->getInfo();
        cout << endl;
        cout << "\t- Povecavam ukupnu cenu " << *totalPrice << " evra za "
            << Path::getPathById(pathToPreviousCity[curCity])->getDistance() << "km * " << suitableVehicle->getPricePerKM()
                << " = " << Path::getPathById(pathToPreviousCity[curCity])->getDistance() * suitableVehicle->getPricePerKM()
                << " evra." << endl;

        *totalPrice += Path::getPathById(pathToPreviousCity[curCity])->getDistance() * suitableVehicle->getPricePerKM();
    } else {
        cout << "- Paket je tezak " << weight << " kg, a maksimalni kapacitet vozila je "  << suitableVehicle->getMaxWeight()
            << " kg. Paket mora da se preveze u nekoliko tura." << endl;

        while (weight > 0) {
            double toLoad = weight <= suitableVehicle->getMaxWeight() ? weight : suitableVehicle->getMaxWeight();
            weight = weight - toLoad;

            cout << "\t- Utovarujem " << toLoad << " kg paketa u vozilo." << endl;
            cout << "\t- Pomeram turu u grad ";
            City::getCityById(curCity)->getInfo();
            cout << endl;
            cout << "\t- Istovarujem turu u grad ";
            City::getCityById(curCity)->getInfo();
            cout << endl;

            cout << "\t- Povecavam ukupnu cenu " << *totalPrice << " evra za "
                 << Path::getPathById(pathToPreviousCity[curCity])->getDistance() << "km * " << suitableVehicle->getPricePerKM()
                 << " = " << Path::getPathById(pathToPreviousCity[curCity])->getDistance() * suitableVehicle->getPricePerKM()
                 << " evra." << endl;

            *totalPrice += Path::getPathById(pathToPreviousCity[curCity])->getDistance() * suitableVehicle->getPricePerKM();

            if (weight <= 0) {
                cout << "\t- Zavrsio sam sa svim turama." << endl;
            } else {
                cout << "\t- Ostalo je jos " << weight << " kg paketa da se preveze." << endl;
                cout << "\t- Pomeram se nazad u grad ";
                City::getCityById(prevCity)->getInfo();
                cout << endl;
            }
        }
    }

    suitableVehicle->setLocatedAt(curCity);
}

