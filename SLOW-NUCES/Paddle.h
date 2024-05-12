#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

class Paddle
{
private:
    sf::Vector2f paddlePosition;
    double paddleSpeed; // need to be set in child class
    sf::RectangleShape paddleObject;

public:
	Paddle(double x, double y, double speed);
    sf::Vector2f getPaddlePosition();
    sf::RectangleShape getPaddleObject();
    sf::FloatRect getPaddleFloatRect();
    void movePaddleTop();
    void movePaddleBottom(int WINDOWHEIGHT);
    void update();
};

