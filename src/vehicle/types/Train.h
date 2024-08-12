//
// Created by c425 on 8/13/23.
//

#ifndef DELIVERY___TRAIN_H
#define DELIVERY___TRAIN_H

#include "../Vehicle.h"

class Train : public Vehicle {
public:
    Train(const string name, const double maxWeight, const double pricePerKM, const int locatedAt)
        :Vehicle(name, "Train", maxWeight, pricePerKM, Path::Type::RAIL, locatedAt) {

    }
};

#endif //DELIVERY___TRAIN_H
