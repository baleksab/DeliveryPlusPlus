//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___VEHICLE_H
#define DELIVERY___VEHICLE_H

#include "../interface/Entity.h"
#include "../location/Path.h"
#include "../package/Package.h"
#include <iostream>
#include <vector>

using namespace std;

class Vehicle : public Entity {
public:
    const string getTypeName() const;
    const double getMaxWeight() const;
    double getCurWeight() const;
    const Path::Type getPathType() const;
    void getInfo() const;
protected:
    Vehicle(const string, const string, const double, const double, const Path::Type);
private:
    const string typeName;
    const double maxWeight;
    const double costPerKM;
    double curWeight;
    const Path::Type pathType;
};


#endif //DELIVERY___VEHICLE_H
