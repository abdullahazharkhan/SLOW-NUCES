#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
class Ball
{
private:

    sf::CircleShape BallObject;
    sf::Vector2f ballPosition;
public:
    sf::CircleShape getBallObject();
    Ball(double x, double y);
    sf::FloatRect getBallFloatRect();
    void reboundSides(int windowWidth);
    void passRight(int windowWidth, int windowHeight, int& playerScore);
    sf::Vector2f getBallPosition;
    void passLeft(int windowWidth, int windowHeight, int& aiScore);
    void intersectBat();
    void intersectAIBat();
    void reboundBatorAI();
    void update();
    double ballVelocityX = 5.0f;
    double ballVelocityY = 5.0f;
    void stop();
    void go();
};