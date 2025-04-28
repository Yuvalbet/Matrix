//Email: yuvali532@gmail.com

#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace MyMatrix;

int main() {
    
    cout << "==Initializing 2x2 matrices==\n";
    SquareMat a(2), b(2);

    // Fill matrix a
    a[0][0] = 1; a[0][1] = 2;
    a[1][0] = 3; a[1][1] = 4;

    // Fill matrix b
    b[0][0] = 5; b[0][1] = 6;
    b[1][0] = 7; b[1][1] = 8;

    cout << "Matrix a:\n" << a << "\n";
    cout << "Matrix b:\n" << b << "\n";
    
    cout << "Trying to access an index out of range:\n";
    try{
        a[5][6] = 6;
    }
    catch(const std::out_of_range& e){
        cerr << e.what() << "\n\n";
    }

    // Matrix addition
    SquareMat c = a + b;
    cout << "a + b:\n" << c << "\n";

    // Matrix subtraction
    SquareMat d = a - b;
    cout << "a - b:\n" << d << "\n";

    // Unary minus
    SquareMat e = -a;
    cout << "-a:\n" << e << "\n";

    // Matrix multiplication
    SquareMat f = a * b;
    cout << "a * b:\n" << f << "\n";

    // Matrix * scalar
    SquareMat g = a * 2.0;
    cout << "a * 2.0:\n" << g << "\n";

    // Scalar * matrix
    SquareMat h = 3.0 * b;
    cout << "3.0 * b:\n" << h << "\n";

    // Element-wise multiplication
    SquareMat i = a % b;
    cout << "a % b (element-wise multiplication):\n" << i << "\n";

    // Modulo with scalar
    SquareMat j = b % 5;
    cout << "b % 5 (element-wise modulo):\n" << j << "\n";

    // Scalar division: A / 2.0
    SquareMat k = a / 2.0;
    cout << "a / 2.0:\n" << k << "\n";
    
    // Matrix exponentiation (raising the matrix to a power)
    SquareMat l = a ^ 2;  // Raise matrix A to the power of 2
    cout << "a ^ 2:\n" << l << "\n";

    // Pre-increment
    ++a;
    cout << "++a:\n" << a << "\n";

    // Post-increment
    SquareMat tempA = a++;
    cout << "a++ (after post-increment):\n" << a << "\n";

    // Pre-decrement
    --b;
    cout << "--b:\n" << b << "\n";

    // Post-decrement
    SquareMat tempB = b--;
    cout << "b-- (after post-decrement):\n" << b << "\n";
    
    // Transpose of matrix A
    SquareMat m = ~a;
    cout << "~a (transpose of A):\n" << m << "\n";

    // Equality and inequality tests
    cout << "a == b?\n " << (a == b ? "true" : "false") << endl;
    cout << "a != b?\n " << (a != b ? "true" : "false") << endl;

    // Comparison tests
    cout << "a < b?\n " << (a < b ? "true" : "false") << endl;
    cout << "a > b?\n " << (a > b ? "true" : "false") << endl;
    cout << "a <= b?\n " << (a <= b ? "true" : "false") << endl;
    cout << "a >= b?\n " << (a >= b ? "true" : "false") << endl;

    // determinant
    cout << "Determinant of a:\n " << !a << endl;
    cout << "Determinant of b:\n " << !b << endl;

    // +=
    a += b;
    cout << "a += b:\n" << a << "\n";

    // -=
    a -= b;
    cout << "a -= b:\n" << a << "\n";

    // *= scalar
    a *= 2.0;
    cout << "a *= 2.0:\n" << a << "\n";

    // /= scalar
    a /= 2.0;
    cout << "a /= 2.0:\n" << a << "\n";

    // %= matrix (element-wise multiplication)
    a %= b;
    cout << "a %= b (element-wise):\n" << a << "\n";

    // %= scalar (modulo)
    b %= 5;
    cout << "b %= 5 (modulo):\n" << b << "\n";

    cout << "Printing matrix a with operator<<:\n" << a << "\n";

    cout << "Printing matrix b with operator<<:\n" << b << "\n";

    return 0;
}
