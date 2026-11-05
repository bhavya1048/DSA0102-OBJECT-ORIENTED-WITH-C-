
#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    double real, imag;

public:
    Complex() {
        real = 0;
        imag = 0;
    }

    Complex(double r) {
        real = r;
        imag = 0;
    }

    Complex(double r, double i) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex operator*(Complex c) {
        return Complex(real*c.real - imag*c.imag,
                       real*c.imag + imag*c.real);
    }

    Complex operator/(Complex c) {
        double d = c.real*c.real + c.imag*c.imag;

        if (d == 0) {
            cout << "Division by zero is not allowed\n";
            return Complex();
        }

        return Complex((real*c.real + imag*c.imag)/d,
                       (imag*c.real - real*c.imag)/d);
    }

    bool operator==(Complex c) {
        return real == c.real && imag == c.imag;
    }

    friend ostream& operator<<(ostream& out, Complex c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "j";
        else
            out << " - " << -c.imag << "j";
        return out;
    }
};

int main() {
    Complex a(10, 5), b(3, 2);

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Equality: " << (a == b) << endl;

    return 0;
}
