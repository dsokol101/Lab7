#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>

class Rational
{
private:
    int numerator;
    int denominator;
    void reduce()
    {
        int gcd = computeGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
    static int computeGCD(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    Rational(int num = 0, int denom = 1);
    operator double() const;
    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;
    Rational& operator=(const Rational &other);
    friend std::ostream &operator<<(std::ostream &os, const Rational &r);
};
#endif