#include <iostream>
using namespace std;
int area(int);          
int area(int, int);     
float area(float);      
float area(float, float); 
int main() {
    
    cout << "Name  :Raj Solankar\n";
    cout << "Roll No: 128\n";
    cout << "Class : S.Y. B. CSE\n";
    
    int s, l, b;
    float r, bs, ht;

    cout << "Enter side of a square: ";
    cin >> s;

    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;

    cout << "Enter radius of circle: ";
    cin >> r;

    cout << "Enter base and height of triangle: ";
    cin >> bs >> ht;

    cout << "\nCalculated Areas:\n";
    cout << "Area of Square: " << area(s) << endl;
    cout << "Area of Rectangle: " << area(l, b) << endl;
    cout << "Area of Circle: " << area(r) << endl;
    cout << "Area of Triangle: " << area(bs, ht) << endl;

    return 0;
}
int area(int s) {
    return s * s;
}

int area(int l, int b) {
    return l * b;
}

float area(float r) {
    return 3.14 * r * r;
}

float area(float bs, float ht) {
    return (bs * ht) / 2;
}