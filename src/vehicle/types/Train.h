//
// Created by c425 on 8/13/23.
//

#ifndef DELIVERY___TRAIN_H
#define DELIVERY___TRAIN_H

#include "../Vehicle.h"

class Train : public Vehicle {
public:
    Train(const string name, const double maxWeight, const double rentCost, const double pricePerKM)
        :Vehicle(name, "Train", maxWeight, rentCost, pricePerKM, Path::Type::ROAD) {

    }
};

#endif //DELIVERY___TRAIN_H
