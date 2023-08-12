//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___AIRPLANE_H
#define DELIVERY___AIRPLANE_H

#include "../Vehicle.h"

class Airplane : public Vehicle {
public:
    Airplane(const string name, const double maxWeight, const double costPerKM):Vehicle(name, "Airplane", maxWeight, costPerKM, Path::Type::AIR) {

    }
};

#endif //DELIVERY___AIRPLANE_H
