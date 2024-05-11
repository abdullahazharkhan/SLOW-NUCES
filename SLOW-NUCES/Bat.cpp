#include "Bat.h"

Bat::Bat(double x, double y)
{
    batPosition.x = x;
    batPosition.y = y;
    BatObject.setSize(sf::Vector2f(150, 10));
    BatObject.setPosition(batPosition);
}

sf::Vector2f Bat::getBatPosition() {
    return batPosition;
}

sf::FloatRect Bat::getBatFloatRect() {
    return BatObject.getGlobalBounds();
}
void Bat::moveBatLeft() {
    if (getBatPosition().x > 0)
        batPosition.x -= batSpeed;
}
sf::RectangleShape Bat::getBatObject() {
    return BatObject;
}
void Bat::moveBatRight(int windowWidth) {
    if (getBatPosition().x < windowWidth - 150)
        batPosition.x += batSpeed;
}
void Bat::update() {
    BatObject.setPosition(batPosition);
}