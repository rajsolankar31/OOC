#include <iostream>
#include <vector>
#include <string>

// Base class demonstrating Encapsulation (private data with getters/setters) and Abstraction (hiding details via methods)
class Book {
private:
    std::string bookName;  // Encapsulated data
    std::string category;
    double price;
    std::string author;

public:
    // Constructor
    Book(std::string name, std::string cat, double pr, std::string auth)
        : bookName(name), category(cat), price(pr), author(auth) {}

    // Getters and setters for Encapsulation (controlled access to private data)
    std::string getBookName() const { return bookName; }
    std::string getCategory() const { return category; }
    double getPrice() const { return price; }
    std::string getAuthor() const { return author; }

    void setBookName(std::string name) { bookName = name; }
    void setCategory(std::string cat) { category = cat; }
    void setPrice(double pr) { price = pr; }
    void setAuthor(std::string auth) { author = auth; }

    // Virtual method for Polymorphism (can be overridden in derived classes)
    virtual void display() const {
        std::cout << "Book Name: " << bookName << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: $" << price << std::endl;
        std::cout << "Author: " << author << std::endl;
    }

    // Virtual destructor for proper cleanup in Inheritance
    virtual ~Book() {}
};

// Derived class demonstrating Inheritance (inherits from Book) and Polymorphism (overrides display)
class FictionBook : public Book {  // Inheritance: Extends Book
private:
    std::string genre;  // Additional attribute

public:
    FictionBook(std::string name, std::string cat, double pr, std::string auth, std::string gen)
        : Book(name, cat, pr, auth), genre(gen) {}

    // Polymorphism: Overriding the display method
    void display() const override {
        Book::display();  // Call base class method
        std::cout << "Genre: " << genre << std::endl;
    }
};

// Library class demonstrating Abstraction (hides complex book management logic)
class Library {
private:
    std::vector<Book*> books;  // Stores pointers to Book objects (supports Polymorphism)

public:
    // Method to add a book (Abstraction: Simple interface for adding)
    void addBook(Book* book) {
        books.push_back(book);
    }

    // Method to display all books (Abstraction: Hides iteration and display logic; uses Polymorphism for correct display)
    void displayAllBooks() const {
        for (const auto& book : books) {
            book->display();  // Polymorphism: Calls the correct display based on object type
            std::cout << "-------------------" << std::endl;
        }
    }

    // Destructor for cleanup
    ~Library() {
        for (auto& book : books) {
            delete book;
        }
    }
};

int main() {
    Library library;

    // Create and add books (demonstrating Polymorphism via base class pointers)
    library.addBook(new Book("General Book", "General", 10.99, "Author A"));
    library.addBook(new FictionBook("Harry Potter", "Fiction", 15.99, "J.K. Rowling", "Fantasy"));

    // Display all books
    std::cout << "Library Books:" << std::endl;
    library.displayAllBooks();

    return 0;
}
