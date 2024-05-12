#include "library.h"
#include <iostream>

// Implementation of Book class
Book::Book(const std::string& title, const std::string& author, const std::string& code)
    : title(title), author(author), code(code), available(true) {}

// Implementation of ScienceBook class
ScienceBook::ScienceBook(const std::string& title, const std::string& author, const std::string& code)
    : Book(title, author, code) {}

void ScienceBook::PrintDetails() const {
    std::cout << "Science, ";
    std::cout << "Title: " << title << ", Author: " << author << ", Code: " << code << ", Available: " << (available ? "Yes" : "No") << std::endl;
}

// Implementation of HistoryBook class
HistoryBook::HistoryBook(const std::string& title, const std::string& author, const std::string& code)
    : Book(title, author, code) {}

void HistoryBook::PrintDetails() const {
    std::cout << "History, ";
    std::cout << "Title: " << title << ", Author: " << author << ", Code: " << code << ", Available: " << (available ? "Yes" : "No") << std::endl;
}

// Implementation of FictionBook class
FictionBook::FictionBook(const std::string& title, const std::string& author, const std::string& code)
    : Book(title, author, code) {}

void FictionBook::PrintDetails() const {
    std::cout << "Fiction, ";
    std::cout << "Title: " << title << ", Author: " << author << ", Code: " << code << ", Available: " << (available ? "Yes" : "No") << std::endl;
}

// Implementation of IssueBook function
void IssueBook(Book& book) {
    if (book.IsAvailable()) {
        std::cout << "Book '" << book.title << "' issued." << std::endl;
        book.available = false;
    }
    else {
        std::cout << "Book '" << book.title << "' is not available." << std::endl;
    }
}

// Implementation of InitializeLibrary function
Book** InitializeLibrary(int& size) {
    size = 6;
    Book** library = new Book * [size];

    library[0] = new ScienceBook("Physics", "Albert Einstein", "PHY001");
    library[1] = new ScienceBook("Chemistry", "prof jenny", "CHEM002");
    library[2] = new HistoryBook("World War I", "Winston Churchill", "WWII001");
    library[3] = new HistoryBook("the train to pakistan", "khushwant singhda ", "REN001");
    library[4] = new FictionBook("perashar kookar", "siddique saliq", "TKAM001");
    library[5] = new FictionBook("1984", "George Orwell", "1984_001");

    return library;
}

// Implementation of FreeLibrary function
void FreeLibrary(Book** library, int size) {
    for (int i = 0; i < size; ++i) {
        delete library[i];
    }
    delete[] library;
}

// Implementation of InitializeIssuedBooksArray function
Book** InitializeIssuedBooksArray(int size) {
    Book** issuedBooks = new Book * [size];
    for (int i = 0; i < size; ++i) {
        issuedBooks[i] = nullptr;
    }
    return issuedBooks;
}

// Implementation of FreeIssuedBooksArray function
void FreeIssuedBooksArray(Book** issuedBooks) {
    delete[] issuedBooks;
}
