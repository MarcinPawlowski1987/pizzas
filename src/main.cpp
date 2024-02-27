#include "Margherita.hpp"
#include "Funghi.hpp"
#include "Pizzeria.hpp"

#include <iostream>

int main()
{
    Pizzeria bravo("Bravo Pizza");
    Pizzas pizzas = { new Margherita{"Margherita", 25.0, std::chrono::seconds(3)},
                      new Funghi{"Funghi", 30.0, std::chrono::seconds(5)} };

    auto orderId = bravo.makeOrder(pizzas);
    auto price = bravo.calculatePrice(orderId);
    bravo.bakePizzas(orderId);
    bravo.completeOrder(orderId);

    std::cout << "Price: " << price << std::endl;

    return 0;
}
