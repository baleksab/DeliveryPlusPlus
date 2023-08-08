//
// Created by C425 on 06/08/2023.
//

#ifndef DELIVERY___PATH_H
#define DELIVERY___PATH_H

#include <iostream>

using namespace std;

class Path final {
public:
    enum Type {
        ROAD,
        WATER,
        AIR,
        RAIL
    };

    static string toString(Path::Type);
private:
    static const string pathTypes[4];
};



#endif //DELIVERY___PATH_H
