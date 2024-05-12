#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Canteen {
private:
    struct MenuItem {
        std::string name;
        double price;
    };

    std::vector<MenuItem> menu;
    std::vector<int> orderQuantities;
    sf::Font font;

public:
    Canteen();

    void displayMenu(sf::RenderWindow& window) const;
    void takeOrder(sf::Event event);
    void displayBill(sf::RenderWindow& window) const;
};
