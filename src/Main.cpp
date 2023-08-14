//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
#include "location/Path.h"
#include "location/PathSolver.h"
#include "vehicle/Vehicle.h"
#include "vehicle/types/Truck.h"
#include "vehicle/types/Van.h"
#include "vehicle/types/Ship.h"
#include "vehicle/types/Airplane.h"
#include "vehicle/types/Train.h"
#include "package/Package.h"
#include <iostream>

using namespace std;

int main() {
    try {
        /* Creating Serbia */

        const int SERBIA = Country::createCountry("Serbia", Country::Continent::EUROPE);

        const int KRAGUJEVAC = City::createCity("Kragujevac", SERBIA);
        const int BELGRADE = City::createCity("Beograd", SERBIA);
        const int NOVI_SAD = City::createCity("Novi Sad", SERBIA);
        const int SUBOTICA = City::createCity("Subotica", SERBIA);

        /* Creating Germany */

        const int GERMANY = Country::createCountry("Germany", Country::Continent::EUROPE);

        const int BERLIN = City::createCity("Berlin", GERMANY);
        const int MUNICH = City::createCity("Munich", GERMANY);
        const int FRANKFURT = City::createCity("Frankfurt", GERMANY);
        const int HAMBURG = City::createCity("Hamburg", GERMANY);

        /* Creating USA */

        const int USA = Country::createCountry("United States of America", Country::Continent::NORTH_AMERICA);

        const int NEW_YORK = City::createCity("New York", USA);
        const int LAS_VEGAS = City::createCity("Las Vegas", USA);
        const int LOS_ANGELES = City::createCity("Los Angeles", USA);
        const int MIAMI = City::createCity("Miami", USA);

        /* Connecting cities */

        City::connectTwoCities(KRAGUJEVAC, BELGRADE, "Put preko Topole", 150, Path::Type::ROAD);
        City::connectTwoCities(KRAGUJEVAC, BELGRADE, "Autoput SRB - Sekcija 1", 130, Path::Type::ROAD);
        City::connectTwoCities(BELGRADE, NOVI_SAD, "Autoput SRB - Sekcija 2", 80, Path::Type::ROAD);
        City::connectTwoCities(NOVI_SAD, SUBOTICA, "Autoput SRB - Sekcija 3", 60, Path::Type::ROAD);
        City::connectTwoCities(SUBOTICA, MUNICH, "Autput - Subotica Minhen", 300, Path::Type::ROAD);
        City::connectTwoCities(BELGRADE, BERLIN, "Vazduna linija - Beograd Berlin", 500, Path::Type::AIR);
        City::connectTwoCities(BERLIN, MUNICH, "Autoput - Berlin Minhen", 150, Path::Type::ROAD);
        City::connectTwoCities(FRANKFURT, BERLIN, "Vazdusna Linija - Frankfurt Berlin", 160, Path::Type::AIR);
        City::connectTwoCities(FRANKFURT, BERLIN, "Put Frankfurt Berlin", 160, Path::Type::ROAD);
        City::connectTwoCities(NEW_YORK, LAS_VEGAS, "Voz Washington Oklahoma", 500, Path::Type::RAIL);
        City::connectTwoCities(LOS_ANGELES, LAS_VEGAS, "Voz Los Angeles Oklahoma", 400, Path::Type::RAIL);
        City::connectTwoCities(MIAMI, LOS_ANGELES, "Voz Majami Los Angeles", 1000, Path::Type::RAIL);
        City::connectTwoCities(BERLIN, NEW_YORK, "Vazdusna linija Berlin Washington", 2000, Path::Type::AIR);
        City::connectTwoCities(HAMBURG, NEW_YORK, "Morska linija Hamburg New York", 2300, Path::Type::WATER);

        /* Listing all countries */

        for (auto &it : Country::getCountries())
            it.second->getInfo();

        /* Listing all of cities Berlin is directly connected to */

        City::getCityById(BERLIN)->getConnectionsInfo();

        /* Calculating most optimal path from Kragujevac to other cities by road */

        unordered_set<Path::Type> excludedTypes = {
                Path::Type::AIR,
                Path::Type::WATER,
                Path::Type::RAIL
        };

        PathSolver kragujevacRoadOnly(KRAGUJEVAC, excludedTypes);

            /* Checking if it's possible to go to Berlin by road only */

            kragujevacRoadOnly.getPathTo(BERLIN);

            /* Checking if it's possible to go to New York by road only */

            kragujevacRoadOnly.getPathTo(NEW_YORK);

        cout << "\n\n\n" << endl;

        /* Creating the vehicle fleet */

        vector<Vehicle *> vehicles;
        vehicles.push_back(new Airplane("Airplane 1", 5000, 3500, 10, BERLIN));
        vehicles.push_back(new Ship("Ship 1", 7500, 2000, 4.5, HAMBURG));
        vehicles.push_back(new Truck("Truck 1", 3000, 300, 0.5, KRAGUJEVAC));
        vehicles.push_back(new Van("Van 1", 250, 100, 0.2, FRANKFURT));
        vehicles.push_back(new Train("Train 1", 3000, 2500, 6, LOS_ANGELES));

        cout << "Available vehicle fleet: " << endl;

        for (auto *vehicle : vehicles)
            vehicle->getInfo();

        vector<Package *> packages;
        packages.push_back(new Package("Wheat", 20000, KRAGUJEVAC, LOS_ANGELES));
        packages.push_back(new Package("Building materials 1", 15000, BERLIN, LAS_VEGAS));
        packages.push_back(new Package("Machinery", 5500, NEW_YORK, FRANKFURT));
        packages.push_back(new Package("PC equipment", 500, MUNICH, SUBOTICA));
        packages.push_back(new Package("Legos", 100, BELGRADE, MIAMI));
        packages.push_back(new Package("Building materials 2", 7500, HAMBURG, KRAGUJEVAC));

        Vehicle::deliverPackages(packages, vehicles);

        for (auto *package : packages)
            delete package;

        for (auto *vehicle : vehicles)
            delete vehicle;
    } catch (UnexpectedBehavior err) {
        cout << err.what() << endl;
    }

    City::clearCities();
    Country::clearCountries();

    return 0;
}