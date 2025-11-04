#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;

public:
    
    void set(int r, int i) {
        real = r;
        imag = i;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }   
    Complex add(Complex C1, Complex C2) {
        Complex temp;
        temp.real = C1.real + C2.real;
        temp.imag = C1.imag + C2.imag;
        return temp;
    }
};

int main() {
	cout << "Name  : Raj Solankar\n";
    cout << "Roll No: 128\n";
    cout << "Class : S.Y. B. CSE\n"; 
    Complex C1, C2, C3;
    C1.set(5, 3);
    C2.set(10, 7);
    cout << "Complex number 1: ";
    C1.display();
    cout << "Complex number 2: ";
    C2.display();
    C3 = C3.add(C1, C2);
    cout << "Sum of complex numbers: ";
    C3.display();

 return 0;
}
