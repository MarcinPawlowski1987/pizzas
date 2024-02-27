#pragma once
#include <list>
#include <set>
#include <chrono>
#include <string>

using minutes = std::chrono::seconds;   // To simulate time flow ;)

class Pizza
{
public:
    // Pizza(std::string const & name, double price, minutes bakingTime);
    // Pizza() = delete;
    virtual ~Pizza() = default;
    virtual std::string getName() const;
    virtual double getPrice() const;
    virtual minutes getBakingTime() const;

    virtual void printPizza();

private:
    std::string name_ {"unknown"};
    double price_ {0.0};
    minutes bakingTime_ {0};
};

using Pizzas = std::set<Pizza*>;
