#include <iostream>
#include <string>
using namespace std;

class book {
private:
       int bookid;
       string title;
       string author;
       float price;
       static int bookcount;
       
public:
   // parameterized constructor
   book(int id, string t, string a, float p) {
       bookid = id;
       title = t;
       author = a;
       price = p;
       bookcount++;
       cout << "book object copied. total books: " << bookcount << endl;
   }
   
   // copy constructor 
   book(const book&b) {
       bookid = b.bookid;
       title = b.title;
       author = b.author;
       price = b.price;
       bookcount++;
       cout << "book object copied. total books: " << bookcount << endl;
   }  
   
   // destructor
   ~book() {
       bookcount--;
       cout << "book object destroyed. total books: " << bookcount << endl;
   }
   
   void display() {
       cout << "book id: " << bookid << endl;
       cout << "title: " << title << endl;
       cout << "author: " << author << endl;
       cout << "price: " << price << endl;
   }
   static int getbookcount() {
        return bookcount;
   }
};
 
int book::bookcount = 0;
 
 int main() {
     cout << "initial book count: " << book::getbookcount() << endl;
     cout << "------------------" << endl;
     
     // creating original book 
     book b1(101, "c++ programming", "bjarne stroustrup", 4500);
     b1.display();
     cout << "-------------------" << endl;
     
     // creating copy using copy constructor
     book b2(b1);
     b2.display();
     cout << "--------------" << endl;
     
     cout << "total books currently: " << book::getbookcount() << endl;
     cout << "--------------" << endl;
     
     // destructors will be called automatically when objects go out 
     return 0;
}
     
