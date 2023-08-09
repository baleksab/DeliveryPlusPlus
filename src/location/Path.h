//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___PATH_H
#define DELIVERY___PATH_H

#include <iostream>

using namespace std;

class Path {
public:
    enum Type {
        ROAD,
        RAIL,
        AIR,
        WATER
    };

    Path(const double, const Type);

    const Type getType() const;
    const double getDistance() const;
    const string getInfo() const;
    static const string typeToString(const Type);
private:
    const Type type;
    const double distance;
    static const string typeName[4];
};


#endif //DELIVERY___PATH_H
