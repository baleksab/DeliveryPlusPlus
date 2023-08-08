//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include "../interfaces/IDescriptive.h"
#include <iostream>
#include <vector>

using namespace std;

class Connection;

class City : public IDescriptive {
public:
    City(const string);

    void setOwnerID(const int);
    int getOwnerID() const;
    int getCityID() const;
    void displayInfo() const override;
    static vector<City *> getCities();
private:
    int ownerID;
    const int cityID;
    static int sid;
    static vector<City *> cities;
};


#endif //DELIVERY___CITY_H
