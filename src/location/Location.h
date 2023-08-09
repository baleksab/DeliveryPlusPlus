//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY___LOCATION_H
#define DELIVERY___LOCATION_H

#include <iostream>

using namespace std;

class Location {
public:
    Location(const string name): name(name) {}

    const string getName() const {
        return name;
    }

    virtual void getInfo() const = 0;
private:
    const string name;
};

#endif //DELIVERY___LOCATION_H
