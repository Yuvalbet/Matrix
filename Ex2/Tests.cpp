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

// Test for division by zero
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

TEST_CASE("Matrix addition") {
    MyMatrix::SquareMat a(2), b(2); 
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = a + b;

    CHECK(c[0][0] == 6);
    CHECK(c[0][1] == 8);
    CHECK(c[1][0] == 10);
    CHECK(c[1][1] == 12);
}

TEST_CASE("Matrix subtraction") {
    MyMatrix::SquareMat a(2), b(2); 
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = a - b;

    CHECK(c[0][0] == -4);
    CHECK(c[0][1] == -4);
    CHECK(c[1][0] == -4);
    CHECK(c[1][1] == -4);
}

TEST_CASE("Unary minus") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat c = -a;

    CHECK(c[0][0] == -1);
    CHECK(c[0][1] == -2);
    CHECK(c[1][0] == -3);
    CHECK(c[1][1] == -4);
}

TEST_CASE("Matrix multiplication") {
    MyMatrix::SquareMat a(2), b(2); 
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = a * b;

    CHECK(c[0][0] == 19);
    CHECK(c[0][1] == 22);
    CHECK(c[1][0] == 43);
    CHECK(c[1][1] == 50);
}

TEST_CASE("Matrix * scalar") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat c = a * 2.0;

    CHECK(c[0][0] == 2);
    CHECK(c[0][1] == 4);
    CHECK(c[1][0] == 6);
    CHECK(c[1][1] == 8);
}

TEST_CASE("Scalar * matrix") {
    MyMatrix::SquareMat b(2);
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = 3.0 * b;

    CHECK(c[0][0] == 15);
    CHECK(c[0][1] == 18);
    CHECK(c[1][0] == 21);
    CHECK(c[1][1] == 24);
}

TEST_CASE("Element-wise multiplication") {
    MyMatrix::SquareMat a(2), b(2); 
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = a % b;

    CHECK(c[0][0] == 5);
    CHECK(c[0][1] == 12);
    CHECK(c[1][0] == 21);
    CHECK(c[1][1] == 32);
}


TEST_CASE("Modulo with scalar") {
    MyMatrix::SquareMat b(2);
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    MyMatrix::SquareMat c = b % 5;

    CHECK(c[0][0] == 0);
    CHECK(c[0][1] == 1);
    CHECK(c[1][0] == 2);
    CHECK(c[1][1] == 3);
}

TEST_CASE("Scalar division") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 10; a[0][1] = 20; a[1][0] = 30; a[1][1] = 40;

    MyMatrix::SquareMat c = a / 2.0;

    CHECK(c[0][0] == 5);
    CHECK(c[0][1] == 10);
    CHECK(c[1][0] == 15);
    CHECK(c[1][1] == 20);
}

TEST_CASE("Matrix exponentiation") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat c = a ^ 2;

    CHECK(c[0][0] == 7);
    CHECK(c[0][1] == 10);
    CHECK(c[1][0] == 15);
    CHECK(c[1][1] == 22);
}

TEST_CASE("Pre-increment") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    ++a;

    CHECK(a[0][0] == 2);
    CHECK(a[0][1] == 3);
    CHECK(a[1][0] == 4);
    CHECK(a[1][1] == 5);
}

TEST_CASE("Post-increment") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat tempA = a++;

    CHECK(tempA[0][0] == 1);
    CHECK(tempA[0][1] == 2);
    CHECK(tempA[1][0] == 3);
    CHECK(tempA[1][1] == 4);

    CHECK(a[0][0] == 2);
    CHECK(a[0][1] == 3);
    CHECK(a[1][0] == 4);
    CHECK(a[1][1] == 5);
}

TEST_CASE("Pre-decrement") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    --a;

    CHECK(a[0][0] == 0);
    CHECK(a[0][1] == 1);
    CHECK(a[1][0] == 2);
    CHECK(a[1][1] == 3);
}

TEST_CASE("Post-decrement") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat tempA = a--;

    CHECK(tempA[0][0] == 1);
    CHECK(tempA[0][1] == 2);
    CHECK(tempA[1][0] == 3);
    CHECK(tempA[1][1] == 4);

    CHECK(a[0][0] == 0);
    CHECK(a[0][1] == 1);
    CHECK(a[1][0] == 2);
    CHECK(a[1][1] == 3);
}

TEST_CASE("Transpose") {
    MyMatrix::SquareMat a(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;

    MyMatrix::SquareMat m = ~a;

    CHECK(m[0][0] == 1);
    CHECK(m[0][1] == 3);
    CHECK(m[1][0] == 2);
    CHECK(m[1][1] == 4);
}

TEST_CASE("Equality and inequality checks") {
    MyMatrix::SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 1; b[0][1] = 2; b[1][0] = 3; b[1][1] = 4;

    CHECK(a == b);
    CHECK_FALSE(a != b);
}

TEST_CASE("Combined assignment operators") {
    MyMatrix::SquareMat a(2), b(2);
    a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4;
    b[0][0] = 5; b[0][1] = 6; b[1][0] = 7; b[1][1] = 8;

    a += b;

    CHECK(a[0][0] == 6);  
    CHECK(a[0][1] == 8);  
    CHECK(a[1][0] == 10); 
    CHECK(a[1][1] == 12); 
}

TEST_CASE("Combined assignment operators (subtraction)") {
    MyMatrix::SquareMat a(2), b(2);
    a[0][0] = 5; a[0][1] = 6; a[1][0] = 7; a[1][1] = 8;
    b[0][0] = 1; b[0][1] = 2; b[1][0] = 3; b[1][1] = 4;

    a -= b;

    CHECK(a[0][0] == 4);  
    CHECK(a[0][1] == 4);  
    CHECK(a[1][0] == 4);  
    CHECK(a[1][1] == 4); 
}
