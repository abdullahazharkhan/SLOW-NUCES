#include "Ball.h"

sf::RectangleShape Ball::getBallObject() {
    return BallObject;
}

Ball::Ball(double x, double y) {
    ballPosition.x = x;
    ballPosition.y = y;
    BallObject.setSize(sf::Vector2f(10, 10));

    BallObject.setPosition(ballPosition);

    BallObject.setFillColor(sf::Color::White);

}

void Ball::update() {


    ballPosition.x += ballVelocityX;
    ballPosition.y += ballVelocityY;


    BallObject.setPosition(ballPosition);
}


void Ball::reboundSides(int windowWidth) {
    if (ballPosition.x > windowWidth)
        ballVelocityX *= -1;

    else if (ballPosition.x < 0)
        ballVelocityX *= -1;


}


void Ball::passTop(int windowWidth, int windowHeight, int& batscore) {

    if (ballPosition.y < 0)
    {
        batscore++;
        ballPosition.x = windowWidth / 2;
        ballPosition.y = windowHeight / 2;

        if (rand() % 2 == 1) ballVelocityY *= -1;
        if (rand() % 2 == 2) ballVelocityX *= -1;

    }
}
void Ball::passBottom(int windowWidth, int windowHeight, int& lives) {
    if (ballPosition.y > windowHeight + 10)
    {
        ballPosition.x = windowWidth / 2;
        ballPosition.y = windowHeight / 2;
        lives--;
        if (rand() % 2 == 1) ballVelocityY *= -1;
        if (rand() % 2 == 2) ballVelocityX *= -1;
    }


}
sf::FloatRect Ball::getBallFloatRect() { return BallObject.getGlobalBounds(); }


void Ball::reboundBatorAI() {
    ballPosition.y -= (ballVelocityY * 30);
    ballVelocityY *= -1;

}

void Ball::stop() {
    ballVelocityY = 0;
    ballVelocityX = 0;
}

void Ball::go() {
    ballVelocityY = 0.5f;
    ballVelocityX = 0.5f;
}