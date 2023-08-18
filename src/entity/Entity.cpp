//
// Created by C425 on 11/08/2023.
//

#include "Entity.h"

int Entity::sid = 1;

Entity::Entity(const string name):id(sid++), name(name) {

}

const int Entity::getId() const {
    return id;
}

const string Entity::getName() const {
    return name;
}