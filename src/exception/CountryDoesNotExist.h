//
// Created by C425 on 05/08/2023.
//

#ifndef DELIVERY___COUNTRYDOESNOTEXIST_H
#define DELIVERY___COUNTRYDOESNOTEXIST_H

#include <exception>

using namespace std;

class CountryDoesNotExist : public exception {
public:
    virtual const char* what() const throw() override {
        return "ERROR: Specified country with given id does not exist!";
    }
};

#endif //DELIVERY___COUNTRYDOESNOTEXIST_H
