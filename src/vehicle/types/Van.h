//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___VAN_H
#define DELIVERY___VAN_H

#include "../Vehicle.h"

class Van : public Vehicle {
public:
    Van(const string name, const double maxWeight, const double rentCost, const double pricePerKM, const int locatedAt)
        :Vehicle(name, "Van", maxWeight, rentCost, pricePerKM, Path::Type::ROAD, locatedAt) {

    }
};

#endif //DELIVERY___VAN_H
