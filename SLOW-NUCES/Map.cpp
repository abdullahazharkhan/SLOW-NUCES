#include <iostream>
#include "Map.h"

Map::Map() {

}
Map::~Map()
{
}
void Map::Load(std::string state)
{
	if (state == "Outside") {
		if (backgroundTexture.loadFromFile("./Assets/Sprites/mpBuilding.png"))
		{
			background.setTexture(backgroundTexture);
		}
		else
		{
			std::cout << "Failed to load tileset" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (state == "Inside") {
		if (backgroundTexture.loadFromFile("./Assets/Sprites/inside.png"))
		{
			background.setTexture(backgroundTexture);
		}
		else
		{
			std::cout << "Failed to load tileset" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (state == "Library") {
		if (backgroundTexture.loadFromFile("./Assets/Sprites/library.png"))
		{
			background.setTexture(backgroundTexture);
		}
		else
		{
			std::cout << "Failed to load tileset" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (state == "Cafe") {
		if (backgroundTexture.loadFromFile("./Assets/Sprites/Cafe.png"))
		{
			background.setTexture(backgroundTexture);
		}
		else
		{
			std::cout << "Failed to load tileset" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else if (state == "Pong") {
		if (backgroundTexture.loadFromFile("./Assets/Sprites/pong.png"))
		{
			background.setTexture(backgroundTexture);
		}
		else
		{
			std::cout << "Failed to load tileset" << std::endl;
			exit(EXIT_FAILURE);
		}
	}
	else {
		std::cout << "Invalid state" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void Map::updateCharacterPosition(std::string GAME_STATE, sf::Vector2f position, sf::Vector2f& direction) {
	std::vector<sf::Vector2f> possiblePositions = { {0, 0},
													{position.x + direction.x , position.y + 0},
													{position.x + 0           , position.y + direction.y },
													{position.x + direction.x , position.y + direction.y } };
	std::vector<sf::Vector2f> possibleDirections = { {0, 0},
													{direction.x, 0},
													{0, direction.y},
													{direction.x, direction.y} };
	direction = { 0.0f, 0.0f };
	if (GAME_STATE == "Outside") {
		// If the new position is not out of bounds
		for (int i = 0; i < 4; i++) {
			sf::Vector2f newPosition = possiblePositions[i], newDirection = possibleDirections[i];
			if (!(!(newPosition.x >= 0 && newPosition.x <= 1150 && newPosition.y >= 0 && newPosition.y <= 815) ||// Out of Area
				(newPosition.x >= 240 && newPosition.x <= 660 && newPosition.y >= 0 && newPosition.y <= 220) || // Walls of MP
				(newPosition.x >= 0 && newPosition.x <= 200 && newPosition.y >= 460 && newPosition.y <= 815) || // Walls of MP
				(newPosition.x >= 660 && newPosition.x <= 760 && newPosition.y >= 0 && newPosition.y <= 75) || // Walls of MP
				(newPosition.x >= 760 && newPosition.x <= 1155 && newPosition.y >= 0 && newPosition.y <= 220) || // Walls of MP
				(newPosition.x >= 0 && newPosition.x <= 200 && newPosition.y >= 0 && newPosition.y <= 440))) // Walls of MP
				direction = newDirection;
		}
	}
	else if (GAME_STATE == "Inside") {
		for (int i = 0; i < 4; i++) {
			sf::Vector2f newPosition = possiblePositions[i], newDirection = possibleDirections[i];
			if (!(!(newPosition.x >= 0 && newPosition.x <= 1170 && newPosition.y >= 0 && newPosition.y <= 800)))// Out of Area
				direction = newDirection;
		}
	}
	else if (GAME_STATE == "Library") {
		for (int i = 0; i < 4; i++) {
			sf::Vector2f newPosition = possiblePositions[i], newDirection = possibleDirections[i];
			if (!(!(newPosition.x >= 45 && newPosition.x <= 1190 && newPosition.y >= 0 && newPosition.y <= 830)))// Out of Area
				direction = newDirection;
		}
	}
	else if (GAME_STATE == "Cafe") {
		for (int i = 0; i < 4; i++) {
			sf::Vector2f newPosition = possiblePositions[i], newDirection = possibleDirections[i];
			if (!(!(newPosition.x >= 0 && newPosition.x <= 1180 && newPosition.y >= 0 && newPosition.y <= 830) ||
				(newPosition.x >= 0 && newPosition.x <= 260 && newPosition.y >= 210 && newPosition.y <= 830)))// Out of Area
				direction = newDirection;
		}
	}
	else {
		std::cout << "Invalid state" << std::endl;
		exit(EXIT_FAILURE);
	}
}
sf::Vector2f Map::changeState(std::string& GAME_STATE, sf::Vector2f direction, int& index) {
	if (GAME_STATE == "Outside") {
		if (direction.x >= 660 && direction.x <= 760 && direction.y >= 75 && direction.y <= 220){ // Walls of MP
			GAME_STATE = "Inside", index = 1;
			return sf::Vector2f(680, 770);
		}
	}
	else if (GAME_STATE == "Inside") {
		if (direction.x >= 660 && direction.x <= 760 && direction.y >= 750 && direction.y <= 800) {
			GAME_STATE = "Outside", index = 0;
			return sf::Vector2f(700, 180);
		}
		else if (direction.x >= 830 && direction.x <= 1100 && direction.y >= 0 && direction.y <= 340) {
			GAME_STATE = "Library", index = 2;
			return sf::Vector2f(810, 750);
		}
		else if (direction.x >= 0 && direction.x <= 220 && direction.y >= 0 && direction.y <= 570) {
			GAME_STATE = "Pong", index = 4;
			return sf::Vector2f(320, 150);
		}
		else if (direction.x >= 410 && direction.x <= 680 && direction.y >= 0 && direction.y <= 220) {
			GAME_STATE = "Cafe", index = 3;
			return sf::Vector2f(130, 130);
		}
	}
	else if (GAME_STATE == "Library") {
		if (direction.x >= 700 && direction.x <= 900 && direction.y >= 750 && direction.y <= 830) {
			GAME_STATE = "Inside", index = 1;
			return sf::Vector2f(920, 345);
		}
		else if (direction.x >= 1000 && direction.x <= 1190 && direction.y >= 0 && direction.y <= 190) {
			GAME_STATE = "Cafe", index = 3;
			return sf::Vector2f(130, 130);
		}
		else if (direction.x >= 590 && direction.x <= 920 && direction.y >= 360 && direction.y <= 680) {
			GAME_STATE = "LibraryManagement", index = 5;
			return sf::Vector2f(760, 680);
		}
	}
	else if (GAME_STATE == "Cafe") {
		if (direction.x >= 0 && direction.x <= 130 && direction.y >= 0 && direction.y <= 130) {
			GAME_STATE = "Inside", index = 1;
			return sf::Vector2f(550, 200);
		}
		else if (direction.x >= 430 && direction.x <= 1140 && direction.y >= 0 && direction.y <= 130) {
			GAME_STATE = "CafeMenu", index = 6;
			return sf::Vector2f(660, 130);
		}

	}
	else if (GAME_STATE == "Pong") {
		GAME_STATE = "Inside", index = 1;
		return sf::Vector2f(110, 330);
	}
	std::cout << "Invalid state" << std::endl;
	return sf::Vector2f(-1, -1);
}
void Map::Draw(sf::RenderWindow& window) const
{
	window.draw(background);
}