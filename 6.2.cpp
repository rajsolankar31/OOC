#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle() { 
        cout << "This is a Vehicle" << endl; 
    }
};

class Car : public Vehicle {
public:
    Car() { 
        cout << "This Vehicle is Car" << endl; 
    }
};

class Bus : public Vehicle {
public:
    Bus() { 
        cout << "This Vehicle is Bus" << endl; 
    }
};

int main() {

    cout << "Name  : Raj Solankar\n";
    cout << "Roll No: 128\n";
    cout << "Class : S.Y. B. CSE\n";
    
    Car obj1;
    Bus obj2;

    
    return 0;
}