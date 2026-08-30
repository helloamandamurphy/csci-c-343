// This is the interface class, which uses SqrMatrix.h logic
#include "SqrMatrix.h"
#include <iostream>
#include <iomanip>

// Constructor with no parameters, default size to 1
SqrMatrix::SqrMatrix() {
    size = 1;
    sq = nullptr;
}

// Constructor with integer input of N, set size to N
SqrMatrix::SqrMatrix(const int N) {
    size = N;
    // Square Matrix of arrays (video example)
    sq = new int* [N];
    for (int i = 0; i < N; i++) {
        sq[i] = new int[N];
    }
}

std::ostream& operator << (std::ostream& out, const SqrMatrix* matrix){
    // Instead of N, trying to use matrix->size
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
        std::cout << "Enter " << matrix->size << " values for the row." << i << std::endl;
        for (int j = 0; j < matrix->size; j++) {
            in >> matrix->sq[i][j];
        }
        // in <<std::endl;
    }
    return in;
}

// SqrMatrix* (return type)
// SqrMatrix::operator * (the multiplication operator we are overloading)
// SqrMatrix* smPtrB (accepts a parameter of a pointer to a SqrMatrix called smPtrB)
SqrMatrix* SqrMatrix::operator * ( SqrMatrix* smPtrB) {
    int i, j, k;
    // create m3 SqrMatrix of size N, pointer m3
    SqrMatrix* m3;
    m3 = new SqrMatrix(size);
    for(i = 0; i < size; ++i)
        for(j = 0; j < size; ++j)
            for(k = 0; k < size; ++k) {
                m3->sq[i][j] += sq[i][k] * smPtrB-> sq[k][j];
            }
    return m3;
}

int SqrMatrix::getElement(int i, int j){
    return sq[i][j];
}

void SqrMatrix::putElement(int val, int i, int j){
    sq[i][j] = val;
}


