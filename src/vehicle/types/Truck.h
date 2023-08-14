//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___TRUCK_H
#define DELIVERY___TRUCK_H

#include "../Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const string name, const double maxWeight, const double rentCost, const double pricePerKM, const int locatedAt)
        :Vehicle(name, "Truck", maxWeight, rentCost, pricePerKM, Path::Type::ROAD, locatedAt) {

    }
};

#endif //DELIVERY___TRUCK_H
