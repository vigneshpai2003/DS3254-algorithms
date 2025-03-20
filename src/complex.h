#pragma once

#include <iostream>

class Complex
{
private:
    double real, imag;

public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    ~Complex() {}

    void print() {
        std::cout << real << " + i " << imag;
    }

    Complex operator+(Complex const& obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }
};