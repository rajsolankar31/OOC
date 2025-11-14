#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ------------------- BOOK BASE CLASS -------------------
class Book {
protected:
    string name;
    string category;
    string author;

public:
    Book(string n, string c, string a)
        : name(n), category(c), author(a) {}

    virtual void display() const {
        cout << "Book Name: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Author: " << author << endl;
    }

    virtual ~Book() {}
};

// ----------- POLYMORPHIC CHILD BOOK CLASSES ------------

// Fiction Book
class FictionBook : public Book {
    string genre;
public:
    FictionBook(string n, string c, string a, string g)
        : Book(n, c, a), genre(g) {}

    void display() const override {
        Book::display();
        cout << "Genre: " << genre << endl;
    }
};

// Science Book
class ScienceBook : public Book {
    string field;
public:
    ScienceBook(string n, string c, string a, string f)
        : Book(n, c, a), field(f) {}

    void display() const override {
        Book::display();
        cout << "Field: " << field << endl;
    }
};

// ------------------- PERSON BASE CLASS -------------------
class Person {
protected:
    string name;
    int id;

public:
    Person(string n, int i) : name(n), id(i) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    virtual ~Person() {}
};

// ------------------- MEMBER CLASS ------------------------
class Member : public Person {
public:
    Member(string n, int i) : Person(n, i) {}

    void display() const override {
        Person::display();
        cout << "Role: Member" << endl;
    }
};

// ------------------- LIBRARIAN CLASS ---------------------
class Librarian : public Person {
public:
    Librarian(string n, int i) : Person(n, i) {}

    void display() const override {
        Person::display();
        cout << "Role: Librarian" << endl;
    }
};

// --------------------- LIBRARY CLASS ---------------------
class Library {
    vector<Book*> books;   // Stores Book pointer (supports polymorphism)

public:
    void addBook(Book* b) {
        books.push_back(b);
    }

    void displayBooks() const {
        for (auto b : books) {
            b->display();
            cout << "------------------" << endl;
        }
    }

    // Delete allocated memory
    ~Library() {
        for (auto b : books)
            delete b;
    }
};

// ----------------------- MAIN ----------------------------
int main() {
    Library lib;

    // Books
    lib.addBook(new Book("General Book", "General", "Author A"));
    lib.addBook(new FictionBook("Harry Potter", "Fiction", "J.K. Rowling", "Fantasy"));
    lib.addBook(new ScienceBook("Space Facts", "Science", "Carl Sagan", "Astronomy"));

    // People
    Member m("Alice", 101);
    Librarian l("Bob", 1);

    cout << "---- People ----\n";
    m.display();
    cout << "------------------\n";
    l.display();

    cout << "\n---- Library Books ----\n";
    lib.displayBooks();

    return 0;
}
