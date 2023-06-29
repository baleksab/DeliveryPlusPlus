//
// Created by C425 on 29/06/2023.
//

#ifndef DELIVERYPLUSPLUS_CONTINENT_H
#define DELIVERYPLUSPLUS_CONTINENT_H

#include <iostream>
#include <string>

class Continent
{
public:
    explicit Continent(std::string);

    std::string getName() const;
private:
    const std::string name;
};

#endif //DELIVERYPLUSPLUS_CONTINENT_H
