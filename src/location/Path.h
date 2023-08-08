//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY_PATH_H
#define DELIVERY_PATH_H

#include <iostream>
#include "../interfaces/IDescriptive.h"

using namespace std;

class Path : public IDescriptive {
public:
    enum Type {
        ROAD,
        RAIL,
        AIR,
        WATER
    };

    Path(const string, const Type, const double);

    const Type getType() const;
    const double getDistance() const;
    void displayInfo() const override;
    static string typeToString(const Type iType);
private:
    const Type type;
    const double distance;
    static string typeName[4];
};


#endif //DELIVERY_PATH_H
