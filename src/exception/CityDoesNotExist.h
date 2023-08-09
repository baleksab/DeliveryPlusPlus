//
// Created by c425 on 8/9/23.
//

#ifndef DELIVERY___CITYDOESNOTEXIST_H
#define DELIVERY___CITYDOESNOTEXIST_H

#include <exception>

using namespace std;

class CityDoesNotExist : public exception {
    virtual const char* what() const throw() override {
        return "ERROR: Specified city with given id does not exist!";
    }
};

#endif //DELIVERY___CITYDOESNOTEXIST_H
