#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Shape {
public:
    Shape() {}
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void display() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
    const double PI = 3.14159;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return PI * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * PI * radius;
    }

    void display() override {
        cout << "\n--- Circle Info ---" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter (Circumference): " << calculatePerimeter() << endl;
        cout << "-------------------\n" << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() override {
        return length * width;
    }

    double calculatePerimeter() override {
        return 2 * (length + width);
    }

    void display() override {
        cout << "\n--- Rectangle Info ---" << endl;
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
        cout << "----------------------\n" << endl;
    }
};

class Triangle : public Shape {
private:
    double sideA;
    double sideB;
    double sideC;

public:
    Triangle(double a, double b, double c) : sideA(a), sideB(b), sideC(c) {}

    double calculateArea() override {
        double s = calculatePerimeter() / 2.0;
        if (s - sideA <= 0 || s - sideB <= 0 || s - sideC <= 0)
            return 0.0;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() override {
        return sideA + sideB + sideC;
    }

    void display() override {
        cout << "\n--- Triangle Info ---" << endl;
        cout << "Sides: " << sideA << ", " << sideB << ", " << sideC << endl;
        if ((sideA + sideB <= sideC) || (sideA + sideC <= sideB) || (sideB + sideC <= sideA)) {
            cout << "Area: N/A (Invalid Triangle)" << endl;
            cout << "Perimeter: " << calculatePerimeter() << " (Sum of sides)" << endl;
        } else {
            cout << "Area (Heron's Formula): " << calculateArea() << endl;
            cout << "Perimeter: " << calculatePerimeter() << endl;
        }
        cout << "---------------------\n" << endl;
    }
};

int main() {
    cout << "Name:Raj Solankar\n";
    cout << "Roll No: 128\n";
    cout << "Division: S.Y. B CSE" << endl;

    cout << fixed << setprecision(2);

    Circle myCircle(4.5);
    Rectangle myRectangle(6.0, 8.0);
    Triangle myTriangle(3.0, 4.0, 5.0);
    Triangle invalidTriangle(1.0, 2.0, 10.0);

    Shape* shapes[4];
    shapes[0] = &myCircle;
    shapes[1] = &myRectangle;
    shapes[2] = &myTriangle;
    shapes[3] = &invalidTriangle;

    for (int i = 0; i < 4; ++i) {
        shapes[i]->display();
    }

    return 0;
}