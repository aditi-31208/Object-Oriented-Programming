#include <iostream>
#include <string>
using namespace std;

// Multiple Inheritance
class PersonalDetails {
protected:
    string name;
    int age;
    string gender;

public:
    PersonalDetails() {
        name = "Unknown";
        age = 0;
        gender = "Unknown";
    }
    
    PersonalDetails(string n, int a, string g) {
        name = n;
        age = a;
        gender = g;
    }
    
    void displayPersonal() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
    }
};

class SalaryDetails {
protected:
    float basicSalary;
    float allowances;
    float deductions;

public:
    SalaryDetails() {
        basicSalary = 0;
        allowances = 0;
        deductions = 0;
    }
    
    SalaryDetails(float bs, float al, float de) {
        basicSalary = bs;
        allowances = al;
        deductions = de;
    }
    
    float calculateNetSalary() {
        return basicSalary + allowances - deductions;
    }
    
    void displaySalary() {
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Allowances: " << allowances << endl;
        cout << "Deductions: " << deductions << endl;
        cout << "Net Salary: " << calculateNetSalary() << endl;
    }
};

class Employee : public PersonalDetails, public SalaryDetails {
private:
    int employeeId;
    string department;

public:
    Employee() : PersonalDetails(), SalaryDetails() {
        employeeId = 0;
        department = "Unknown";
    }
    
    Employee(string n, int a, string g, float bs, float al, float de,
             int id, string dept) 
        : PersonalDetails(n, a, g), SalaryDetails(bs, al, de) {
        employeeId = id;
        department = dept;
    }
    
    void displayEmployee() {
        cout << "Employee ID: " << employeeId << endl;
        cout << "Department: " << department << endl;
        displayPersonal();
        displaySalary();
    }
};

// Hierarchical Inheritance
class Shape {
protected:
    string color;

public:
    Shape() {
        color = "Unknown";
    }
    
    Shape(string c) {
        color = c;
    }
    
    virtual void draw() {
        cout << "Drawing a shape..." << endl;
    }
    
    virtual float area() = 0; // pure virtual function
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle() : Shape() {
        radius = 0;
    }
    
    Circle(string c, float r) : Shape(c) {
        radius = r;
    }
    
    void draw() override {
        cout << "Drawing a circle of radius " << radius << " with color " << color << endl;
    }
    
    float area() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float width;

public:
    Rectangle() : Shape() {
        length = 0;
        width = 0;
    }
    
    Rectangle(string c, float l, float w) : Shape(c) {
        length = l;
        width = w;
    }
    
    void draw() override {
        cout << "Drawing a rectangle of " << length << "x" << width 
             << " with color " << color << endl;
    }
    
    float area() override {
        return length * width;
    }
};

int main() {
    cout << "===== Multiple Inheritance - Employee =====" << endl;
    Employee emp("Alice Smith", 30, "Female", 60000, 15000, 5000, 1001, "IT");
    emp.displayEmployee();
    
    cout << "\n===== Hierarchical Inheritance - Shapes =====" << endl;
    Circle circle("Red", 5);
    Rectangle rectangle("Blue", 10, 6);
    
    circle.draw();
    cout << "Circle Area: " << circle.area() << endl;
    
    rectangle.draw();
    cout << "Rectangle Area: " << rectangle.area() << endl;
    
    return 0;
}
