#include "Paddle.h"

Paddle::Paddle(double x, double y, double speed)
{
    paddlePosition.x = x;
    paddlePosition.y = y;
	paddleSpeed = speed;
    paddleObject.setSize(sf::Vector2f(10, 150));
    paddleObject.setPosition(paddlePosition);
}

void Paddle::update()
{
    paddleObject.setPosition(paddlePosition);
}

void Paddle::movePaddleBottom(int windowHeight)
{
	if (getPaddlePosition().y < windowHeight - 150)
		paddlePosition.y += paddleSpeed;
}

void Paddle::movePaddleTop()
{
    if (getPaddlePosition().y > 0) {
		paddlePosition.y -= paddleSpeed;
    }
}

sf::FloatRect Paddle::getPaddleFloatRect()
{
    return paddleObject.getGlobalBounds();
}

sf::RectangleShape Paddle::getPaddleObject()
{
    return paddleObject;
}

sf::Vector2f Paddle::getPaddlePosition() {
    return paddlePosition;
}

