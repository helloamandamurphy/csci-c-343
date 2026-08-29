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
SqrMatrix::SqrMatrix(int N) {
    size = N;
    sq = nullptr;
}

std::ostream& operator << (std::ostream& out, const SqrMatrix* matrix){
    return out;
}

std::istream& operator >> (std::istream& in, SqrMatrix* matrix){
    return in;
}

SqrMatrix* SqrMatrix::operator * ( SqrMatrix* smPtrB){
    return new SqrMatrix(1);
}

int SqrMatrix::getElement(int i, int j){
    return 0;
}

void SqrMatrix::putElement(int val, int i, int j){
}


