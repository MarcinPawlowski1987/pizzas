#pragma once
#include "Pizza.hpp"
#include <chrono>
#include <string>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Margherita : public Pizza
{
public:
    Margherita() = delete;
    Margherita(std::string name, double price, minutes bakingTime);

    std::string getName() const override;
    double getPrice() const override;
    minutes getBakingTime() const override;

    void printPizza() override;

private:
    std::string name_ {};
    double price_ {0.0};
    minutes bakingTime_ {0};
};
