//
// Created by c425 on 8/12/23.
//

#ifndef DELIVERY___UNEXPECTEDBEHAVIOUR_H
#define DELIVERY___UNEXPECTEDBEHAVIOUR_H

#include <exception>
#include <iostream>

using namespace std;

class UnexpectedBehavior : public exception {
public:
    UnexpectedBehavior(const string errorMsg):errorMsg("Error: " + errorMsg) {

    }

    virtual const char* what() const throw() override {
        return errorMsg.c_str();
    }
private:
    string errorMsg;
};

#endif //DELIVERY___UNEXPECTEDBEHAVIOUR_H
