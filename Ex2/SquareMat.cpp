#include "SquareMat.hpp"
#include <iostream> 
#include <cmath> // for fmod()


using namespace MyMatrix;
using namespace std;

// Constructor – Allocates 2D dynamic array
SquareMat::SquareMat(int n) {
    if (n <= 0)
        throw std::invalid_argument("Matrix size must be positive.");

    size = n;
    data = new double*[size];

    // Initializes the entire matrix to zero
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = 0.0;
        }
    }
}


// Copy Constructor – Deep copy
SquareMat::SquareMat(const SquareMat& other) {
    size = other.size;

    // Reallocate the matrix with the same dimensions
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j]; 
        }
    }
}

// Assignment Operator
SquareMat& SquareMat::operator=(const SquareMat& other) {
    if (this == &other) {
        return *this;
    }

    // Free the memory of the current object
    for (int i = 0; i < size; ++i) {
        delete[] data[i];
    }
    delete[] data;

    // Allocate new memory and copy the values
    size = other.size;
    data = new double*[size];
    for (int i = 0; i < size; ++i) {
        data[i] = new double[size];
        for (int j = 0; j < size; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}


// Destructor – Frees memory
SquareMat::~SquareMat() {
    if (data != nullptr) {
        for (int i = 0; i < size; ++i) {
            delete[] data[i];
        }
        delete[] data; 
        data = nullptr; 
    }
}


// Helper Function – Prints the matrix
void SquareMat::print() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << data[i][j] << " "; 
        }
        cout << endl;
    }
}

// Operator []
double* SquareMat::operator[](int i) {
    // Check if the row index is in range
    if (i < 0 || i >= size) {
        throw std::out_of_range("Row index out of bounds");
    }    
    return data[i]; 
}

const double* SquareMat::operator[](int i) const {
    if (i < 0 || i >= size) {
        throw std::out_of_range("Row index out of bounds");
    } 
    return data[i];
}



//Matrix Addition
SquareMat SquareMat::operator+(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Cannot add matrices of different sizes");
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
        throw std::invalid_argument("Cannot subtract matrices of different sizes");
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

//Matrix multiplication
SquareMat SquareMat::operator*(const SquareMat& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Cannot multiply matrices of different sizes");
    }    

    SquareMat result(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0; 
            for (int k = 0; k < size; ++k) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }

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


//Multiply terms between two matrices
SquareMat SquareMat::operator%(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Cannot apply % to matrices of different sizes");

    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = data[i][j] * other.data[i][j];

    return result;   
}

//For each element in the matrix, we model it with the scalar
SquareMat SquareMat::operator%(int scalar) const {
    if (scalar == 0)
        throw std::invalid_argument("Modulo by zero is not allowed");

    SquareMat result(size);
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = fmod(data[i][j], scalar); 

    return result;
}

//Scalar division (divide each element by scalar)
SquareMat SquareMat::operator/(double scalar) const {
    // Check for division by zero
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    

    SquareMat result(size); 
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = data[i][j] / scalar;
        }
    }

    return result;
}


//Raise the matrix to a power
SquareMat SquareMat::operator^(int power) const {
    if (power < 0) {
        throw std::invalid_argument("Negative powers are not supported for matrix exponentiation");
    }    

    if (power == 0) {
        SquareMat identity(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                identity[i][j] = (i == j) ? 1.0 : 0.0; 
            }
        }
        return identity;
    }
    if (power==1){
        return *this;
    }

    SquareMat result=*this;

    for (int i = 1; i < power; ++i) {
        result = result * (*this);  
    }

    return result;
}

//pre increment
SquareMat& SquareMat::operator++() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] += 1.0;
    return *this;
}

//post increment
SquareMat SquareMat::operator++(int) {
    SquareMat temp = *this;  // save current state
    ++(*this);               // use pre-increment to apply
    return temp;
}

//pre decrement
SquareMat& SquareMat::operator--() {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] -= 1.0;
    return *this;
}

//post decrement
SquareMat SquareMat::operator--(int) {
    SquareMat temp = *this;
    --(*this);
    return temp;
}

// Transpose operator: returns a transposed matrix
SquareMat SquareMat::operator~() const {
    SquareMat result(size);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[j][i] = data[i][j];  // swap indices

    return result;
}

//Comparing matrix sums
bool SquareMat::operator==(const SquareMat& other) const {
    if (size != other.size)
        throw std::invalid_argument("Matrices must be of the same size.");

    double sum1 = 0, sum2 = 0;

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }

    return sum1 == sum2;
}


