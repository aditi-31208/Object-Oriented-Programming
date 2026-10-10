#include <iostream>
#include <string>
using namespace std;

// Single Inheritance - Person to Student
class Person {
protected:
    string name;
    int age;
    string address;

public:
    Person() {
        name = "Unknown";
        age = 0;
        address = "Unknown";
    }
    
    Person(string n, int a, string addr) {
        name = n;
        age = a;
        address = addr;
    }
    
    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
    }
};

class Student : public Person {
private:
    int rollNumber;
    float marks;

public:
    Student() : Person() {
        rollNumber = 0;
        marks = 0;
    }
    
    Student(string n, int a, string addr, int roll, float m) 
        : Person(n, a, addr) {
        rollNumber = roll;
        marks = m;
    }
    
    void displayStudent() {
        displayPerson();
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }
};

// Multilevel Inheritance - Vehicle -> Car -> ElectricCar
class Vehicle {
protected:
    string brand;
    string model;
    int year;

public:
    Vehicle() {
        brand = "Unknown";
        model = "Unknown";
        year = 0;
    }
    
    Vehicle(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }
    
    void displayVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : public Vehicle {
protected:
    int numberOfDoors;
    string fuelType;

public:
    Car() : Vehicle() {
        numberOfDoors = 4;
        fuelType = "Petrol";
    }
    
    Car(string b, string m, int y, int doors, string fuel) 
        : Vehicle(b, m, y) {
        numberOfDoors = doors;
        fuelType = fuel;
    }
    
    void displayCar() {
        displayVehicle();
        cout << "Number of Doors: " << numberOfDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryCapacity; // in kWh
    int range; // in km

public:
    ElectricCar() : Car() {
        batteryCapacity = 0;
        range = 0;
    }
    
    ElectricCar(string b, string m, int y, int doors, string fuel, 
                int battery, int r) 
        : Car(b, m, y, doors, fuel) {
        batteryCapacity = battery;
        range = r;
    }
    
    void displayElectricCar() {
        displayCar();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
        cout << "Range: " << range << " km" << endl;
    }
};

int main() {
    cout << "===== Single Inheritance - Student =====" << endl;
    Student s("John Doe", 20, "123 Main Street", 101, 85.5);
    s.displayStudent();
    
    cout << "\n===== Multilevel Inheritance - Electric Car =====" << endl;
    ElectricCar tesla("Tesla", "Model S", 2023, 4, "Electric", 100, 650);
    tesla.displayElectricCar();
    
    return 0;
}
