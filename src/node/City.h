//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include "Node.h"
#include <iostream>
#include <vector>

using namespace std;

class Connection;

class City : public Node {
public:
    City(const string);

    void setOwnerID(const int);
    int getOwnerID() const;
    int getCityID() const;
    void displayInfo() const override;
private:
    int ownerID;
    const int cityID;
    static int sid;
};


#endif //DELIVERY___CITY_H
