//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___CITY_H
#define DELIVERY___CITY_H

#include <iostream>
#include <vector>

#define UNKNOWN 0;

using namespace std;

class Connection;

class City {
public:
    City(string name);

    string getName();
    int getOwnerID();
    int getCityID();
    void setOwnerID(int);
    vector<Connection *> getConnections();
    void addConnection(Connection *connection);
    void displayConnections();
private:
    string name;
    int ownerID = UNKNOWN;
    int cityID;
    static int _cityID;
    vector<Connection *> connections;
};


#endif //DELIVERY___CITY_H
