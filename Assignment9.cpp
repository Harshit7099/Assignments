#include <iostream>
#include <string>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    Complex(int r = 0, int i = 0) : real(r), img(i) {}
    friend Complex operator+(const Complex& c1, const Complex& c2) {
        Complex temp;
        temp.real = c1.real + c2.real;
        temp.img = c1.img + c2.img;
        return temp;
    }
    friend Complex operator-(const Complex& c1, const Complex& c2) {
        Complex temp;
        temp.real = c1.real - c2.real;
        temp.img = c1.img - c2.img;
        return temp;
    }
    void Display() {
        cout << real << " + i" << img << endl;
    }
};

class Cents {
private:
    int cents;
public:
    Cents(int c = 0) : cents(c) {}
    friend Cents operator+(const Cents& c1, const Cents& c2) {
        Cents result;
        result.cents = c1.cents + c2.cents;
        return result;
    }
    void Display() {
        cout << cents << " cents" << endl;
    }
};

int main() {
    Complex C1(3, 7);
    Complex C2(5, 2);
    Complex C3 = C1 + C2; 
    C3.Display();

    Complex V1(3, 7);
    Complex V2(1, 4);
    Complex V3 = V1 - V2; 
    V3.Display();

    Cents money1(50);
    Cents money2(75);
    Cents total = money1 + money2; 
    total.Display();

    return 0;
}
