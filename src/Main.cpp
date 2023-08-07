//
// Created by C425 on 05/08/2023.
//

#include "node/City.h"
#include "node/Country.h"
#include "node/Connection.h"
#include <iostream>

using namespace std;

int main() {
    City *kragujevac = new City("Kragujevac");
    City *beograd = new City("Beograd");
    City *noviSad = new City("Novi Sad");
    City *subotica = new City("Subotica");

    Country *srbija = new Country("Srbija", Continent::Type::EUROPE);
    srbija->addCity(kragujevac);
    srbija->addCity(beograd);
    srbija->addCity(noviSad);
    srbija->addCity(subotica);

    Connection::create(kragujevac, beograd, "Autoput", 150, Path::Type::GROUND);
    Connection::create(kragujevac, beograd, "Magistralni put", 180, Path::Type::GROUND);

    City *berlin = new City("Berlin");
    City *frankfurt = new City("Frankfurt");
    City *munich = new City("Munich");

    Country *germany = new Country("Germany", Continent::Type::EUROPE);
    germany->addCity(berlin);
    germany->addCity(frankfurt);
    germany->addCity(munich);

    srbija->displayInfo();
    germany->displayInfo();

    kragujevac->displayConnections();
    beograd->displayConnections();

    return 0;
}