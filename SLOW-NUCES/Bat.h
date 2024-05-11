#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

class Bat
{
private:
    sf::Vector2f batPosition;
    double batSpeed = 0.85f;
    sf::RectangleShape BatObject;

public:
    Bat(double x, double y);
    sf::Vector2f getBatPosition();
    sf::RectangleShape getBatObject();
    sf::FloatRect getBatFloatRect();
    void moveBatLeft();
    void moveBatRight(int windowWidth);
    void update();
};