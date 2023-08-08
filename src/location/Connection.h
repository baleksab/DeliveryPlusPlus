//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY___CONNECTION_H
#define DELIVERY___CONNECTION_H

#include "City.h"
#include "Path.h"
#include <iostream>
#include <vector>

using namespace std;

class Connection {
public:
    Connection(const City *, const Path *);

    City * getDestination() const;
    void addPath(Path *);
    vector<Path *> getPaths() const;
private:
    City *destination;
    vector<Path *> paths;
};


#endif //DELIVERY___CONNECTION_H
