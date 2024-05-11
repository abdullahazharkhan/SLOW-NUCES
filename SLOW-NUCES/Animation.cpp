#include "Animation.h"

Animation::Animation() = default;

Animation::Animation(int x, int y, int width, int height, bool isStill = false)
{
	texture.loadFromFile("./Assets/Sprites/guy.png");
	if (isStill) {
		for (int i = 0; i < nFrames; i++) {
			frames[i] = { 0, y, width, height };
		}
	}
	else {
		for (int i = 0; i < nFrames; i++) {
			frames[i] = { i * width, y, width, height };
		}
	}
}

void Animation::ApplyToSprite(sf::Sprite& sprite) const
{
	sprite.setTexture(texture);
	sprite.setTextureRect(frames[iFrame]);
}

void Animation::Update(float deltaTime)
{
	time += deltaTime;
	while (time >= holdTime) {
		time -= holdTime;
		Advance();
		//iFrame = (iFrame + 1) % nFrames;
	}
}

void Animation::Advance()
{
	if (++iFrame >= nFrames) {
		iFrame = 0;
	}
}