//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___VAN_H
#define DELIVERY___VAN_H

#include "../Vehicle.h"

class Van : public Vehicle {
public:
    Van(const string name, const double maxWeight):Vehicle(name, "Van", maxWeight, Path::Type::ROAD) {

    }
};

#endif //DELIVERY___VAN_H
