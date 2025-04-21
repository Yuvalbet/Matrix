#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace MyMatrix;

int main() {
    try {
        SquareMat a(2), b(2);

        // Fill matrix A
        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        // Fill matrix B
        b[0][0] = 5; b[0][1] = 6;
        b[1][0] = 7; b[1][1] = 8;

        cout << "Matrix A:" << endl;
        a.print();

        cout << "Matrix B:" << endl;
        b.print();

        // Matrix addition
        SquareMat c = a + b;
        cout << "A + B:" << endl;
        c.print();

        // Matrix subtraction
        SquareMat d = a - b;
        cout << "A - B:" << endl;
        d.print();

        // Unary minus
        SquareMat e = -a;
        cout << "-A:" << endl;
        e.print();

        // Matrix multiplication
        SquareMat f = a * b;
        cout << "A * B:" << endl;
        f.print();

        // Matrix * scalar
        SquareMat g = a * 2.0;
        cout << "A * 2.0:" << endl;
        g.print();

        // Scalar * matrix
        SquareMat h = 3.0 * b;
        cout << "3.0 * B:" << endl;
        h.print();

        // Element-wise multiplication
        SquareMat i = a % b;
        cout << "A % B (element-wise multiplication):" << endl;
        i.print();

        // Modulo with scalar
        SquareMat j = b % 5;
        cout << "B % 5 (element-wise modulo):" << endl;
        j.print();

        // Scalar division: A / 2.0
        SquareMat k = a / 2.0;
        cout << "A / 2.0:" << endl;
        k.print();
        
       



    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
