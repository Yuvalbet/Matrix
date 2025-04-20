#include <iostream>
#include "SquareMat.hpp"

using namespace std;
using namespace MyMatrix;

int main() {
    try {
        SquareMat a(2), b(2);

        a[0][0] = 1; a[0][1] = 2;
        a[1][0] = 3; a[1][1] = 4;

        b[0][0] = 5; b[0][1] = 6;
        b[1][0] = 7; b[1][1] = 8;

        cout << "Matrix A:" << endl;
        a.print();

        cout << "Matrix B:" << endl;
        b.print();

        SquareMat c = a + b;

        cout << "A + B:" << endl;
        c.print();

    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }

    return 0;
}
