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
        /* Pravljenje Srbije */

        const int SERBIA = Country::createCountry("Serbia", Country::Continent::EUROPE);

        const int KRAGUJEVAC = City::createCity("Kragujevac", SERBIA);
        const int BELGRADE = City::createCity("Beograd", SERBIA);
        const int NOVI_SAD = City::createCity("Novi Sad", SERBIA);
        const int SUBOTICA = City::createCity("Subotica", SERBIA);

        /* Pravljenje Nemacke */

        const int GERMANY = Country::createCountry("Germany", Country::Continent::EUROPE);

        const int BERLIN = City::createCity("Berlin", GERMANY);
        const int MUNICH = City::createCity("Munich", GERMANY);
        const int FRANKFURT = City::createCity("Frankfurt", GERMANY);
        const int HAMBURG = City::createCity("Hamburg", GERMANY);

        /* Pravljenje Amerike */

        const int USA = Country::createCountry("United States of America", Country::Continent::NORTH_AMERICA);

        const int NEW_YORK = City::createCity("New York", USA);
        const int LAS_VEGAS = City::createCity("Las Vegas", USA);
        const int LOS_ANGELES = City::createCity("Los Angeles", USA);
        const int MIAMI = City::createCity("Miami", USA);

        /* Povezivanje gradova */

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
        City::connectTwoCities(BERLIN, HAMBURG, "Autoput Berlin - Hamburg", 150, Path::Type::ROAD);
        City::connectTwoCities(HAMBURG, NEW_YORK, "Morska linija Hamburg New York", 2300, Path::Type::WATER);

        /* Izlistavanje svih drzava */

        for (auto &it : Country::getCountries())
            it.second->getInfo();

        /* Izlistavanje svih gradova sa kojim je Berlin povezan */

        City::getCityById(BERLIN)->getConnectionsInfo();

        /* Nalazenje optimalnog puta do svih gradova sa kojim je Kragujevac povezan iskljucivo obicnim putem */

        unordered_set<Path::Type> includedTypes = {
                Path::Type::ROAD
        };

        PathSolver kragujevacRoadOnly(KRAGUJEVAC, includedTypes);

            /* Provera da li je moguce stici do Berlina iskljucivo putem */

            kragujevacRoadOnly.getPathTo(BERLIN);

            /* Provera da li je moguce stici do Njujorka iskljucivo putem*/

            kragujevacRoadOnly.getPathTo(NEW_YORK);

        /* Nalazenje optimalnog puta od Kragujevca do svih gradova bilo kojim tipom puta */

        includedTypes.clear(); // if filter is empty it means all path types allowed

        PathSolver kragujevacAll(KRAGUJEVAC, includedTypes);

            /* Provera da li sada mozemo stici do Njujorka */

            kragujevacAll.getPathTo(NEW_YORK);

        cout << "\n\n\n" << endl;

        /* Pravimo vozila sa kojim cemo da radimo isporuke */

        vector<Vehicle *> vehicles;
        vehicles.push_back(new Airplane("Avion 1", 50000, 0.6, BERLIN));
        vehicles.push_back(new Ship("Brod 1", 75000, 0.32, HAMBURG));
        vehicles.push_back(new Truck("Kamion 1", 10000, 0.05, KRAGUJEVAC));
        vehicles.push_back(new Van("Kombi 1", 1000, 0.02, FRANKFURT));
        vehicles.push_back(new Train("Voz 1", 50000, 0.2, LOS_ANGELES));

        /* Pravimo pakete koje cemo isporucivati */

        vector<Package *> packages;
        packages.push_back(new Package("Brasno", 20000, BELGRADE, LOS_ANGELES));
        packages.push_back(new Package("Gradjevinski materijali 1", 15000, BERLIN, LAS_VEGAS));
        packages.push_back(new Package("Masinerija", 5500, NEW_YORK, FRANKFURT));
        packages.push_back(new Package("Oprema za racunare", 500, MUNICH, SUBOTICA));
        packages.push_back(new Package("Lego kocke", 100, BELGRADE, MIAMI));
        packages.push_back(new Package("Gradjevinski materijali 2", 7500, HAMBURG, KRAGUJEVAC));

        /* Zapocinjemo isporuke */

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
    Path::clearPaths();

    cout << "Program se uspesno izvrsio i ocistila se sva memorija!" << endl;

    return 0;
}