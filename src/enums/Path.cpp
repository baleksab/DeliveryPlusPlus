//
// Created by c425 on 8/8/23.
//

#include "Path.h"

const string Path::pathTypes[4] = {
        "Road",
        "Water",
        "Air",
        "Rail"
};

string Path::toString(Path::Type pathType) {
    return pathTypes[pathType];
}