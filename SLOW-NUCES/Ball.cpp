#include "Ball.h"

sf::CircleShape Ball::getBallObject() {
    return BallObject;
}

Ball::Ball(double x, double y) {
    ballPosition.x = x;
    ballPosition.y = y;
	BallObject.setRadius(12);

    BallObject.setPosition(ballPosition);
	BallObject.setOrigin(BallObject.getRadius()/2, BallObject.getRadius() / 2);
    BallObject.setFillColor(sf::Color::Yellow);

}

void Ball::update() {


    ballPosition.x += ballVelocityX;
    ballPosition.y += ballVelocityY;


    BallObject.setPosition(ballPosition);
}


void Ball::reboundSides(int windowHeight) {
    if (ballPosition.y > windowHeight - 12)
        ballVelocityY *= -1;

    else if (ballPosition.y < 0)
        ballVelocityY *= -1;


}


void Ball::passRight(int windowWidth, int windowHeight, int &playerScore) {

    if (ballPosition.x > windowWidth)
    {
        playerScore++;
        ballPosition.x = (float)windowWidth / 2;
        ballPosition.y = (float)windowHeight / 2;

        if (rand() % 2 == 1) ballVelocityY *= -1;
        if (rand() % 2 == 2) ballVelocityX *= -1;

    }
}
void Ball::passLeft(int windowWidth, int windowHeight, int& aiScore) {
    if (ballPosition.x < 0)
    {
        aiScore++;
        ballPosition.x = (float)windowWidth / 2;
        ballPosition.y = (float)windowHeight / 2;
        if (rand() % 2 == 1) ballVelocityY *= -1;
        if (rand() % 2 == 2) ballVelocityX *= -1;
    }


}
sf::FloatRect Ball::getBallFloatRect() { return BallObject.getGlobalBounds(); }


void Ball::reboundBatorAI() {
    //ballPosition.y -= (ballVelocityY * 30);
    //ballVelocityY *= -1;

    ballPosition.x -= (ballVelocityX);
    ballVelocityX *= -1;
}

void Ball::stop() {
    ballVelocityY = 0;
    ballVelocityX = 0;
}

void Ball::go() {
    ballVelocityY = 5.0f;
    ballVelocityX = 5.0f;
}