// This is the interface class, which uses SqrMatrix.h logic
#include "SqrMatrix.h"
#include <iostream>
#include <iomanip>

// Constructor with no parameters, default size to 1
SqrMatrix::SqrMatrix() {
    // Matrix of arrays (example from video lecture)
    size = 1;
    sq = new int*[size]; // create a pointer to an array with a length of size
    for (int i = 0; i < size; i++) { // while i is < size
        sq[i] = new int[size]; // set the value of the pointer at index i to an array with the length of size.
        for (int j = 0; j < N; j++) {
            sq[i][j] = 0; // create a matrix of 0's before the user enters values
        }
    }
}

// Constructor with integer input of N, set size to N
SqrMatrix::SqrMatrix(const int N) {
    size = N;
    // Square Matrix of arrays (example from video lecture)
    sq = new int* [N];
    for (int i = 0; i < N; i++) {
        sq[i] = new int[N];
        for (int j = 0; j < N; j++) {
            sq[i][j] = 0; // create a matrix of 0's before the user enters values
        }
    }
}

std::ostream& operator << (std::ostream& out, const SqrMatrix* matrix){
    for (int i = 0; i < matrix->size; i++) {
        for (int j = 0; j < matrix->size; j++) {
            out << matrix->sq[i][j] << " ";
        }
        out <<std::endl;
    }
    return out;
}

std::istream& operator >> (std::istream& in, SqrMatrix* matrix){
    for (int i = 0; i < matrix->size; i++) {
        std::cout << "Enter " << matrix->size << " values for the row " << i << std::endl;
        for (int j = 0; j < matrix->size; j++) {
            in >> matrix->sq[i][j];
        }
    }
    return in;
}

// SqrMatrix* (return type)
// SqrMatrix::operator * (the multiplication operator we are overloading)
// SqrMatrix* smPtrB (accepts a parameter of a pointer to a SqrMatrix called smPtrB)
SqrMatrix* SqrMatrix::operator * ( SqrMatrix* smPtrB) {
    SqrMatrix* m3; // create pointer of m3
    m3 = new SqrMatrix(size); // set m3 value to a new SquareMatrix object with same size
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < size; ++j)
            for(int k = 0; k < size; ++k) {
                m3->sq[i][j] += sq[i][k] * smPtrB-> sq[k][j];
            }
    return m3;
}

int SqrMatrix::getElement(int i, int j){
    return sq[i][j]; // return the value at row i and column j
}

void SqrMatrix::putElement(int val, int i, int j){
    sq[i][j] = val; // set value of row i and column j
}


