#include <iostream>
#include "MainMenu.h"

MainMenu::MainMenu(int width, int height)
{
	window.create(sf::VideoMode(width, height), "SLOW NUCES", sf::Style::Default);
	if (backgroundTexture.loadFromFile("./Assets/Sprites/mpBuilding3.png"))
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
	if (controlsTexture.loadFromFile("./Assets/Sprites/Controls.png"))
	{
		controls.setTexture(controlsTexture);
	}
	else
	{
		std::cout << "Failed to load tileset" << std::endl;
		exit(EXIT_FAILURE);
	}

	if (!MineCraft.loadFromFile("./Assets/Fonts/Quartz.ttf"))
	{
		std::cout << "Failed to load font" << std::endl;
		exit(EXIT_FAILURE);
	}
	if (!Blox.loadFromFile("./Assets/Fonts/Stones.ttf"))
	{
		std::cout << "Failed to load font" << std::endl;
		exit(EXIT_FAILURE);
	}
}
bool MainMenu::display() {
	bool choice = false;
	sf::RectangleShape fade(sf::Vector2f(window.getSize().x, window.getSize().y));
	fade.setFillColor(sf::Color(0, 0, 0, 100));

	sf::FloatRect imageBounds;
	imageBounds = controls.getLocalBounds();
	controls.setOrigin(-imageBounds.left + imageBounds.width / 2.0f, -imageBounds.top + imageBounds.height / 2.0f);
	controls.setPosition(window.getSize().x / 2.0, window.getSize().y / 2.0);

	sf::FloatRect bounds;
	sf::Text Title;
	Title.setFont(MineCraft);
	Title.setString("SLOW NUCES");
	Title.setCharacterSize(140u);
	Title.setFillColor(sf::Color::White);
	bounds = Title.getLocalBounds();
	Title.setOrigin(-bounds.left + bounds.width / 2.0f, -bounds.top + bounds.height / 2.0f);
	Title.setPosition(window.getSize().x / 2.0, 35.0f + 120.f);

	sf::Text Play;
	Play.setFont(Blox);
	Play.setString("SPACE to Play");
	Play.setCharacterSize(80u);
	Play.setFillColor(sf::Color::White);
	bounds = Play.getLocalBounds();
	Play.setOrigin(-bounds.left + bounds.width / 2.0f, -bounds.top + bounds.height / 2.0f);
	Play.setPosition(window.getSize().x / 2.0, 600.0f);

	sf::Text Controls;
	Controls.setFont(Blox);
	Controls.setString("C for Controls");
	Controls.setCharacterSize(60u);
	Controls.setFillColor(sf::Color::White);
	bounds = Controls.getLocalBounds();
	Controls.setOrigin(-bounds.left + bounds.width / 2.0f, -bounds.top + bounds.height / 2.0f);
	Controls.setPosition(window.getSize().x / 2.0, 700.0f);

	int type = 1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
				if (type == 1)
					window.close();
				else if (type == 2)
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
			window.draw(background);
			window.draw(controls);
		}
		window.display();
	}
	return choice;
}