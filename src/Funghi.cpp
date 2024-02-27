#include "Funghi.hpp"

#include <iostream>

Funghi::Funghi(std::string name, double price, minutes bakingTime)
    : name_(name) 
    , price_(price)
    , bakingTime_(bakingTime)
{
}

std::string Funghi::getName() const
{
    return name_;
}

double Funghi::getPrice() const
{
    return price_;
}

minutes Funghi::getBakingTime() const
{
    return bakingTime_;
}

void Funghi::printPizza()
{
    std::cout << "- name: " << name_
              << " price: " << price_
              << " time: " << bakingTime_.count() << std::endl;
}