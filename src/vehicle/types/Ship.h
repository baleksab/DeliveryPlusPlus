//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___SHIP_H
#define DELIVERY___SHIP_H

#include "../Vehicle.h"

class Ship : public Vehicle {
public:
    Ship(const string name, const double maxWeight, const double rentCost, const double pricePerKM)
        :Vehicle(name, "Ship", maxWeight, rentCost, pricePerKM, Path::Type::WATER) {

    }
};

#endif //DELIVERY___SHIP_H
