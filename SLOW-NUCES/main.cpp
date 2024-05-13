#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Animation.h"
#include "Character.h"
#include "Map.h"
#include "canteen.h"
#include "library.h"
#include "Pong.h"
#include "CafeMenu.h"
#include "LibraryManagement.h"

// declarations
int WINDOWWIDTH = 1250;
int WINDOWHEIGHT = 900;

// Total Maps
Map maps[5];
int mapIndex = 0; 

// main guy
Character mainGuy({ 700.0f, 260.0f });

int main()
{
    MainMenu mainMenu(1250, 900);
    bool choice = mainMenu.display();
    if (!choice) {
		return EXIT_SUCCESS;
	}

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1250, 900), "SLOW NUCES", sf::Style::Default, settings);
    window.setFramerateLimit(60);
    
     // Current Map
    std::string Game_State = "Outside";

    maps[0].Load("Outside");
    maps[1].Load("Inside");
    maps[2].Load("Library");
    maps[3].Load("Cafe");
    maps[4].Load("Pong");

    // timepoint for delta time measurement
    auto lastTime = std::chrono::steady_clock::now();
    sf::RectangleShape fadeEffect(sf::Vector2f(1250, 900));
    fadeEffect.setFillColor(sf::Color(0, 0, 0, 0)); // Start fully transparent

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
                // Simulating character entering coordinates
                // Change game state to trigger screen transition
                int newIndex = -1;
                sf::Vector2f newPosition = Map::changeState(Game_State, mainGuy.GetPosition(), newIndex);
                if (newPosition.x != -1 && newPosition.y != -1) {
                    for (int i = 0; i < 256; i += 3) {
        
                        fadeEffect.setFillColor(sf::Color(0, 0, 0, i));
                        window.clear();

                        maps[mapIndex].Draw(window);
                        window.draw(fadeEffect);
                        window.display();
                    }
                    mainGuy.spawnAt(newPosition);
                    mapIndex = newIndex;
                }
            }
        }

        // calculate delta time
        float deltaTime;
        {
            const auto new_time = std::chrono::steady_clock::now();
            deltaTime = std::chrono::duration<float>(new_time - lastTime).count();
            lastTime = new_time;
        }
        sf::Vector2f direction = { 0.0f, 0.0f };
        bool moved = false;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            direction.y -= 1.0f, moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            direction.x += 1.0f, moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            direction.y += 1.0f, moved = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            direction.x -= 1.0f, moved = true;
        }
        if (moved) {
            Map::updateCharacterPosition(Game_State, mainGuy.GetPosition(), direction);
        }

        mainGuy.SetDirection(direction);
        mainGuy.Update(deltaTime);

        window.clear();
        if (mapIndex < 4) {
			maps[mapIndex].Draw(window);
			mainGuy.Draw(window);
		}
		else if (Game_State == "Pong") {
            Pong::play(WINDOWWIDTH, WINDOWHEIGHT, Game_State, mapIndex);
		}
        else if (Game_State == "LibraryManagement") {
            LibraryManagement::Menu(WINDOWWIDTH, WINDOWHEIGHT, Game_State, mapIndex);
        }
        else if (Game_State == "CafeMenu") {
            CafeMenu::Show(WINDOWWIDTH, WINDOWHEIGHT, Game_State, mapIndex);
		}
        window.display();
    }
    return EXIT_SUCCESS;
}