//
// Created by c425 on 8/9/23.
//

#include "Path.h"

unordered_map<int, Path *> Path::paths;
const string Path::typeName[4] {
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

void Path::setPathDisabled(const bool disabled) {
    pathDisabled = disabled;
}

const bool Path::getPathDisabled() {
    return pathDisabled;
}

Path * Path::getPathById(const int index) {
    return paths.at(index);
}

int Path::createPath(const string name, const double distance, const Path::Type type) {
    Path *path = new Path(name, distance, type);

    paths.insert({path->getId(), path});

    return path->getId();
}

void Path::clearPaths() {
    for (auto &it : paths)
        delete it.second;
}