//
// Created by c425 on 8/8/23.
//

#include "Path.h"

string Path::typeName[4] = {
        "Road",
        "Rail",
        "Air",
        "Water"
};

Path::Path(const std::string name, const Path::Type type, const double distance):IDescriptive(name), type(type), distance(distance) {

}

const Path::Type Path::getType() const {
    return type;
}

const double Path::getDistance() const {
    return distance;
}

void Path::displayInfo() const {
    cout << getName() << ", Type: " << typeToString(getType()) << ", Distance: " << getDistance() << endl;
}

string Path::typeToString(const Path::Type iType) {
    return typeName[iType];
}



