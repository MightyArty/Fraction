#include "doctest.h"
#include "sources/Fraction.hpp"
#include <stdexcept>

using namespace std;
using namespace ariel;

TEST_CASE("Constructors")
{
    Fraction frac1(2, 3);
    CHECK(frac1.getTop() == 2);
    CHECK(frac1.getBottom() == 3);

    Fraction frac2(3, 5);
    CHECK(frac2.getTop() == 3);
    CHECK(frac2.getBottom() == 5);

    Fraction frac3;
    CHECK(frac3.getTop() == 0);
    CHECK(frac3.getBottom() == 1);
}

TEST_CASE("Copy Constructor")
{
    Fraction frac1(2, 3);
    Fraction frac2(frac1);
    CHECK(frac1.getTop() == frac2.getTop());
    CHECK(frac1.getBottom() == frac2.getBottom());
}

TEST_CASE("Unary Operators")
{
    SUBCASE("Minus operator")
    {
        Fraction frac1(1, 2);
        Fraction frac2(2, 3);

        Fraction frac3 = -frac1;
        CHECK(frac3.getTop() == -1);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = -frac2;
        CHECK(frac4.getTop() == -2);
        CHECK(frac4.getBottom() == 3);
    }

    SUBCASE("Plus operator")
    {
        Fraction frac1(1, 2);
        Fraction frac2(2, 3);

        Fraction frac3 = +frac1;
        CHECK(frac3.getTop() == 1);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = +frac2;
        CHECK(frac4.getTop() == 2);
        CHECK(frac4.getBottom() == 3);
    }

    SUBCASE("Pre-Increment operator")
    {
        Fraction frac1(1, 2);
        Fraction frac2(2, 3);

        Fraction frac3 = ++frac1;
        CHECK(frac1.getTop() == 3);
        CHECK(frac1.getBottom() == 2);
        CHECK(frac3.getTop() == 3);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = ++frac2;
        CHECK(frac2.getTop() == 5);
        CHECK(frac2.getBottom() == 3);
        CHECK(frac4.getTop() == 5);
        CHECK(frac4.getBottom() == 3);
    }

    SUBCASE("Post-Increment operator")
    {
        Fraction frac1(1, 2);
        Fraction frac2(2, 3);

        Fraction frac3 = frac1++;
        CHECK(frac1.getTop() == 3);
        CHECK(frac1.getBottom() == 2);
        CHECK(frac3.getTop() == 1);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = frac2++;
        CHECK(frac2.getTop() == 5);
        CHECK(frac2.getBottom() == 3);
        CHECK(frac4.getTop() == 2);
        CHECK(frac4.getBottom() == 3);
    }

    SUBCASE("Pre-Decrement operator")
    {
        Fraction frac1(5, 2);
        Fraction frac2(4, 3);

        Fraction frac3 = --frac1;
        CHECK(frac1.getTop() == 3);
        CHECK(frac1.getBottom() == 2);
        CHECK(frac3.getTop() == 3);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = --frac2;
        CHECK(frac2.getTop() == 1);
        CHECK(frac2.getBottom() == 3);
        CHECK(frac4.getTop() == 1);
        CHECK(frac4.getBottom() == 3);
    }

    SUBCASE("Post-Decrement operator")
    {
        Fraction frac1(5, 2);
        Fraction frac2(4, 3);

        Fraction frac3 = frac1--;
        CHECK(frac1.getTop() == 3);
        CHECK(frac1.getBottom() == 2);
        CHECK(frac3.getTop() == 5);
        CHECK(frac3.getBottom() == 2);

        Fraction frac4 = frac2--;
        CHECK(frac2.getTop() == 1);
        CHECK(frac2.getBottom() == 3);
        CHECK(frac4.getTop() == 4);
    }
}

TEST_CASE("Binary Operators")
{
    SUBCASE("Addition operator")
    {
        Fraction frac1(3, 4);
        Fraction frac2(1, 2);
        Fraction result = frac1 + frac2;
        Fraction expected(5, 4);
        CHECK(result == expected);

        result = frac1 + 2;
        expected = Fraction(11, 4);
        CHECK(result == expected);

        result = frac1 + 2.5;
        expected = Fraction(11, 4);
        CHECK(result == expected);
    }

    SUBCASE("Substraction operator")
    {
        Fraction frac1(3, 4);
        Fraction frac2(1, 2);
        Fraction result = frac1 - frac2;
        Fraction expected(1, 4);
        CHECK(result == expected);

        result = frac1 - 2;
        expected = Fraction(-5, 4);
        CHECK(result == expected);

        result = frac1 - 2.5;
        expected = Fraction(-7, 4);
        CHECK(result == expected);
    }

    SUBCASE("Muliplication operator")
    {
        Fraction frac1(3, 4);
        Fraction frac2(1, 2);
        Fraction result = frac1 * frac2;
        Fraction expected(3, 8);
        CHECK(result == expected);

        result = frac1 * 2;
        expected = Fraction(3, 2);
        CHECK(result == expected);

        result = frac1 * 2.5;
        expected = Fraction(15, 8);
        CHECK(result == expected);
    }

    SUBCASE("Division operator")
    {
        Fraction frac1(3, 4);
        Fraction frac2(1, 2);
        Fraction result = frac1 / frac2;
        Fraction expected(3, 2);
        CHECK(result == expected);

        result = frac1 / 2;
        expected = Fraction(3, 8);
        CHECK(result == expected);

        result = frac1 / 2.5;
        expected = Fraction(3, 10);
        CHECK(result == expected);
    }
}
