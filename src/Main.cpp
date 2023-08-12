//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
#include "location/Path.h"
#include "location/PathSolver.h"
#include "vehicle/Vehicle.h"
#include "vehicle/types/Truck.h"
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

        Vehicle *truck1 = new Truck("Lolara", 500);
        truck1->getInfo();

        PathSolver kragujevacSolver(KRAGUJEVAC);

    } catch (UnexpectedBehavior err) {
        cout << err.what() << endl;
    }

    City::clearCities();
    Country::clearCountries();

    return 0;
}