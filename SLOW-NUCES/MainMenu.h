#pragma once
#include <SFML/Graphics.hpp>

class MainMenu
{
	sf::RenderWindow window;
	sf::Sprite background, background2, controls, backgroundNew, controlsNew;
	sf::Texture backgroundTexture, backgroundTexture2, controlsTexture, backgroundTextureNew, controlsTextureNew;
	sf::Font Blox, MineCraft;

	public:
	MainMenu(int, int);
	bool display();
	bool display2();
};

