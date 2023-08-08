//
// Created by C425 on 05/08/2023.
//

#include "location/City.h"
#include "location/Country.h"
#include <iostream>

using namespace std;

int main() {
    City *kragujevac = new City("Kragujevac");
    City *beograd = new City("Beograd");
    City *noviSad = new City("Novi Sad");
    City *subotica = new City("Subotica");

    Country *srbija = new Country("Srbija", Country::Continent::EUROPE);
    srbija->addCity(kragujevac);
    srbija->addCity(beograd);
    srbija->addCity(noviSad);
    srbija->addCity(subotica);

    City *berlin = new City("Berlin");
    City *frankfurt = new City("Frankfurt");
    City *munich = new City("Munich");

    Country *germany = new Country("Germany", Country::Continent::EUROPE);
    germany->addCity(berlin);
    germany->addCity(frankfurt);
    germany->addCity(munich);

    srbija->displayInfo();
    germany->displayInfo();

    for (auto *city : City::getCities())
        city->displayInfo();


    return 0;
}