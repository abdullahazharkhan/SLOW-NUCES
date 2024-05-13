#include "CafeMenu.h"
#include <iostream>
#include <map>
#include <sstream>


void CafeMenu::Show(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow cafeWindow(sf::VideoMode(1250, 900), "Cafe", sf::Style::Default, settings);
	cafeWindow.setFramerateLimit(60);

	std::string gameState = "inMenu";
	float totalBill = 0.0f;
	// background
	sf::Sprite cafeBackground;
	sf::Texture cafeBackgroundTexture;
	if (cafeBackgroundTexture.loadFromFile("./Assets/Sprites/CafeBlurred3.png")) {
		cafeBackground.setTexture(cafeBackgroundTexture);
	}
	else {
		std::cout << "Failed to load cafeBlurred.png" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	//
	sf::FloatRect bounds;
	sf::Font font;
	if (!font.loadFromFile("./Assets/Fonts/RobotoBoldCondensed.ttf")) {
		std::cout << "error loading font" << std::endl;
	}
	sf::Text title;
	title.setFont(font);
	title.setString("SLOW-NUCES' Cafe");
	title.setCharacterSize(50u);
	title.setFillColor(sf::Color::Black);
	bounds = title.getLocalBounds();
	title.setOrigin(-bounds.left + bounds.width / 2.0f, -bounds.top + bounds.height / 2.0f);
	title.setPosition(1250 / 2.0, 50.0f);
	sf::Text instruction;
	instruction.setFont(font);
	instruction.setString("Press Space to proceed payment");
	instruction.setCharacterSize(30u);
	instruction.setFillColor(sf::Color::Black);
	bounds = instruction.getLocalBounds();
	instruction.setOrigin(-bounds.left + bounds.width / 2.0f, -bounds.top + bounds.height / 2.0f);
	instruction.setPosition(1250 / 2.0, 900 - 80.0f);


	// food items
	std::vector<std::pair<sf::Sprite, float>> foodItems(8);
	sf::Texture foodItemsTexture;
	if (foodItemsTexture.loadFromFile("./Assets/Sprites/foodSheet.png")) {
		for (int i = 0; i < foodItems.size(); i++) {
			foodItems[i].first.setScale(sf::Vector2f({ 4.0f, 4.0f }));
			foodItems[i].first.setTexture(foodItemsTexture);
		}

		foodItems[0].first.setTextureRect(sf::IntRect(0 * 34, 3 * 34, 34, 34));
		foodItems[0].second = 100.0f;
		foodItems[1].first.setTextureRect(sf::IntRect(1 * 34, 3 * 34, 34, 34));
		foodItems[1].second = 120.0f;
		foodItems[2].first.setTextureRect(sf::IntRect(2 * 34, 3 * 34, 34, 34));
		foodItems[2].second = 60.5f;
		foodItems[3].first.setTextureRect(sf::IntRect(1 * 34, 4 * 34, 34, 34));
		foodItems[3].second = 50.0f;
		foodItems[4].first.setTextureRect(sf::IntRect(5 * 34, 3 * 34, 34, 34));
		foodItems[4].second = 70.0f;
		foodItems[5].first.setTextureRect(sf::IntRect(5 * 34, 5 * 34, 34, 34));
		foodItems[5].second = 80.0f;
		foodItems[6].first.setTextureRect(sf::IntRect(0 * 34, 0 * 34, 34, 34));
		foodItems[6].second = 10.0f;
		foodItems[7].first.setTextureRect(sf::IntRect(13 * 34, 7 * 34, 34, 34));
		foodItems[7].second = 15.0f;
	}
	else {
		std::cout << "Failed to load foodSheet.png" << std::endl;
		exit(EXIT_FAILURE);
	}
	// food itens price
	std::vector<sf::Text> foodItemsPrice(8);
	for (int i = 0; i < foodItemsPrice.size(); ++i)
	{
		std::stringstream prices;
		prices << (char)('A' + i) << " --  Rs. " << foodItems[i].second;
		foodItemsPrice[i].setCharacterSize(30);
		foodItemsPrice[i].setFont(font);
		foodItemsPrice[i].setFillColor(sf::Color::Black);
		foodItemsPrice[i].setString(prices.str());
	}
	//purchased food
	// <spriteIndex, <quantity, price>>
	std::map<int, std::pair<int, float>> purchasedFood;
	std::vector<sf::Text> purchasedFoodTexts;

	//std::vector<std::pair<sf::Sprite, std::pair<int, float>>> purchasedFood;
	//std::vector<sf::Sprite> purchasedFoodSprites;
	//std::vector<std::pair<int, float>> purchasedFoodInfo;

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

			if (cafeEvent.type == sf::Event::KeyPressed && cafeEvent.key.code == sf::Keyboard::Space) {
				gameState = "inBill";
			}

			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::A))
			{
				purchasedFood[0].first++;
				purchasedFood[0].second += foodItems[0].second;
				totalBill += foodItems[0].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::B))
			{
				purchasedFood[1].first++;
				purchasedFood[1].second += foodItems[1].second;
				totalBill += foodItems[1].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::C))
			{
				purchasedFood[2].first++;
				purchasedFood[2].second += foodItems[2].second;
				totalBill += foodItems[2].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::D))
			{
				purchasedFood[3].first++;
				purchasedFood[3].second += foodItems[3].second;
				totalBill += foodItems[3].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::E))
			{
				purchasedFood[4].first++;
				purchasedFood[4].second += foodItems[4].second;
				totalBill += foodItems[4].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::F))
			{
				purchasedFood[5].first++;
				purchasedFood[5].second += foodItems[5].second;
				totalBill += foodItems[5].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::G))
			{
				purchasedFood[6].first++;
				purchasedFood[6].second += foodItems[6].second;
				totalBill += foodItems[6].second;
			}
			if (((cafeEvent.type == cafeEvent.KeyPressed) && cafeEvent.key.code == sf::Keyboard::H))
			{
				purchasedFood[7].first++;
				purchasedFood[7].second += foodItems[7].second;
				totalBill += foodItems[7].second;
			}
		}

		cafeWindow.clear();
		cafeWindow.draw(cafeBackground);
		cafeWindow.draw(title);
		if (gameState == "inMenu") {
			for (int i = 0; i < foodItems.size(); i++) {
				foodItems[i].first.setPosition(450, 120 + i * 80);
				cafeWindow.draw(foodItems[i].first);
			}
			for (int i = 0; i < foodItemsPrice.size(); i++) {
				foodItemsPrice[i].setPosition(600, 165 + i * 82);
				cafeWindow.draw(foodItemsPrice[i]);
			}
			cafeWindow.draw(instruction);
		}
		else if (gameState == "inBill") {
			int i = 0;
			for (auto it : purchasedFood) {
				foodItems[it.first].first.setPosition(450, 120 + (i++) * 80);
				sf::Text txt;
				txt.setFont(font);
				txt.setCharacterSize(30);
				txt.setFillColor(sf::Color::Black);
				std::stringstream ss;
				ss << "-- x" << it.second.first << "  Rs. " << it.second.second;
				txt.setString(ss.str());
				txt.setPosition(600, 165 + (i - 1) * 82);
				cafeWindow.draw(txt);
				cafeWindow.draw(foodItems[it.first].first);
			}
			sf::Text total;
			total.setFont(font);
			total.setCharacterSize(35);
			total.setFillColor(sf::Color::Black);
			std::stringstream s;
			s << "Total Rs. " << totalBill;
			total.setString(s.str());
			total.setPosition(900, 900-100.0f);
			cafeWindow.draw(total);
		}
		cafeWindow.display();
	}	

}