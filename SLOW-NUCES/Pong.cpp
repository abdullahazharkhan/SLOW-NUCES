#include "Pong.h"
#include <iostream>
#include <sstream>

void Pong::play(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

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
    AIBat aibat(WINDOWWIDTH - 50, (WINDOWHEIGHT / 2 - 75));

    while (pongWindow.isOpen())
    {
        // Event processing
        sf::Event pongEvent;
        while (pongWindow.pollEvent(pongEvent))
        {
            // Request for closing the window
            if (pongEvent.type == sf::Event::Closed || (pongEvent.type == sf::Event::KeyPressed && pongEvent.key.code == sf::Keyboard::Escape)) {
                Game_State = "Inside";
                mapIndex = 1;
                pongWindow.close();
                return;
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
        ss1 << "Youre in table tennis court.\n\npress any key to begin\n\nesc to exit";

        startmessage.setCharacterSize(50);
        startmessage.setPosition((float)WINDOWWIDTH / 2 - 400, (float)WINDOWHEIGHT / 2 - 100);
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

