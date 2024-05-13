#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
	sf::RenderWindow window;
	sf::Sprite background, background2, controls;
	sf::Texture backgroundTexture, backgroundTexture2, controlsTexture;
	sf::Font Blox, MineCraft;

	public:
	MainMenu(int, int);
	bool display();
};

