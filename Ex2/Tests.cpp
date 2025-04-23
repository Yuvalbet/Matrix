#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "SquareMat.hpp" 

TEST_CASE("Constructor checks with invalid values") {
    CHECK_THROWS(MyMatrix::SquareMat(0));
    CHECK_THROWS(MyMatrix::SquareMat(-3));
}

TEST_CASE("Incorrect index access checks") {
    MyMatrix::SquareMat m(3);
    CHECK_THROWS(m[-1]);
    CHECK_THROWS(m[3]);
}

TEST_CASE("Testing operations between matrices of different sizes") {
    MyMatrix::SquareMat a(2), b(3);
    CHECK_THROWS(a + b);
    CHECK_THROWS(a - b);
    CHECK_THROWS(a * b);
    CHECK_THROWS(a % b);
}

TEST_CASE("Checking operations with an invalid scalar") {
    MyMatrix::SquareMat m(2);
    CHECK_THROWS(m / 0);
    CHECK_THROWS(m % 0);
}

TEST_CASE("Negative strength test") {
    MyMatrix::SquareMat m(2);
    CHECK_THROWS(m ^ -2);
}

TEST_CASE("Determinant test on an empty matrix") {
    CHECK_THROWS(MyMatrix::SquareMat(0));
}

TEST_CASE("Testing comparisons between matrices of different sizes") {
    MyMatrix::SquareMat a(2), b(3);
    CHECK_THROWS(a == b);
    CHECK_THROWS(a < b);
    CHECK_THROWS(a > b);
}
