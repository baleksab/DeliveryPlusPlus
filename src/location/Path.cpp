//
// Created by c425 on 8/9/23.
//

#include "Path.h"

const string Path::typeName[4] {
    "Road",
    "Rail",
    "Air",
    "Water"
};

Path::Path(const double distance, const Path::Type type):distance(distance), type(type) {

}

const Path::Type Path::getType() const {
    return type;
}

const double Path::getDistance() const {
    return distance;
}

const string Path::typeToString(const Path::Type type) {
    return typeName[type];
}

const string Path::getInfo() const {
    return "Path via " + typeToString(getType()) + ", " + to_string(getDistance()) + " km long.\n";
}
