#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
class Ball
{
private:

    sf::RectangleShape BallObject;
    sf::Vector2f ballPosition;
public:
    sf::RectangleShape getBallObject();
    Ball(double x, double y);
    sf::FloatRect getBallFloatRect();
    void reboundSides(int windowWidth);
    void passTop(int windowWidth, int windowHeight, int& batscore);
    sf::Vector2f getBallPosition;
    void passBottom(int windowWidth, int windowHeight, int& lives);
    void intersectBat();
    void intersectAIBat();
    void reboundBatorAI();
    void update();
    double ballVelocityX = 0.5f;
    double ballVelocityY = 0.5f;
    void stop();
    void go();
};