#include "Pizzeria.hpp"
#include <numeric>
#include <algorithm>
#include <thread>
#include <iostream>

Pizzeria::Pizzeria(std::string const & name)
    : name_(name)
    , orders_()
{}

int Pizzeria::makeOrder(Pizzas& pizzas)
{
    int orderId = rand() % 1000;
    orders_.push_back(std::make_tuple(orderId, pizzas, std::chrono::system_clock::now(), Status::New));

    std::cout << "Making order: " << std::endl;
    for (const auto& position : orders_)
    {
        const std::time_t t_c = std::chrono::system_clock::to_time_t(std::get<2>(position));
        std::cout << "- id: " << std::get<0>(position) << '\n'
                  << "- time: " << std::ctime(&t_c)
                  << "- status: " << static_cast<uint16_t>(std::get<3>(position)) << std::endl;

        std::cout << "Order: " << std::endl;
        for (const auto& pizza : std::get<1>(position))
        {
            pizza->printPizza();
        }
    }

    return orderId;
}

double Pizzeria::calculatePrice(int orderId)
{
    auto order = std::find_if(orders_.begin(), orders_.end(), [orderId](const auto & order)
    {
        return std::get<0>(order) == orderId;
    });
    if (order != orders_.end())
    {
        std::get<Status>(*order) = Status::Paid;
        auto pizzas = std::get<Pizzas>(*order);
        return std::accumulate(pizzas.begin(),
                               pizzas.end(),
                               0.0,
                               [](double previousSum, Pizza *pizza)
                               {
                                   return previousSum + pizza->getPrice();
                               });
    }
    else
    {
        throw std::invalid_argument("Order with id: " + std::to_string(orderId) + "not found");
    }
}

void Pizzeria::bakePizzas(int orderId)
{
    auto order = std::find_if(orders_.begin(), orders_.end(), [orderId](const auto & order)
    {
        return std::get<0>(order) == orderId;
    });
    if (order != orders_.end())
    {
        auto pizzas = std::get<Pizzas>(*order);
        for (const auto & pizza : pizzas)
        {
            std::cout << "Baking " << pizza->getName() << std::endl;
            std::this_thread::sleep_for(pizza->getBakingTime());
        }
        std::get<Status>(*order) = Status::Baked;
    }
    else
    {
        throw std::invalid_argument("Order with id: " + std::to_string(orderId) + "not found");
    }
}

void Pizzeria::completeOrder(int orderId)
{
    auto order = std::find_if(orders_.begin(), orders_.end(), [orderId](const auto & order)
    {
        return std::get<0>(order) == orderId;
    });
    if (order != orders_.end())
    {
        std::cout << "Order " << orderId << " completed" << std::endl;
        std::get<Status>(*order) = Status::Completed;
    }
    else
    {
        throw std::invalid_argument("Order with id: " + std::to_string(orderId) + "not found");
    }
}


