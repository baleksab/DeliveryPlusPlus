//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___SAMECITYNOTALLOWED_H
#define DELIVERY___SAMECITYNOTALLOWED_H

#include <exception>

using namespace std;

class SameCityNotAllowed : public exception {
    virtual const char* what() const throw() override {
        return "ERROR: City can not be connected to itself!";
    }
};


#endif //DELIVERY___SAMECITYNOTALLOWED_H
