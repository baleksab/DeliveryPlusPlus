//
// Created by c425 on 8/9/23.
//

#include "Path.h"

const string Path::typeName[5] {
    "All",
    "Road",
    "Rail",
    "Air",
    "Water"
};

Path::Path(const string name, const double distance, const Path::Type type):Entity(name), distance(distance), type(type) {

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

void Path::getInfo() const {
    cout << "\t\tPath: "
            << "\n\t\t\t- Name: " << getName()
            << "\n\t\t\t- Type: " << typeToString(getType())
            << "\n\t\t\t- Distance: " << getDistance() << " km"
            << endl;
}
