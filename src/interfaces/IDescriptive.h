//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY___IDESCRIPTION
#define DELIVERY___IDESCRIPTION

#include <iostream>

using namespace std;

class IDescriptive {
public:
    IDescriptive(const string name): name(name) {

    }

    string getName() const {
        return name;
    }

    virtual void displayInfo() const = 0;
private:
    const string name;
};

#endif //DELIVERY___IDESCRIPTION
