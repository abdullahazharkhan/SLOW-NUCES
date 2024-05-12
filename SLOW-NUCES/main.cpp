#include <iostream>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <sstream>
#include "MainMenu.h"
#include "Animation.h"
#include "Character.h"
#include "Map.h"
#include "canteen.h"
#include "library.h"
#include "Ball.h"
#include "Bat.h"
#include "AIBat.h"

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

		if (Game_State == "Pong") {
            sf::RenderWindow pongWindow(sf::VideoMode(1250, 900), "Pong", sf::Style::Default, settings);
			pongWindow.setFramerateLimit(60);

            sf::Sprite pongBackground;
            sf::Texture pongBackgroundTexture;
            if (pongBackgroundTexture.loadFromFile("./Assets/Sprites/pongBg.png")) {
                pongBackground.setTexture(pongBackgroundTexture);
            }
            else {
                std::cout << "Failed to load tileset" << std::endl;
                exit(EXIT_FAILURE);
            }

            int aibatcounter = 0;
            bool started = false;
			int playerScore = 0, aiScore = 0;
            Bat bat(50, (WINDOWHEIGHT / 2 - 75));
            Ball ball(WINDOWWIDTH / 2, WINDOWHEIGHT / 2);
            AIBat aibat(WINDOWWIDTH-50, (WINDOWHEIGHT / 2 - 75));

            while (pongWindow.isOpen())
            {
                // Event processing
                sf::Event pongEvent;
                while (pongWindow.pollEvent(pongEvent))
                {
                    // Request for closing the window
                    if (pongEvent.type == sf::Event::Closed || (pongEvent.type == sf::Event::KeyPressed && pongEvent.key.code == sf::Keyboard::Escape)) {
                        pongWindow.close();
                        Game_State = "Inside";
						mapIndex = 1;
                    }
                }

                if (((pongEvent.type == pongEvent.KeyPressed) && pongEvent.key.code == sf::Keyboard::Up)) 
                {
                    bat.movePaddleTop();
                }

                if (((pongEvent.type == pongEvent.KeyPressed) && pongEvent.key.code == sf::Keyboard::Down))
                {
                    bat.movePaddleBottom(WINDOWHEIGHT);
                }

                ball.reboundSides(WINDOWHEIGHT);
                ball.passRight(WINDOWWIDTH, WINDOWHEIGHT, playerScore);
                ball.passLeft(WINDOWWIDTH, WINDOWHEIGHT, aiScore);

                if (ball.getBallFloatRect().intersects(bat.getPaddleFloatRect()))
                {
                    ball.reboundBatorAI();
                }

                if (ball.getBallFloatRect().intersects(aibat.getPaddleFloatRect()))
                {

                    ball.reboundBatorAI();
                }

                if (ball.getBallFloatRect().top > (aibat.getPaddleFloatRect().top) + 50)
                {
                    if (aibatcounter % 10 == 0)
                        aibat.movePaddleBottom(WINDOWHEIGHT);
                }

                if (ball.getBallFloatRect().top < (aibat.getPaddleFloatRect().top) + 50)
                {
                    if (aibatcounter % 10 == 0)
                        aibat.movePaddleTop();
                }

                if (ball.getBallPosition.y > WINDOWHEIGHT)
                    aibat.AIBatSpeedReverse();

                //scores message
                sf::Text scores;
                std::stringstream ss;

                ss << "your score: " << playerScore << "       AI's score: " << aiScore;

                sf::Font font;
                if (!font.loadFromFile("./Assets/Fonts/MineCraft.ttf")) {
                    std::cout << "error loading font" << std::endl;
                }

                scores.setFont(font);
                scores.setCharacterSize(45);
                scores.setFillColor(sf::Color::White);

                scores.setString(ss.str());

				// start message
                sf::Text startmessage;
                std::stringstream ss1;
                ss1 << "welcome to table tennis.\n\npress any key to begin\n\nesc to exit";

                startmessage.setCharacterSize(50);
                startmessage.setPosition(WINDOWWIDTH / 2 - 400, WINDOWHEIGHT / 2 - 100);
                startmessage.setFont(font);
                startmessage.setString(ss1.str());

                if (aibatcounter == 1000000)
                {
                    aibatcounter = 0;
                }
                aibatcounter++;
                ball.update();
                bat.update();
                aibat.update();


                // Clear the whole window before rendering a new frame
                pongWindow.clear();
				pongWindow.draw(pongBackground);
                // Draw some graphical entities
				
                if (started == false)
                {
                    pongWindow.draw(startmessage);
                    ball.stop();
                    if (pongEvent.type == pongEvent.KeyPressed)
                    {
                        started = true;
                        ball.go();
                    }
                }
                else
                {
                    pongWindow.draw(bat.getPaddleObject());
                    pongWindow.draw(ball.getBallObject());
                    pongWindow.draw(scores);
                    pongWindow.draw((aibat.getPaddleObject()));
                }
                

                // End the current frame and display its contents on screen
                pongWindow.display();
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
        else if (Game_State == "pong") {
			maps[4].Draw(window);
		}
        window.display();
    }
/*
    Canteen canteen;
    sf::RenderWindow canteenWindow(sf::VideoMode(800, 600), "Canteen", sf::Style::Default, settings);
    while (canteenWindow.isOpen()) {
        sf::Event event;
        while (canteenWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
		        canteenWindow.close();
		    }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
			    canteen.takeOrder(event);
		    }
        }
        canteen.displayMenu(canteenWindow);
        canteen.displayBill(canteenWindow);
        canteenWindow.display();
    }*/


    return EXIT_SUCCESS;
}