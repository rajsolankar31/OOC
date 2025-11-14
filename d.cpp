#include <iostream>
#include <vector>
#include <string>
#include <memory>

// Base Class
class Book {
private:
    std::string bookName;
    std::string category;
    double price;
    std::string author;

public:
    Book(std::string name, std::string cat, double pr, std::string auth)
        : bookName(name), category(cat), price(pr), author(auth) {}

    virtual void display() const {
        std::cout << "Book Name: " << bookName << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

    virtual ~Book() {}
};

// Derived Class
class FictionBook : public Book {
private:
    std::string genre;

public:
    FictionBook(std::string name, std::string cat, double pr, std::string auth, std::string gen)
        : Book(name, cat, pr, auth), genre(gen) {}

    void display() const override {
        Book::display();
        std::cout << "Genre: " << genre << std::endl;
    }
};

// Library Class
class Library {
private:
    std::vector<std::unique_ptr<Book>> books;

public:
    void addBook(std::unique_ptr<Book> book) {
        books.push_back(std::move(book));
    }

    void displayAllBooks() const {
        for (const auto& book : books) {
            book->display();
            std::cout << "-----------------------\n";
        }
    }
};

int main() {
    Library library;

    library.addBook(std::make_unique<Book>("General Book", "General", 10.99, "Author A"));
    library.addBook(std::make_unique<FictionBook>("Harry Potter", "Fiction", 15.99, "J.K. Rowling", "Fantasy"));

    std::cout << "Library Books:\n";
    library.displayAllBooks();

    return 0;
}
