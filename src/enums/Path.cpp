//
// Created by C425 on 06/08/2023.
//

#include "Path.h"

const string Path::pathTypes[3] = {
        "GROUND",
        "WATER",
        "AIR"
};

string Path::toString(Path::Type pathType) {
    return pathTypes[pathType];
}