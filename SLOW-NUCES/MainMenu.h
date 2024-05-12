#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
	sf::RenderWindow window;
	sf::Sprite background, background2;
	sf::Texture backgroundTexture, backgroundTexture2;
	sf::Font Blox, MineCraft;

	public:
	MainMenu(int, int);
	bool display();
};

