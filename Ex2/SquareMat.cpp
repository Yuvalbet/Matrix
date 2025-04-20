#include "SquareMat.hpp"
#include <iostream> 

using namespace MyMatrix;
using namespace std;//במקום לכתוב כל פעם STD

// Constructor – Allocates 2D dynamic array
SquareMat::SquareMat(int n) {
    if (n <= 0) throw "Invalid matrix size"; // בדיקת קלט

    size = n;

    // מקצה מערך של מצביעים (שורות)
    data = new double*[size];

    // עבור כל שורה – הקצה עמודות ואתחל באפס
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0; // אתחול כל האיברים ל־0
        }
    }
}

// Copy Constructor – Deep copy
SquareMat::SquareMat(const SquareMat& other) {
    size = other.size;

    // הקצאת מערך חדש בגודל זהה
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j]; // העתקת ערכים
        }
    }
}

// Destructor – Frees memory
SquareMat::~SquareMat() {
    for (int i = 0; i < size; ++i) {
        delete[] data[i]; // שחרור כל שורה
    }
    delete[] data; // שחרור המערך של השורות
}

// Helper Function – Prints the matrix
void SquareMat::print() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << data[i][j] << " "; // הדפסת ערך
        }
        cout << endl;
    }
}

// Operator []
double* SquareMat::operator[](int i) {
    if (i < 0 || i >= size)
        throw "Row index out of bounds";
    return data[i];
}

const double* SquareMat::operator[](int i) const {
    if (i < 0 || i >= size)
        throw "Row index out of bounds";
    return data[i];
}


// Operator + : Matrix Addition
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw "Cannot add matrices of different sizes";
    }

    // Create new matrix to store result
    SquareMat result(size);

    // Add each element
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }

    return result;
}

// Operator - : Matrix Subtraction
SquareMat SquareMat::operator-(const SquareMat& other) const {
    if (size != other.size) {
        throw "Cannot subtract matrices of different sizes";
    }

    // Create new matrix to store result
    SquareMat result(size);

    // Subtract each element
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }

    return result;
}

// Operator - : Unary minus (change the sign of each element)
SquareMat SquareMat::operator-() const {
    // Create new matrix to store result
    SquareMat result(size);

    // Change the sign of each element
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = -data[i][j];
        }
    }

    return result;
}

// Operator * : Matrix Multiplication
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw "Cannot multiply matrices of different sizes";
    }

    // Create new matrix to store the result
    SquareMat result(size);

    // Perform matrix multiplication
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}



