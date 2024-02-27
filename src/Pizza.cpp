#include "Pizza.hpp"

#include <iostream>

// Pizza::Pizza(std::string const & name, double price, minutes bakingTime)
//     : name_(name)
//     , price_(price)
//     , bakingTime_(bakingTime)
// {}

std::string Pizza::getName() const
{
    return name_;
}

double Pizza::getPrice() const
{
    return price_;
}

minutes Pizza::getBakingTime() const
{
    return bakingTime_;
}

void Pizza::printPizza()
{
    std::cout << "- name: " << name_
              << " price: " << price_
              << " time: " << bakingTime_.count() << std::endl;
}

