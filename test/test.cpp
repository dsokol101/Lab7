#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"
#include "../include/Rational.h"
#include <sstream>

TEST_CASE("Constructor and reduction") {
    Rational r(2, 4);
    std::ostringstream out;
    out << r;
    CHECK(out.str() == "1/2");

    CHECK_THROWS_AS(Rational(1, 0), std::invalid_argument);
}

TEST_CASE("operator double() conversion") {
    Rational r(3, 2);
    CHECK(static_cast<double>(r) == doctest::Approx(1.5));
}

TEST_CASE("operator+ addition") {
    Rational a(1, 2);
    Rational b(1, 3);

    Rational c = a + b;
    std::ostringstream out;
    out << c;
    CHECK(out.str() == "5/6");
}

TEST_CASE("operator- subtraction") {
    Rational a(3, 4);
    Rational b(1, 4);

    Rational c = a - b;
    std::ostringstream out;
    out << c;
    CHECK(out.str() == "1/2");
}

TEST_CASE("operator* multiplication") {
    Rational a(2, 3);
    Rational b(3, 4);

    Rational c = a * b;
    std::ostringstream out;
    out << c;
    CHECK(out.str() == "1/2");
}

TEST_CASE("operator/ division") {
    Rational a(2, 3);
    Rational b(3, 4);

    Rational c = a / b;
    std::ostringstream out;
    out << c;
    CHECK(out.str() == "8/9");
}

TEST_CASE("operator/ division by zero numerator") {
    Rational a(1, 2);
    Rational b(0, 5);  // zero numerator → represents 0
    CHECK_THROWS_AS(a / b, std::invalid_argument);
}

TEST_CASE("operator= assignment") {
    Rational a(5, 6);
    Rational b(1, 3);

    b = a;

    std::ostringstream out;
    out << b;
    CHECK(out.str() == "5/6");
}

TEST_CASE("operator<< output") {
    Rational r(-6, -8);    // reduces to 3/4
    std::ostringstream out;
    out << r;
    CHECK(out.str() == "3/4");

    Rational neg(6, -8);   // reduces to -3/4
    std::ostringstream out2;
    out2 << neg;
    CHECK(out2.str() == "-3/4");
}

