#include <iostream>
using namespace std;

class Complex {
private:
    float real;
    float imag;
public:
    // Constructor to initialize complex number
    Complex(float r = 0, float i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator + (Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // Display function to print complex numbers
    void display(){
        cout << "Real: " << real << ", Imaginary: " << imag << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0); // Initializing first complex number
    Complex c2(1.5, 2.5); // Initializing second complex number
    Complex c3;

    c3 = c1 + c2; // Using overloaded + operator

    // Displaying the result
    cout << "Sum of complex numbers: ";
    c3.display();

    return 0;
}
