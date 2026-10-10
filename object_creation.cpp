#include <iostream>
#include <string>
using namespace std;

// Forward declaration for friend class
class FriendClassExample;

// Class with static data members and static member functions
class StaticExample {
private:
    static int count;
    int id;

public:
    StaticExample() {
        count++;
        id = count;
    }

    static void showCount() {
        cout << "Total objects created: " << count << endl;
    }

    void display() {
        cout << "Object ID: " << id << endl;
    }
};

int StaticExample::count = 0;

// Classes for friend function demonstration
class ClassA;
class ClassB;

class ClassA {
private:
    int valueA;

public:
    ClassA(int v) : valueA(v) {}
    friend void compareValues(ClassA &a, ClassB &b);
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int v) : valueB(v) {}
    friend void compareValues(ClassA &a, ClassB &b);
};

// Friend function accessing private members of two classes
void compareValues(ClassA &a, ClassB &b) {
    cout << "Value in ClassA: " << a.valueA << endl;
    cout << "Value in ClassB: " << b.valueB << endl;
    if (a.valueA > b.valueB) {
        cout << "ClassA value is greater" << endl;
    } else if (a.valueA < b.valueB) {
        cout << "ClassB value is greater" << endl;
    } else {
        cout << "Both values are equal" << endl;
    }
}

// Friend Class demonstration
class SecretData {
private:
    string password;
    int secretNumber;

public:
    SecretData(string p, int n) : password(p), secretNumber(n) {}
    
    // Declaring FriendClassExample as friend
    friend class FriendClassExample;
};

class FriendClassExample {
public:
    void displaySecret(SecretData &s) {
        cout << "Accessing private members through friend class:" << endl;
        cout << "Password: " << s.password << endl;
        cout << "Secret Number: " << s.secretNumber << endl;
    }
};

int main() {
    cout << "===== Static Members Demonstration =====" << endl;
    StaticExample s1, s2, s3;
    StaticExample::showCount();
    s1.display();
    s2.display();
    s3.display();
    
    cout << "\n===== Friend Function Demonstration =====" << endl;
    ClassA a(50);
    ClassB b(30);
    compareValues(a, b);
    
    cout << "\n===== Friend Class Demonstration =====" << endl;
    SecretData secret("myPassword123", 999);
    FriendClassExample friendObj;
    friendObj.displaySecret(secret);
    
    return 0;
}
