#include "LibraryManagement.h"
#include <iostream>
#include <vector>
#include <sstream>

Book::Book(std::string name, std::string num) : name(name), num(num) {

}
std::string Book::getName() const
{
    return name;
}

std::string Book::getNum() const
{
    return num;
}

void Book::setName(std::string name)
{
    this->name = name;
}

void Book::setNum(std::string num)
{
    this->num = num;
}
CourseBook::CourseBook() : Book("", ""){

}
CourseBook::CourseBook(std::string name, std::string num) : Book(name, num) {

}
void CourseBook::display()
{
    std::cout << this->getName() << std::endl;
    std::cout << this->getNum() << std::endl;
}


void LibraryManagement::Menu(int WINDOWWIDTH, int WINDOWHEIGHT, std::string& Game_State, int& mapIndex) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    sf::RenderWindow LibraryWindow(sf::VideoMode(1250, 900), "LibraryManagement", sf::Style::Default, settings);
    LibraryWindow.setFramerateLimit(60);

    // background
    sf::Sprite libBackground;
    sf::Texture libBackgroundTexture;
    if (libBackgroundTexture.loadFromFile("./Assets/Sprites/libraryBlurred2.png")) {
        libBackground.setTexture(libBackgroundTexture);
    }
    else {
        std::cout << "Failed to load libraryBlurred.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    // books
    std::vector<std::pair<sf::Sprite, bool>> books(4);
    std::vector<Book*> booksInfo(4);

	sf::Texture book1Texture;
    if (book1Texture.loadFromFile("./Assets/Sprites/book1.png")) {
        books[0].first.setTexture(book1Texture);
		books[0].second = true;
        booksInfo[0] = new CourseBook("Calculus", "101");
    }
    else {
        std::cout << "Failed to load book1.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book2Texture;
    if (book2Texture.loadFromFile("./Assets/Sprites/book2.png")) {
        books[1].first.setTexture(book2Texture);
        books[1].second = true;
        booksInfo[1] = new CourseBook("Programming", "102");
    }
    else {
        std::cout << "Failed to load book2.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book3Texture;
    if (book3Texture.loadFromFile("./Assets/Sprites/book3.png")) {
        books[2].first.setTexture(book3Texture);
        books[2].second = true;
        booksInfo[2] = new CourseBook("Physics", "103");
    }
    else {
        std::cout << "Failed to load book3.png" << std::endl;
        exit(EXIT_FAILURE);
    }
    sf::Texture book4Texture;
    if (book4Texture.loadFromFile("./Assets/Sprites/book4.png")) {
        books[3].first.setTexture(book4Texture);
        books[3].second = true;
        booksInfo[3] = new CourseBook("Chemistry", "104");
    }
    else {
        std::cout << "Failed to load book4.png" << std::endl;
        exit(EXIT_FAILURE);
    }

    sf::Text text, text2;
    sf::Font font;
    if (!font.loadFromFile("./Assets/Fonts/GROBOLD.ttf")) {
        std::cout << "error loading font" << std::endl;
    }
    std::stringstream ss;
    ss << "Click book to issue it.";
    text.setCharacterSize(50);;
    text.setPosition((float)WINDOWWIDTH / 2 - 200, (float)75);
    text.setFont(font);
    text.setFillColor(sf::Color::Black);
    text.setString(ss.str());

    std::stringstream enter;
    enter << "Press Any key to continue.";
    text2.setCharacterSize(40);;
    text2.setPosition((float)WINDOWWIDTH / 2 - 400, (float)675);
    text2.setFont(font);
    text2.setFillColor(sf::Color::Black);
    text2.setString(enter.str());

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
        bInfo << booksInfo[i]->getName() << "\n" << booksInfo[i]->getNum();
        booksInfoTexts[i].first.setCharacterSize(30);
        booksInfoTexts[i].first.setFont(font);
        booksInfoTexts[i].first.setFillColor(sf::Color::Black);
        booksInfoTexts[i].first.setString(bInfo.str());
		booksInfoTexts[i].second = true;
    }

    std::vector<CourseBook*> issuedBooks(4);
    for (int i = 0; i < 4; i++) issuedBooks[i] = new CourseBook("", "");
    std::vector<sf::Text> issuedBooksTexts(issuedBooks.size());
    int menu = 1;

    while (LibraryWindow.isOpen())
    {
        // Event processing
        sf::Event event;
        while (LibraryWindow.pollEvent(event) || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed) {
                Game_State = "Library";
                mapIndex = 2;

                for (int i = 0; i < 4; i++) {
                    delete issuedBooks[i];
                    delete booksInfo[i];
                }
                LibraryWindow.close();
                return;
            }
            else if (event.type == sf::Event::KeyPressed && menu == 1) {
                menu = 2;
            }
            else if (event.type == sf::Event::KeyPressed && menu == 2) {
                Game_State = "Library";
                mapIndex = 2;

                for (int i = 0; i < 4; i++) {
                    delete issuedBooks[i];
                    delete booksInfo[i];
                }
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
                issuedBooks[0]->setName(booksInfo[0]->getName());
                issuedBooks[0]->setNum(booksInfo[0]->getNum());
            }
            if (bound2.contains(mouse))
            {
                books[1].second = false;
                booksInfoTexts[1].second = false;
                issuedBooks[1]->setName(booksInfo[1]->getName());
                issuedBooks[1]->setNum(booksInfo[1]->getNum());
            }
            if (bound3.contains(mouse))
            {
                books[2].second = false;
                booksInfoTexts[2].second = false;
                issuedBooks[2]->setName(booksInfo[2]->getName());
                issuedBooks[2]->setNum(booksInfo[2]->getNum());
            }
            if (bound4.contains(mouse))
            {
                books[3].second = false;
                booksInfoTexts[3].second = false;
                issuedBooks[3]->setName(booksInfo[3]->getName());
                issuedBooks[3]->setNum(booksInfo[3]->getNum());
            }
        }

        for (int i = 0; i < issuedBooksTexts.size(); ++i)
        {
            std::stringstream issuedInfo;
            issuedInfo << issuedBooks[i]->getName() << "    " << issuedBooks[i]->getNum();
            issuedBooksTexts[i].setCharacterSize(20);
            issuedBooksTexts[i].setFont(font);
            issuedBooksTexts[i].setFillColor(sf::Color::Black);
            issuedBooksTexts[i].setString(issuedInfo.str());
        }


        LibraryWindow.clear();
        LibraryWindow.draw(libBackground);
        if (menu == 1) {
            for (int i = 0; i < books.size(); ++i) {
                if (books[i].second == true) {
			        books[i].first.setPosition(i * 300, 150);
			        LibraryWindow.draw(books[i].first);
                }
            }
            LibraryWindow.draw(text);
            LibraryWindow.draw(text2);
            for (int i = 0; i < booksInfoTexts.size(); ++i) {
                if (booksInfoTexts[i].second == true) {
                    booksInfoTexts[i].first.setPosition(60 + i * 300, 550);
                    LibraryWindow.draw(booksInfoTexts[i].first);
                }
            }
            LibraryWindow.draw(iBooks);
            for (int i = 0; i < issuedBooksTexts.size(); ++i) {
                issuedBooksTexts[i].setPosition(WINDOWWIDTH-200, 700 + i*25);
                LibraryWindow.draw(issuedBooksTexts[i]);
            }
        }
        else if(menu == 2) {
			text.setString("Books Issued:");
			text.setPosition((float)WINDOWWIDTH / 3, (float)250);
			LibraryWindow.draw(text);
            LibraryWindow.draw(text2);
			for (int i = 0; i < issuedBooksTexts.size(); ++i) {
				issuedBooksTexts[i].setPosition(WINDOWWIDTH / 3, 320 + i * 40);
                issuedBooksTexts[i].setCharacterSize(30);
				LibraryWindow.draw(issuedBooksTexts[i]);
			}
		}
        LibraryWindow.display();
    }
}
