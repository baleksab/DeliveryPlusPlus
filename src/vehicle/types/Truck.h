//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___TRUCK_H
#define DELIVERY___TRUCK_H

#include "../Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(const string name, const double maxWeight):Vehicle(name, "Truck", maxWeight, Path::Type::ROAD) {

    }
};

#endif //DELIVERY___TRUCK_H
