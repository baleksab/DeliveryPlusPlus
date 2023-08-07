//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___CONTINENT_H
#define DELIVERY___CONTINENT_H

#include <iostream>

using namespace std;

class Continent final {
public:
    enum Type {
        ASIA,
        EUROPE,
        AUSTRALIA,
        NORTH_AMERICA,
        SOUTH_AMERICA,
        ANTARCTICA
    };

    static string toString(Continent::Type continent);
private:
    static const string continentNames[6];
};



#endif //DELIVERY___CONTINENT_H
