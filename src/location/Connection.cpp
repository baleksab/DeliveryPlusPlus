//
// Created by c425 on 8/8/23.
//

#include "Connection.h"

Connection::Connection(const City *destination, const Path *path) {

}

City * Connection::getDestination() const {
    return destination;
}

void Connection::addPath(Path *path) {
    paths.push_back(path);
}

vector<Path *> Connection::getPaths() const {
    return paths;
};