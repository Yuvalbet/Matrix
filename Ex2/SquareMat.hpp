#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

namespace MyMatrix{
    
class SquareMat{
private:
    int size;
    double** data;

public:
    SquareMat(int n);
    SquareMat(const SquareMat& other);

    ~SquareMat();

    void print() const;
    
    // Get matrix size
    int getSize() const { return size; }

    // Access row (for mat[i][j] syntax)
    double* operator[](int i);
    const double* operator[](int i) const;

    // Operator + : Adds two matrices element by element.
    SquareMat operator+(const SquareMat& other) const;

    // Operator - : Subtracts two matrices element by element.
    SquareMat operator-(const SquareMat& other) const;

    // Operator - : Unary minus (changes the sign of each element)
    SquareMat operator-() const;

    // Operator * : Multiplies two matrices
    SquareMat operator*(const SquareMat& other) const;

};

}
#endif