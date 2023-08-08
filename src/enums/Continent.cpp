//
// Created by c425 on 8/8/23.
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