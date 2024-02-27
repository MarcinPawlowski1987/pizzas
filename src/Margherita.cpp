#include "Margherita.hpp"

#include <iostream>

Margherita::Margherita(std::string name, double price, minutes bakingTime)
    : name_(name) 
    , price_(price)
    , bakingTime_(bakingTime)
    {
    }

std::string Margherita::getName() const
{
    return name_;
}

double Margherita::getPrice() const
{
    return price_;
}

minutes Margherita::getBakingTime() const
{
    return bakingTime_;
}

void Margherita::printPizza()
{
    std::cout << "- name: " << name_
              << " price: " << price_
              << " time: " << bakingTime_.count() << std::endl;
}