// Inequality operator (!=)
bool SquareMat::operator!=(const SquareMat& other) const {
    return !(*this == other);  // reuse ==
}

// Less than
bool SquareMat::operator<(const SquareMat& other) const {
    if (size != other.size) 
        throw std::invalid_argument("Cannot compare matrices of different sizes");

    double sum1 = 0, sum2 = 0;
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            sum1 += data[i][j];
            sum2 += other.data[i][j];
        }

    return sum1 < sum2;
}

// Less than or equal
bool SquareMat::operator<=(const SquareMat& other) const {
    return (*this < other) || (*this == other);
}

// Greater than
bool SquareMat::operator>(const SquareMat& other) const {
    return other < *this;
}

// Greater than or equal
bool SquareMat::operator>=(const SquareMat& other) const {
    return (*this > other) || (*this == other);
}

//determinant
double SquareMat::operator!() const {

    if (size == 0) {
        throw std::invalid_argument("Cannot calculate determinant of an empty matrix");
    }
    if (size == 1)
        return data[0][0];

    if (size == 2)
        return data[0][0]*data[1][1] - data[0][1]*data[1][0];

    double det = 0;
    double** minor = new double*[size - 1];

    for (int i = 0; i < size - 1; ++i)
        minor[i] = new double[size - 1];

    for (int col = 0; col < size; ++col) {
        // Build the minor matrix by skipping row 0 and column col
        for (int i = 1; i < size; ++i) {
            int mCol = 0;
            for (int j = 0; j < size; ++j) {
                if (j == col) continue;
                minor[i - 1][mCol++] = data[i][j];
            }
        }

        // Recursive call (inline)
        double minor_det = 0;
        if (size - 1 == 1) {
            minor_det = minor[0][0];
        } else if (size - 1 == 2) {
            minor_det = minor[0][0]*minor[1][1] - minor[0][1]*minor[1][0];
        } else {
            // build new SquareMat and call operator!() again
            SquareMat temp(size - 1);
            for (int i = 0; i < size - 1; ++i)
                for (int j = 0; j < size - 1; ++j)
                    temp[i][j] = minor[i][j];
            minor_det = !temp;
        }

        double sign = (col % 2 == 0) ? 1 : -1;
        det += sign * data[0][col] * minor_det;
    }

    for (int i = 0; i < size - 1; ++i)
        delete[] minor[i];
    delete[] minor;

    return det;
}

// Matrices connection and placement
SquareMat& SquareMat::operator+=(const SquareMat& other) {
    if (size != other.size) 
        throw std::invalid_argument("Matrix sizes must match for +=");

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] += other.data[i][j];
    return *this;
}

// Matrix Subtraction and Substitution
SquareMat& SquareMat::operator-=(const SquareMat& other) {
    if (size != other.size) 
        throw std::invalid_argument("Matrix sizes must match for -=");

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] -= other.data[i][j];
    return *this;
}

// Matrix multiplication and substitution
SquareMat& SquareMat::operator*=(const SquareMat& other) {
    if (size != other.size) 
        throw std::invalid_argument("Matrix sizes must match for *=");

    SquareMat result = *this * other; // Use existing operator*
    *this = result; // Update current matrix
    return *this;
}

// Scalar multiplication and substitution
SquareMat& SquareMat::operator*=(double scalar) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] *= scalar;
    return *this;
}

// Scalar division and substitution
SquareMat& SquareMat::operator/=(double scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] /= scalar;
    return *this;
}


// Multiplication and Substitution
SquareMat& SquareMat::operator%=(const SquareMat& other) {
    if (size != other.size) 
        throw std::invalid_argument("Matrix sizes must match for %=");

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] *= other.data[i][j];
    return *this;
}

// Scalar modulo and placement
SquareMat& SquareMat::operator%=(int scalar) {
    if (scalar == 0) throw "Modulo by zero";
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            data[i][j] = fmod(data[i][j], scalar);
    return *this;
}

namespace MyMatrix {

    //scalar * Matrix (outside the class, inside namespace)
    SquareMat operator*(double scalar, const SquareMat& mat) {
        return mat * scalar;
    }

    //Like the print() function
    std::ostream& operator<<(std::ostream& os, const SquareMat& mat) {
        for (int i = 0; i < mat.getSize(); ++i) {
            for (int j = 0; j < mat.getSize(); ++j) {
                os << mat[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
    
}
    




