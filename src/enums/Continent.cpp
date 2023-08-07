//
// Created by C425 on 05/08/2023.
//

#include "Continent.h"

const string Continent::continentNames[6] = {
        "Asia",
        "Europe",
        "Australia",
        "North America",
        "South America",
        "Antarctica"
};

string Continent::toString(Continent::Type continent) {
    return continentNames[continent];
}