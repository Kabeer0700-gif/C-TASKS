#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real, imag;
public:
    Complex(float r = 0, float i = 0) {
        real = r;
        imag = i;
    }

   
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    Complex operator-(const Complex& obj) {
        return Complex(real - obj.real, imag - obj.imag);
    }

    Complex operator*(const Complex& obj) {
        return Complex(real * obj.real - imag * obj.imag,
                       real * obj.imag + imag * obj.real);
    }

    Complex operator/(const Complex& obj) {
        float denominator = obj.real * obj.real + obj.imag * obj.imag;
        return Complex((real * obj.real + imag * obj.imag) / denominator,
                       (imag * obj.real - real * obj.imag) / denominator);
    }

    friend ostream& operator<<(ostream& out, const Complex& c);
    friend float magnitude(Complex c);
};

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

float magnitude(Complex c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

int main() {
    Complex c1(3, 4), c2(1, 2);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "Addition: " << c1 + c2 << endl;
    cout << "Subtraction: " << c1 - c2 << endl;
    cout << "Multiplication: " << c1 * c2 << endl;
    cout << "Division: " << c1 / c2 << endl;
    cout << "Magnitude of c1: " << magnitude(c1) << endl;

    return 0;
}
