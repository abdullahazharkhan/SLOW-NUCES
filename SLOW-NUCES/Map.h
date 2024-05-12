#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map();
	~Map();
	void Load(std::string);
	void Draw(sf::RenderWindow& window) const;
	static void updateCharacterPosition(std::string GAME_STATE, sf::Vector2f position, sf::Vector2f& direction);
	static sf::Vector2f changeState(std::string& GAME_STATE, sf::Vector2f direction, int& index);

private:
	sf::Sprite background;
	sf::Texture backgroundTexture;
};