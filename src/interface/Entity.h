//
// Created by c425 on 8/8/23.
//

#ifndef DELIVERY___ENTITY_H
#define DELIVERY___ENTITY_H

#include <iostream>

using namespace std;

class Entity {
public:
    Entity(const string name);

    const int getId() const;
    const string getName() const;
    virtual void getInfo() const = 0;
private:
    const int id;
    const string name;
    static int sid;
};



#endif //DELIVERY___ENTITY_H
