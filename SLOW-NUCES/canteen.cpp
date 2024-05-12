#include "canteen.h"
#include <iostream>

Canteen::Canteen() {
    if (!font.loadFromFile("./Assets/Fonts/arial.ttf")) {
        std::cout << "Unable to load the font" << std::endl;
    }

    menu.push_back({ "Biryanii", 200 });
    menu.push_back({ "Donut", 100 });
    menu.push_back({ "Chai", 60 });
    menu.push_back({ "Cold drink",120 });
    menu.push_back({ "karai",200 });

    orderQuantities.resize(menu.size(), 0);
}

void Canteen::displayMenu(sf::RenderWindow& window) const {
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    for (int i = 0; i < menu.size(); i++) {
        text.setString(menu[i].name + std::to_string(menu[i].price));
        text.setPosition(50, 50 + i * 30);
        window.draw(text);
    }
}

void Canteen::takeOrder(sf::Event event) {

}

void Canteen::displayBill(sf::RenderWindow& window) const {
    double total = 0.0;

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);

    text.setString("Your Bill:");
    text.setPosition(50, 50);
    window.draw(text);

    for (int i = 0; i < menu.size(); i++) {
        if (orderQuantities[i] > 0) {
            text.setString(menu[i].name + " x" + std::to_string(orderQuantities[i]) + std::to_string(menu[i].price * orderQuantities[i]));
            text.setPosition(50, 100 + i * 30);
            window.draw(text);
            total += menu[i].price * orderQuantities[i];
        }
    }

    text.setString("Total: $" + std::to_string(total));
    text.setPosition(50, 100 + menu.size() * 30);
    window.draw(text);
}
