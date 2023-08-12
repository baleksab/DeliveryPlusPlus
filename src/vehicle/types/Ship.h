//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___SHIP_H
#define DELIVERY___SHIP_H

#include "../Vehicle.h"

class Ship : public Vehicle {
public:
    Ship(const string name, const double maxWeight):Vehicle(name, "Ship", maxWeight, Path::Type::WATER) {

    }
};

#endif //DELIVERY___SHIP_H
