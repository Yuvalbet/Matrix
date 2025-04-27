//Email: yuvali532@gmail.com

#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace MyMatrix;

int main() {
    try {
        SquareMat a(2), b(2);

        // Fill matrix a
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        // Fill matrix b
        b[0][0] = 5; b[0][1] = 6;
        b[1][0] = 7; b[1][1] = 8;

        cout << "Matrix a:" << endl;
        cout << a << endl;

        cout << "Matrix b:" << endl;
        cout << b << endl;

        // Matrix addition
        SquareMat c = a + b;
        cout << "a + b:" << endl;
        cout << c << endl;

        // Matrix subtraction
        SquareMat d = a - b;
        cout << "a - b:" << endl;
        cout << d << endl;

        // Unary minus
        SquareMat e = -a;
        cout << "-a:" << endl;
        cout << e << endl;

        // Matrix multiplication
        SquareMat f = a * b;
        cout << "a * b:" << endl;
        cout << f << endl;

        // Matrix * scalar
        SquareMat g = a * 2.0;
        cout << "a * 2.0:" << endl;
        cout << g << endl;

        // Scalar * matrix
        SquareMat h = 3.0 * b;
        cout << "3.0 * b:" << endl;
        cout << h << endl;

        // Element-wise multiplication
        SquareMat i = a % b;
        cout << "a % b (element-wise multiplication):" << endl;
        cout << i << endl;

        // Modulo with scalar
        SquareMat j = b % 5;
        cout << "b % 5 (element-wise modulo):" << endl;
        cout << j << endl;

        // Scalar division: A / 2.0
        SquareMat k = a / 2.0;
        cout << "a / 2.0:" << endl;
        cout << k << endl;
        
        // Matrix exponentiation (raising the matrix to a power)
        SquareMat l = a ^ 2;  // Raise matrix A to the power of 2
        cout << "a ^ 2:" << endl;
        cout << l << endl;

        // Pre-increment
        ++a;
        cout << "++a:" << endl;
        cout << a << endl;

        // Post-increment
        SquareMat tempA = a++;
        cout << "a++ (after post-increment):" << endl;
        cout << a << endl;
    
        // Pre-decrement
        --b;
        cout << "--b:" << endl;
        cout << b << endl;

        // Post-decrement
        SquareMat tempB = b--;
        cout << "b-- (after post-decrement):" << endl;
        cout << b << endl;
        
        // Transpose of matrix A
        SquareMat m = ~a;
        cout << "~a (transpose of A):" << endl;
        cout << m << endl;

        // Equality and inequality tests
        cout << "a == b? " << (a == b ? "true" : "false") << endl;
        cout << "a != b? " << (a != b ? "true" : "false") << endl;

        // Comparison tests
        cout << "a < b? " << (a < b ? "true" : "false") << endl;
        cout << "a > b? " << (a > b ? "true" : "false") << endl;
        cout << "a <= b? " << (a <= b ? "true" : "false") << endl;
        cout << "a >= b? " << (a >= b ? "true" : "false") << endl;

        // determinant
        cout << "Determinant of a: " << !a << endl;
        cout << "Determinant of b: " << !b << endl;

        // +=
        a += b;
        cout << "a += b:" << endl;
        cout << a << endl;

        // -=
        a -= b;
        cout << "a -= b:" << endl;
        cout << a << endl;

        // *= scalar
        a *= 2.0;
        cout << "a *= 2.0:" << endl;
        cout << a << endl;

        // /= scalar
        a /= 2.0;
        cout << "a /= 2.0:" << endl;
        cout << a << endl;

        // %= matrix (element-wise multiplication)
        a %= b;
        cout << "a %= b (element-wise):" << endl;
        cout << a << endl;

        // %= scalar (modulo)
        b %= 5;
        cout << "b %= 5 (modulo):" << endl;
        cout << b << endl;

        cout << "Printing matrix a with operator<<:" << endl;
        cout << a << endl;

        cout << "Printing matrix b with operator<<:" << endl;
        cout << b << endl;

    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
