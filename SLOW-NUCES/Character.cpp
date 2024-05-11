#include "Character.h"
#include <iostream>

Character::Character(const sf::Vector2f& position) : position(position)
{
	if(!texture.loadFromFile("./Assets/Sprites/guy.png")) 
		std::cout << "error loading guy.png" << std::endl;

	//sprite.setTextureRect({ 0,0,64,64 });
	Animations[int(AnimationIndex::WalkingLeft)] = Animation(64, 64 * 1, 64, 64, false);
	Animations[int(AnimationIndex::WalkingRight)] = Animation(64, 64 * 2, 64, 64, false);
	Animations[int(AnimationIndex::WalkingUp)] = Animation(64, 64 * 3, 64, 64, false);
	Animations[int(AnimationIndex::WalkingDown)] = Animation(64, 64 * 0, 64, 64, false);
	Animations[int(AnimationIndex::StandingStill)] = Animation(64, 64 * 0, 64, 64, true);
}

void Character::Draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}
void Character::spawnAt(sf::Vector2f position) {
	this->position = position;
}

void Character::SetDirection(const sf::Vector2f& direction)
{
	velocity = direction * speed;
	if (direction.x > 0.0f) {
		currentAnimation = AnimationIndex::WalkingRight;
	}
	else if (direction.x < 0.0f) {
		currentAnimation = AnimationIndex::WalkingLeft;
	}
	else if (direction.y > 0.0f) {
		currentAnimation = AnimationIndex::WalkingDown;
	}
	else if (direction.y < 0.0f) {
		currentAnimation = AnimationIndex::WalkingUp;
	}
	else {
		currentAnimation = AnimationIndex::StandingStill;
	}
}

void Character::Update(float deltaTime)
{
	position += velocity * deltaTime;
	Animations[int(currentAnimation)].Update(deltaTime);
	Animations[int(currentAnimation)].ApplyToSprite(sprite);
	sprite.setPosition(position);
}
sf::Vector2f Character::GetPosition() const {
	return position;
}