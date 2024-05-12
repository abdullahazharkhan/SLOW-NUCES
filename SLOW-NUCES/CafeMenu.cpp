#include "CafeMenu.h"
#include <iostream>

void CafeMenu::Show(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow cafeWindow(sf::VideoMode(1250, 900), "Cafe", sf::Style::Default, settings);
	cafeWindow.setFramerateLimit(60);

	sf::Sprite cafeBackground;
	sf::Texture cafeBackgroundTexture;


	while (cafeWindow.isOpen())
	{
		// Event processing
		sf::Event cafeEvent;
		while (cafeWindow.pollEvent(cafeEvent))
		{
			// Request for closing the window
			if (cafeEvent.type == sf::Event::Closed || (cafeEvent.type == sf::Event::KeyPressed && cafeEvent.key.code == sf::Keyboard::Escape)) {
				Game_State = "Cafe";
				mapIndex = 3;
				cafeWindow.close();
				return;
			}
		}
		cafeWindow.clear();
		cafeWindow.display();
	}	

}