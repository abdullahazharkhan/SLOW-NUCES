#pragma once
#include <SFML/Graphics.hpp>

class Book {
	protected:
	std::string name;
	std::string num;

	public:
		Book(std::string, std::string);
		std::string getName() const;
		std::string getNum() const;
		void setName(std::string);
		void setNum(std::string);

		virtual void display() = 0;
};
class CourseBook : public Book {
	public:
		CourseBook();
		CourseBook(std::string, std::string);
		void display() override;
};

class LibraryManagement
{
	public:
	static void Menu(int, int, std::string& game_state, int& mapIndex);
};
