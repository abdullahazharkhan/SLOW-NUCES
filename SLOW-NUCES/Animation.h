#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>

class Animation
{
public:
	Animation();
	Animation(int x, int y, int width, int height, bool isStill);

	void ApplyToSprite(sf::Sprite& sprite) const;

	void Update(float deltaTime);

private:
	void Advance();
private:
	static constexpr int nFrames = 4;
	static constexpr float holdTime = 0.2f;
	sf::Texture texture;
	sf::IntRect frames[nFrames];
	int iFrame = 0;
	float time = 0.0f;
};