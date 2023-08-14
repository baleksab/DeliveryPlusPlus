//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___PATH_H
#define DELIVERY___PATH_H

#include <iostream>
#include "../interface/Entity.h"
#include <unordered_map>

using namespace std;

class Path : public Entity {
public:
    enum Type {
        ROAD,
        RAIL,
        AIR,
        WATER
    };

    const Type getType() const;
    const double getDistance() const;
    void getInfo() const override;
    void setPathDisabled(const bool);
    const bool getPathDisabled();
    static const string typeToString(const Type);
    static int createPath(const string, const double, const Type);
    static Path * getPathById(const int);
    static unordered_map<int, Path *> getPaths();
    static void clearPaths();
private:
    Path(const string, const double, const Type);

    bool pathDisabled = false;
    const string name;
    const Type type;
    const double distance;
    static const string typeName[4];
    static unordered_map<int, Path *> paths;
};


#endif //DELIVERY___PATH_H
