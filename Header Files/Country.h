//
// Created by C425 on 29/06/2023.
//

#ifndef DELIVERYPLUSPLUS_COUNTRY_H
#define DELIVERYPLUSPLUS_COUNTRY_H

#include <iostream>

class Country
{
public:
    explicit Country(std::string);

    std::string getName() const;
private:
    const
    const std::string name;
};

#endif //DELIVERYPLUSPLUS_COUNTRY_H
