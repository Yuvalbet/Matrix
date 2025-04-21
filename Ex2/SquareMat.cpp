#include "SquareMat.hpp"
#include <iostream> 
#include <cmath> // for fmod()


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
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];  // שחרור כל שורה
        }
        delete[] data;  // שחרור המערך של השורות
        data = nullptr;  // אתחול המצביע ל-nullptr
    }
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


//Matrix Addition
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

//Matrix Subtraction
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

//Unary minus (change the sign of each element)
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
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw "Cannot multiply matrices of different sizes";
    }

    SquareMat result(size);

    // Perform matrix multiplication
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = 0;  // אתחול התוצאה לשם ביצוע הכפל
            for (int k = 0; k < size; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

    cout << "Multiplication result:" << endl;
    result.print();  // הדפסת תוצאת הכפל
    return result;
}


//Matrix * scalar
SquareMat SquareMat::operator*(double scalar) const {
    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * scalar;
    return result;
}
//scalar * Matrix (outside the class, inside namespace)
namespace MyMatrix {

    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }
    
} // namespace MyMatrix

//Multiply terms between two matrices
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size)
        throw "Cannot apply % to matrices of different sizes";

    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * other.data[i][j];

    return result;
}

//For each element in the matrix, we model it with the scalar
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0)
        throw "Modulo by zero is not allowed";

    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = fmod(data[i][j], scalar); // use fmod for doubles

    return result;
}

//Scalar division (divide each element by scalar)
SquareMat SquareMat::operator/(double scalar) const {
    // Check for division by zero
    if (scalar == 0) {
        throw "Division by zero is not allowed";
    }

    SquareMat result(size); 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] / scalar;  // Divide each element by scalar
        }
    }

    return result;
}
