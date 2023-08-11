//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___PATH_H
#define DELIVERY___PATH_H

#include <iostream>
#include "../interface/Entity.h"

using namespace std;

class Path : public Entity {
public:
    enum Type {
        ALL,
        ROAD,
        RAIL,
        AIR,
        WATER
    };

    Path(const string, const double, const Type);

    const Type getType() const;
    const double getDistance() const;
    void getInfo() const override;
    static const string typeToString(const Type);
private:
    const string name;
    const Type type;
    const double distance;
    static const string typeName[5];
};


#endif //DELIVERY___PATH_H
