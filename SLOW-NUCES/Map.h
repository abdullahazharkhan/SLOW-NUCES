#pragma once
#include <SFML/Graphics.hpp>

class Map
{
public:
	Map();
	~Map();
	void Initialize();
	void Load(std::string);
	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window) const;
	static void updateCharacterPosition(std::string GAME_STATE, sf::Vector2f position, sf::Vector2f& direction);
	static sf::Vector2f changeState(std::string& GAME_STATE, sf::Vector2f direction, int& index);
	void transition();

private:
	sf::Texture tileSheetTexture;
	const static int spritesSize = 10;
	sf::Sprite sprites[spritesSize];
	sf::Sprite background;
	sf::Texture backgroundTexture;
	int tileWidth;
	int tileHeight;
	int totalTilesOnX;
	int totalTilesOnY;
};