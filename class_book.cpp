#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    int bookId;
    string title;
    string author;
    float price;
    static int bookCount;

public:
    // Parameterized constructor
    Book(int id, string t, string a, float p) {
        bookId = id;
        title = t;
        author = a;
        price = p;
        bookCount++;
        cout << "Book object created. Total books: " << bookCount << endl;
    }

    // Copy constructor
    Book(const Book &b) {
        bookId = b.bookId;
        title = b.title;
        author = b.author;
        price = b.price;
        bookCount++;
        cout << "Book object copied. Total books: " << bookCount << endl;
    }

    // Destructor
    ~Book() {
        bookCount--;
        cout << "Book object destroyed. Total books: " << bookCount << endl;
    }

    void display() {
        cout << "Book ID: " << bookId << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }

    static int getBookCount() {
        return bookCount;
    }
};

int Book::bookCount = 0;

int main() {
    cout << "Initial book count: " << Book::getBookCount() << endl;
    cout << "-------------------------" << endl;
    
    // Creating original book
    Book b1(101, "C++ Programming", "Bjarne Stroustrup", 4500);
    b1.display();
    cout << "-------------------------" << endl;
    
    // Creating copy using copy constructor
    Book b2(b1);
    b2.display();
    cout << "-------------------------" << endl;
    
    cout << "Total books currently: " << Book::getBookCount() << endl;
    cout << "-------------------------" << endl;
    
    // Destructors will be called automatically when objects go out of scope
    return 0;
}
