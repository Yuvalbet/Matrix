#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "SquareMat.hpp" // ודא שהשם נכון בהתאם לקובץ שלך

TEST_CASE("בדיקות בנאי עם ערכים לא חוקיים") {
    CHECK_THROWS(MyMatrix::SquareMat(0));
    CHECK_THROWS(MyMatrix::SquareMat(-3));
}

TEST_CASE("בדיקות גישה לאינדקס שגוי") {
    MyMatrix::SquareMat m(3);
    CHECK_THROWS(m[-1]);
    CHECK_THROWS(m[3]);
}

TEST_CASE("בדיקת פעולות בין מטריצות בגודל שונה") {
    MyMatrix::SquareMat a(2), b(3);
    CHECK_THROWS(a + b);
    CHECK_THROWS(a - b);
    CHECK_THROWS(a * b);
    CHECK_THROWS(a % b);
}

TEST_CASE("בדיקת פעולות עם סקלר לא חוקי") {
    MyMatrix::SquareMat m(2);
    CHECK_THROWS(m / 0);
    CHECK_THROWS(m % 0);
}

TEST_CASE("בדיקת חזקה שלילית") {
    MyMatrix::SquareMat m(2);
    CHECK_THROWS(m ^ -2);
}

TEST_CASE("בדיקת דטרמיננטה על מטריצה ריקה") {
    CHECK_THROWS(MyMatrix::SquareMat(0));
    // אפשרות נוספת:
    // MyMatrix::SquareMat empty(0);
    // CHECK_THROWS(!empty);
}

TEST_CASE("בדיקת השוואות בין מטריצות בגדלים שונים") {
    MyMatrix::SquareMat a(2), b(3);
    CHECK_THROWS(a == b);
    CHECK_THROWS(a < b);
    CHECK_THROWS(a > b);
}
