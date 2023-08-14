//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___VEHICLE_H
#define DELIVERY___VEHICLE_H

#include "../interface/Entity.h"
#include "../location/Path.h"
#include "../package/Package.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Vehicle : public Entity {
public:
    const string getTypeName() const;
    const double getMaxWeight() const;
    const double getRentCost() const;
    const double getPricePerKM() const;
    const int getLocatedAt() const;
    const Path::Type getPathType() const;
    void getInfo() const;
    static void deliverPackages(vector<Package *>, vector<Vehicle *>);
protected:
    Vehicle(const string, const string, const double, const double, const double, const Path::Type, const int);
    void setLocatedAt(const int);
private:
    int locatedAt;
    const string typeName;
    const double rentCost;
    const double pricePerKM;
    const double maxWeight;
    const Path::Type pathType;
    static unordered_map<int, Vehicle *> vehicles;
};


#endif //DELIVERY___VEHICLE_H