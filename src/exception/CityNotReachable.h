//
// Created by C425 on 11/08/2023.
//

#ifndef DELIVERY___CITYNOTREACHABLE_H
#define DELIVERY___CITYNOTREACHABLE_H

#include "../location/Path.h"
#include "../location/City.h"
#include <exception>

using namespace std;

class CityNotReachable : public exception {
public:
    CityNotReachable(const int source, const int destination, const Path::Type type):type(type), source(source), destination(destination) {
        error_msg = "ERROR: " + City::getCityById(destination)->getName() + " is not reachable from "
                    + City::getCityById(source)->getName() + " by " + Path::typeToString(type) + "!";
    }

    virtual const char* what() const throw() override {
        return error_msg.c_str();
    }
private:
    const int source;
    const int destination;
    const Path::Type type;
    string error_msg;
};

#endif //DELIVERY___CITYNOTREACHABLE_H
