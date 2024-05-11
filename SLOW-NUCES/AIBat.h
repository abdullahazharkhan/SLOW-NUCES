#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
class AIBat
{
private:
    sf::Vector2f aiBatPosition;
    double aiBatSpeed = 24;
    sf::RectangleShape aiBatObject;

public:
    AIBat(double x, double y);
    sf::Vector2f getAIBatPosition();
    sf::RectangleShape getAIBatObject();
    sf::FloatRect getAIBatFloatRect();
    void moveAIBatLeft();
    void moveAIBatRight();
    void update();
    void Rebound();
    void AIBatSpeedReverse();

};