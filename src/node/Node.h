//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY___NODE_H
#define DELIVERY___NODE_H

#include <iostream>

using namespace std;

class Node {
public:
    Node(const string name):name(name) {

    }

    string getName() const {
        return name;
    }

    virtual void displayInfo() const = 0;
private:
    const string name;
};

#endif //DELIVERY___NODE_H
