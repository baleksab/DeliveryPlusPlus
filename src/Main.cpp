//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
#include "location/Path.h"
#include <iostream>

using namespace std;

int main() {
    /* Creating Serbia */

    const int COUNTRY_SERBIA = Country::createCountry("Serbia", Country::Continent::EUROPE);

    const int CITY_KRAGUJEVAC = City::createCity("Kragujevac", COUNTRY_SERBIA);
    const int CITY_BELGRADE = City::createCity("Beograd", COUNTRY_SERBIA);
    const int CITY_NOVI_SAD = City::createCity("Novi Sad", COUNTRY_SERBIA);
    const int CITY_SUBOTICA = City::createCity("Subotica", COUNTRY_SERBIA);

    /* Creating Germany */

    const int COUNTRY_GERMANY = Country::createCountry("Germany", Country::Continent::EUROPE);

    const int CITY_BERLIN = City::createCity("Berlin", COUNTRY_GERMANY);
    const int CITY_MUNICH = City::createCity("Munich", COUNTRY_GERMANY);
    const int CITY_FRANKFURT = City::createCity("Frankfurt", COUNTRY_GERMANY);

    /* Creating USA */

    const int COUNTRY_USA = Country::createCountry("United States of America", Country::Continent::NORTH_AMERICA);

    const int CITY_WASHINGTON = City::createCity("Washington", COUNTRY_USA);
    const int CITY_OKLAHOMA = City::createCity("Oklahoma", COUNTRY_USA);
    const int CITY_LOS_ANGELES = City::createCity("Los Angeles", COUNTRY_USA);
    const int CITY_MIAMI = City::createCity("Miami", COUNTRY_USA);

    Country::getCountryById(COUNTRY_SERBIA)->getInfo();
    Country::getCountryById(COUNTRY_GERMANY)->getInfo();
    Country::getCountryById(COUNTRY_USA)->getInfo();

    City::connectTwoCities(CITY_KRAGUJEVAC, CITY_BELGRADE, new Path(150, Path::Type::ROAD));
    City::connectTwoCities(CITY_BELGRADE, CITY_NOVI_SAD, new Path(80, Path::Type::ROAD));
    City::connectTwoCities(CITY_NOVI_SAD, CITY_SUBOTICA, new Path(60, Path::Type::ROAD));
    City::connectTwoCities(CITY_SUBOTICA, CITY_MUNICH, new Path(300, Path::Type::ROAD));
    City::connectTwoCities(CITY_BELGRADE, CITY_BERLIN, new Path(500, Path::Type::AIR));
    City::connectTwoCities(CITY_BERLIN, CITY_MUNICH, new Path(150, Path::Type::ROAD));
    City::connectTwoCities(CITY_FRANKFURT, CITY_BERLIN, new Path(160, Path::Type::AIR));
    City::connectTwoCities(CITY_FRANKFURT, CITY_BERLIN, new Path(160, Path::Type::ROAD));
    City::connectTwoCities(CITY_WASHINGTON, CITY_OKLAHOMA, new Path(500, Path::Type::RAIL));
    City::connectTwoCities(CITY_LOS_ANGELES, CITY_OKLAHOMA, new Path(400, Path::Type::RAIL));
    City::connectTwoCities(CITY_MIAMI, CITY_LOS_ANGELES, new Path(1000, Path::Type::RAIL));
    City::connectTwoCities(CITY_BERLIN, CITY_WASHINGTON, new Path(2000, Path::Type::AIR));

    City::getCityById(CITY_BERLIN)->getConnectionsInfo();

    return 0;
}