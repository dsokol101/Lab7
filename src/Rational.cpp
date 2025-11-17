#include <iostream>
#include "../include/Rational.h"
using namespace std;

Rational::Rational(int num, int denom) : numerator(num), denominator(denom)
{
    if (denominator == 0)
    {
        throw invalid_argument("Denominator cannot be zero.");
    }
    reduce();
}
// TODO: Implement operator overloads
