#include "LibraryManagement.h"
#include <iostream>
#include <vector>
#include <sstream>

void LibraryManagement::Menu(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow LibraryWindow(sf::VideoMode(1250, 900), "LibraryManagement", sf::Style::Default, settings);
    LibraryWindow.setFramerateLimit(60);

    // background
    sf::Sprite libBackground;
    sf::Texture libBackgroundTexture;
    if (libBackgroundTexture.loadFromFile("./Assets/Sprites/libraryBlurred.png")) {
        libBackground.setTexture(libBackgroundTexture);
    }
    else {
        std::cout << "Failed to load libraryBlurred.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // books
    std::vector<std::pair<sf::Sprite, bool>> books(4);
    std::vector<std::pair<std::string, std::string>> booksInfo(4);
    

	sf::Texture book1Texture;
    if (book1Texture.loadFromFile("./Assets/Sprites/book1.png")) {
        books[0].first.setTexture(book1Texture);
		books[0].second = true;
        booksInfo[0].first = "Calculus";
        booksInfo[0].second = "101";
    }
    else {
        std::cout << "Failed to load book1.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book2Texture;
    if (book2Texture.loadFromFile("./Assets/Sprites/book2.png")) {
        books[1].first.setTexture(book2Texture);
        books[1].second = true;
        booksInfo[1].first = "Programming";
        booksInfo[1].second = "102";
    }
    else {
        std::cout << "Failed to load book2.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book3Texture;
    if (book3Texture.loadFromFile("./Assets/Sprites/book3.png")) {
        books[2].first.setTexture(book3Texture);
        books[2].second = true;
        booksInfo[2].first = "Physics";
        booksInfo[2].second = "103";
    }
    else {
        std::cout << "Failed to load book3.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book4Texture;
    if (book4Texture.loadFromFile("./Assets/Sprites/book4.png")) {
        books[3].first.setTexture(book4Texture);
        books[3].second = true;
        booksInfo[3].first = "Chemistry";
        booksInfo[3].second = "104";
    }
    else {
        std::cout << "Failed to load book4.png" << std::endl;
        exit(EXIT_FAILURE);
    }

    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("./Assets/Fonts/MineCraft.ttf")) {
        std::cout << "error loading font" << std::endl;
    }
    std::stringstream ss;
    ss << "Press book to issue it.";
    text.setCharacterSize(50);;
    text.setPosition((float)WINDOWWIDTH / 2 - 400, (float)WINDOWHEIGHT - 200);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString(ss.str());

    sf::Text iBooks;
    std::stringstream ss2;
    ss2 << "Issued Books";
    iBooks.setCharacterSize(30);;
    iBooks.setPosition(WINDOWWIDTH - 200, 700 - 30);
    iBooks.setFont(font);
    iBooks.setFillColor(sf::Color::Black);
    iBooks.setString(ss2.str());
    std::vector<std::pair<sf::Text, bool>> booksInfoTexts(4);
    for (int i = 0; i < booksInfoTexts.size(); ++i)
    {
        std::stringstream bInfo;
        bInfo << booksInfo[i].first << "\n" << booksInfo[i].second;
        booksInfoTexts[i].first.setCharacterSize(30);
        booksInfoTexts[i].first.setFont(font);
        booksInfoTexts[i].first.setFillColor(sf::Color::Black);
        booksInfoTexts[i].first.setString(bInfo.str());
		booksInfoTexts[i].second = true;
    }

    std::vector<std::pair<std::string, std::string>> issuedBooks(4);
    std::vector<sf::Text> issuedBooksTexts(issuedBooks.size());

    while (LibraryWindow.isOpen())
    {
        // Event processing
        sf::Event event;
        while (LibraryWindow.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                Game_State = "Library";
                mapIndex = 2;

                LibraryWindow.close();
                return;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // transform the mouse position from window coordinates to world coordinates
            sf::Vector2f mouse = LibraryWindow.mapPixelToCoords(sf::Mouse::getPosition(LibraryWindow));

            // retrieve the bounding box of the sprite
            sf::FloatRect bound1 = books[0].first.getGlobalBounds();
            sf::FloatRect bound2 = books[1].first.getGlobalBounds();
            sf::FloatRect bound3 = books[2].first.getGlobalBounds();
            sf::FloatRect bound4 = books[3].first.getGlobalBounds();

            // hit test
            if (bound1.contains(mouse))
            {
                books[0].second = false;
                booksInfoTexts[0].second = false;
                issuedBooks[0]= { booksInfo[0].first, booksInfo[0].second };
            }
            if (bound2.contains(mouse))
            {
                books[1].second = false;
                booksInfoTexts[1].second = false;
                issuedBooks[1] = { booksInfo[1].first, booksInfo[1].second };
            }
            if (bound3.contains(mouse))
            {
                books[2].second = false;
                booksInfoTexts[2].second = false;
                issuedBooks[2] = { booksInfo[2].first, booksInfo[2].second };
            }
            if (bound4.contains(mouse))
            {
                books[3].second = false;
                booksInfoTexts[3].second = false;
                issuedBooks[3] = { booksInfo[3].first, booksInfo[3].second };
            }
        }

        for (int i = 0; i < issuedBooksTexts.size(); ++i)
        {
            std::stringstream issuedInfo;
            issuedInfo << issuedBooks[i].first << "    " << issuedBooks[i].second;
            issuedBooksTexts[i].setCharacterSize(20);
            issuedBooksTexts[i].setFont(font);
            issuedBooksTexts[i].setFillColor(sf::Color::Black);
            issuedBooksTexts[i].setString(issuedInfo.str());
        }


        LibraryWindow.clear();
        LibraryWindow.draw(libBackground);
        for (int i = 0; i < books.size(); ++i) {
            if (books[i].second == true) {
			    books[i].first.setPosition(i * 300, 100);
			    LibraryWindow.draw(books[i].first);
            }
        }
        LibraryWindow.draw(text);
        for (int i = 0; i < booksInfoTexts.size(); ++i) {
            if (booksInfoTexts[i].second == true) {
                booksInfoTexts[i].first.setPosition(60 + i * 300, 500);
                LibraryWindow.draw(booksInfoTexts[i].first);
            }
        }
        LibraryWindow.draw(iBooks);
        for (int i = 0; i < issuedBooksTexts.size(); ++i) {
            issuedBooksTexts[i].setPosition(WINDOWWIDTH-200, 700 + i*25);
            LibraryWindow.draw(issuedBooksTexts[i]);
        }
        LibraryWindow.display();
    }
}

