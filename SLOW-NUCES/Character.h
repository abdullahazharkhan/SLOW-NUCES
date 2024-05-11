#pragma once
#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include "Animation.h"

class Character
{
private:
	enum class AnimationIndex {
		WalkingRight,
		WalkingLeft,
		WalkingUp,
		WalkingDown,
		StandingStill,
		Count
	};
public:
	Character(const sf::Vector2f& position);

	void Draw(sf::RenderWindow& window) const;
	void spawnAt(sf::Vector2f position);
	void SetDirection(const sf::Vector2f& direction);
	void Update(float deltaTime = 1.0);

	sf::Vector2f GetPosition() const;


private:
	static constexpr float speed = 100.0f;
	sf::Vector2f position;
	sf::Vector2f velocity = { 0.0f, 0.0f };
	sf::Texture texture;
	sf::Sprite sprite;
	Animation Animations[int(AnimationIndex::Count)];
	AnimationIndex currentAnimation = AnimationIndex::WalkingDown;
};