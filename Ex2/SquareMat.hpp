//Email: yuvali532@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <ostream>


namespace MyMatrix{
    
class SquareMat{
private:
    int size;
    double** data;

public:
    SquareMat(int n); //Constructor
    SquareMat(const SquareMat& other); //Copy constructor
    SquareMat& operator=(const SquareMat& other); //Copy assignment operator
    ~SquareMat(); //Destructor

    
    // Get matrix size
    int getSize() const;

    // Access row (for mat[i][j] syntax)
    double* operator[](int i);
    const double* operator[](int i) const;

    // Operator + : Adds two matrices element by element.
    SquareMat operator+(const SquareMat& other) const;

    // Operator - : Subtracts two matrices element by element.
    SquareMat operator-(const SquareMat& other) const;

    // Operator - : Unary minus (changes the sign of each element)
    SquareMat operator-() const;

    // Operator * : Multiplies two matrices by definition of matrix multiplication
    SquareMat operator*(const SquareMat& other) const;

    // Scalar multiplication: scalar * matrix
    friend SquareMat operator*(double scalar, const SquareMat& mat);

    // Scalar multiplication: matrix * scalar
    SquareMat operator*(double scalar) const;

    // Element-wise multiplication
    SquareMat operator%(const SquareMat& other) const;

    // Modulo operation with scalar
    SquareMat operator%(int scalar) const;

    // scalar division (divide each element by scalar)
    SquareMat operator/(double scalar) const;

    // Raises the matrix to a power (matrix exponentiation)
    SquareMat operator^(int power) const;

    // Pre-increment (++mat)
    SquareMat& operator++();

    // Post-increment (mat++)
    SquareMat operator++(int);

    // Pre-decrement (--mat)
    SquareMat& operator--();

    // Post-decrement (mat--)
    SquareMat operator--(int);

    // Transpose operator: switches rows and columns
    SquareMat operator~() const;

    // Equality and inequality based on sum of elements
    bool operator==(const SquareMat& other) const;
    bool operator!=(const SquareMat& other) const;

    // Comparison operators based on sum of elements
    bool operator<(const SquareMat& other) const;
    bool operator<=(const SquareMat& other) const;
    bool operator>(const SquareMat& other) const;
    bool operator>=(const SquareMat& other) const;

    // Operator for calculating the determinant of the matrix
    double operator!() const;

    // Combined assignment operators
    SquareMat& operator+=(const SquareMat& other);
    SquareMat& operator-=(const SquareMat& other);
    SquareMat& operator*=(const SquareMat& other);
    SquareMat& operator*=(double scalar);
    SquareMat& operator/=(double scalar);
    SquareMat& operator%=(const SquareMat& other);
    SquareMat& operator%=(int scalar);


    friend std::ostream& operator<<(std::ostream& os, const SquareMat& mat);
 
};
   
}

#endif