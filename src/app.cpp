#include <iostream>
#include "../include/Rational.h"
using namespace std;



/************************************************************************************/
/*  You can put in main to help you test your code.  */
int main()
{
    Rational r1(1,2);
    Rational r2(3,4);
    Rational r3 = r1 + r2;
    cout << "Rational r1: " << r1 << endl;
    cout << "Rational r2: " << r2 << endl;
    cout << "Rational r3: " << r3 << endl;      
    double d = r3;// call cast operator
    cout << "Double value of r3: " << d << endl;
    // test other operators
    r2 = r1 * r3;
    cout << "Rational r2 after multiplication: " << r2 << endl;
    r2 = r3 - r1;
    cout << "Rational r2 after subtraction: " << r2 << endl;
    r2 = r3 / r1;   
    cout << "Rational r2 after division: " << r2 << endl;
    
    return 0;
}
/* output:
Rational r1: 1/2
Rational r2: 3/4
Rational r3: 5/4
Double value of r3: 1.25
Rational r2 after multiplication: 5/8
Rational r2 after subtraction: 3/4
Rational r2 after division: 5/2 */