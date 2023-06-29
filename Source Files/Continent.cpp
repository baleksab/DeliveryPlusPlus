//
// Created by C425 on 29/06/2023.
//

#include "Header Files/Continent.h"
#include <utility>

Continent::Continent(std::string name):name(std::move(name))
{

}

std::string Continent::getName() const
{
    return name;
}