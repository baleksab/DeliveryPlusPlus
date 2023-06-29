//
// Created by C425 on 29/06/2023.
//

#include "Header Files/Country.h"

#include <utility>

Country::Country(std::string name):name(std::move(name))
{

}

std::string Country::getName() const
{
    return name;
}

