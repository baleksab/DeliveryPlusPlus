//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
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

    return 0;
}