#pragma once
#include <string>

class Book {
protected:
    std::string title;
    std::string author;
    std::string code;
    bool available;

public:
    Book(const std::string& title, const std::string& author, const std::string& code);
    virtual ~Book() {}

    virtual void PrintDetails() const = 0;

    bool IsAvailable() const { return available; }
    void SetAvailable(bool status) { available = status; }

    friend void IssueBook(Book& book);
};

class ScienceBook : public Book {
public:
    ScienceBook(const std::string& title, const std::string& author, const std::string& code);
    void PrintDetails() const override;
};

class HistoryBook : public Book {
public:
    HistoryBook(const std::string& title, const std::string& author, const std::string& code);
    void PrintDetails() const override;
};

class FictionBook : public Book {
public:
    FictionBook(const std::string& title, const std::string& author, const std::string& code);
    void PrintDetails() const override;
};

void IssueBook(Book& book);
Book** InitializeLibrary(int& size);
void FreeLibrary(Book** library, int size);
Book** InitializeIssuedBooksArray(int size);
void FreeIssuedBooksArray(Book** issuedBooks);
