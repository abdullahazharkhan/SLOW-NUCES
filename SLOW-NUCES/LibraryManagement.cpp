#include "LibraryManagement.h"

void LibraryManagement::Menu(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow LibraryWindow(sf::VideoMode(1250, 900), "LibraryManagement", sf::Style::Default, settings);
    LibraryWindow.setFramerateLimit(60);

    sf::Sprite pongBackground;
    sf::Texture pongBackgroundTexture;
    

    while (LibraryWindow.isOpen())
    {
        // Event processing
        sf::Event pongEvent;
        while (LibraryWindow.pollEvent(pongEvent))
        {
            // Request for closing the window
            if (pongEvent.type == sf::Event::Closed || (pongEvent.type == sf::Event::KeyPressed && pongEvent.key.code == sf::Keyboard::Escape)) {
                Game_State = "Library";
                mapIndex = 2;
                LibraryWindow.close();
                return;
            }
        }

        LibraryWindow.display();
    }
}

