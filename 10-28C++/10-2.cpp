#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }
    void Display()
    {
        cout << " real = " << real << " imag = " << imag << endl;
    }
    Complex operator+(Complex &c2);
    Complex operator-(Complex &c2);
    Complex operator*(Complex &c2);
    Complex operator/(Complex &c2);
    string operator<<(Complex &c2);
};

Complex Complex::operator+(Complex &c2)
{
    Complex c;
    c.real = this->real + c2.real;
    c.imag = this->imag + c2.imag;
    return c;
}
Complex Complex::operator-(Complex &c2)
{
    Complex c;
    c.real = this->real - c2.real;
    c.imag = this->imag - c2.imag;
    return c;
}

Complex Complex::operator*(Complex &c2)
{
    Complex c;
    c.real = this->real * c2.real;
    c.imag = this->imag * c2.imag;
    return c;
}

Complex Complex::operator/(Complex &c2)
{
    Complex c;
    c.real = this->real / c2.real;
    c.imag = this->imag / c2.imag;
    return c;
}

int main()
{
    Complex a(3, 4);
    Complex b(2, 3);
    Complex c;
    c = a + b;
    cout << "a + b:";
    c.Display();
    c = a - b;
    cout << "a - b:";
    c.Display();
    c = a * b;
    cout << "a * b:";
    c.Display();
    c = a / b;
    cout << "a / b:";
    c.Display();
}