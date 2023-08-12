//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
#include "location/Path.h"
#include "location/PathSolver.h"
#include "vehicle/Vehicle.h"
#include "vehicle/types/Truck.h"
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

        /* Creating USA */

        const int USA = Country::createCountry("United States of America", Country::Continent::NORTH_AMERICA);

        const int WASHINGTON = City::createCity("Washington", USA);
        const int OKLAHOMA = City::createCity("Oklahoma", USA);
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
        City::connectTwoCities(WASHINGTON, OKLAHOMA, "Voz Washington Oklahoma", 500, Path::Type::RAIL);
        City::connectTwoCities(LOS_ANGELES, OKLAHOMA, "Voz Los Angeles Oklahoma", 400, Path::Type::RAIL);
        City::connectTwoCities(MIAMI, LOS_ANGELES, "Voz Majami Los Angeles", 1000, Path::Type::RAIL);
        City::connectTwoCities(BERLIN, WASHINGTON, "Vazdusna linija Berlin Washington", 2000, Path::Type::AIR);

        /* Listing all countries */

        for (auto &it : Country::getCountries())
            it.second->getInfo();

        /* Listing all of cities Berlin is directly connected to */

        City::getCityById(BERLIN)->getConnectionsInfo();

        /* Solving all shortest paths from Kragujevac to other cities */

        PathSolver kragujevacSolver(KRAGUJEVAC);

        /* Showing most optimal path from Kragujevac to Berlin by road, if there is one */

        kragujevacSolver.getPathTo(BERLIN, Path::Type::ROAD);

        /* Showing most optimal path from Kragujevac to Berlin all possible transportation methods, if there is one */

        kragujevacSolver.getBestPathTo(BERLIN);

        /* Showing most optimal path from Kragujevac to Washington by road, if there is one */

        kragujevacSolver.getPathTo(WASHINGTON, Path::Type::ROAD);

        /* Creating the packages */

        Package *package1 = new Package("Slusalice", 0.5, KRAGUJEVAC, MUNICH);
        Package *package2 = new Package("Frizider", 40, BELGRADE, KRAGUJEVAC);
        Package *package3 = new Package("Sporet", 60, BERLIN, WASHINGTON);
        Package *package4 = new Package("Racunar i monitor", 10, LOS_ANGELES, FRANKFURT);
        Package *package5 = new Package("Neki vrlo tezak paket", 1100, MIAMI, KRAGUJEVAC);
        Package *package6 = new Package("Brasno", 5500, SUBOTICA, OKLAHOMA);
        Package *package7 = new Package("Tegovi", 400, WASHINGTON, OKLAHOMA);
        Package *package8 = new Package("Zito", 3000, KRAGUJEVAC, MUNICH);




        delete package1;
        delete package2;
        delete package3;
        delete package4;
        delete package5;
        delete package6;
        delete package7;
        delete package8;

    } catch (UnexpectedBehavior err) {
        cout << err.what() << endl;
    }

    City::clearCities();
    Country::clearCountries();

    return 0;
}