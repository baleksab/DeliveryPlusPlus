//
// Created by C425 on 06/08/2023.
//

#include "Connection.h"
#include "City.h"

Connection::Connection(City *destination, string name, double distance, Path::Type type):destination(destination), type(type), distance(distance), name(name) {

}

double Connection::getDistance() {
    return distance;
}

Path::Type Connection::getType() {
    return type;
}

string Connection::getName() {
    return name;
}

City * Connection::getDestination() {
    return destination;
}

void Connection::create(City *city1, City *city2, string name, double distance, Path::Type type) {
    city1->addConnection(new Connection(city2, name, distance, type));
    city2->addConnection(new Connection(city1, name, distance, type));
}

void Connection::displayInfo() {
    cout << "\n\t-----------------------------------------"
        << "\n\tCity name: " << destination->getName()
        << "\n\tConnection name: " << name
        << "\n\tDistance: " << distance
        << "\n\tType: " << Path::toString(type)
        << "\n\t-----------------------------------------"
        << endl;
}
