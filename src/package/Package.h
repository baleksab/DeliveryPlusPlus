//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___PACKAGE_H
#define DELIVERY___PACKAGE_H

#include "../interface/Entity.h"
#include "../location/City.h"
#include <iostream>

using namespace std;

class Package : public Entity {
public:
    Package(const string, const double, const int, const int);

    const double getWeight() const;
    const int getSource() const;
    const int getDestination() const;
    void getInfo() const override;
private:
    const double weight;
    const int source;
    const int destination;
};


#endif //DELIVERY___PACKAGE_H
