#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(int width, int height)
{
	window.create(sf::VideoMode(width, height), "SLOW NUCES", sf::Style::Default);
	if (backgroundTexture.loadFromFile("./Assets/Sprites/mainScreen.png"))
	{
		background.setTexture(backgroundTexture);
	}
	else
	{
		std::cout << "Failed to load tileset" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (backgroundTexture2.loadFromFile("./Assets/Sprites/MainScreenMenu.png"))
	{
		background2.setTexture(backgroundTexture2);
	}
	else
	{
		std::cout << "Failed to load tileset" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!Blox.loadFromFile("./Assets/Fonts/Blox.ttf"))
	{
		std::cout << "Failed to load font" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!MineCraft.loadFromFile("./Assets/Fonts/MineCraft.ttf"))
	{
		std::cout << "Failed to load font" << std::endl;
		exit(EXIT_FAILURE);
	}
}
bool MainMenu::display() {
	bool choice = false;

	sf::Text Title;
	Title.setFont(MineCraft);
	Title.setString("SLOW NUCES");
	Title.setCharacterSize(140);
	Title.setFillColor(sf::Color::White);
	Title.setPosition(260, 40);

	sf::Text Play;
	Play.setFont(Blox);
	Play.setString("Press Space to Play");
	Play.setCharacterSize(80);
	Play.setFillColor(sf::Color::White);
	Play.setPosition(260, 400);

	sf::Text Controls;
	Controls.setFont(Blox);
	Controls.setString("Press C for controls");
	Controls.setCharacterSize(60);
	Controls.setFillColor(sf::Color::White);
	Controls.setPosition(300, 550);

	int type = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				if(type == 1)
					window.close();
				else if(type == 2)
					type = 1;
			}
			else if (event.type == sf::Event::KeyPressed && type == 2) {
				type = 1;
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
				choice = true;
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
				type = 2;
			}
		}
		window.clear();
		if (type == 1) {
			window.draw(background);
			window.draw(Title);
			window.draw(Play);
			window.draw(Controls);
		}
		else {
			window.draw(background2);
		}
		window.display();
	}
	return choice;
}