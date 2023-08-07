//
// Created by C425 on 06/08/2023.
//

#ifndef DELIVERY___CONNECTION_H
#define DELIVERY___CONNECTION_H

#include "../enums/Path.h"
#include <iostream>

using namespace std;

class City;

class Connection {
public:
    double getDistance();
    City * getDestination();
    Path::Type getType();
    string getName();
    static void create(City *, City *, string , double , Path::Type type);
    void displayInfo();
private:
    Connection(City *, string, double, Path::Type);

    City *destination;
    Path::Type type;
    double distance;
    string name;
};


#endif //DELIVERY___CONNECTION_H
