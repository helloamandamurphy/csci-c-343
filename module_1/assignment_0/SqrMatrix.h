// Implementation file
#ifndef C343_ASSIGNMENT0_SQRMATRIX_H // If SQRMATRIX_H is not defined
#define C343_ASSIGNMENT0_SQRMATRIX_H // Define it as this
#include <iostream>

// Class definition
class SqrMatrix {

private: // think this is private by default so this doesn't change the access level

    /**
     * Description: Holds the size of the NxN matrix where size is analogous to N
     */
    int size;

    /**
     * Description: A pointer to a two dimensional array. This is equivalent to int * sq[]
     */
    int **sq;

public:
    // constructor
    SqrMatrix();

    /**
     * Description: Constructor that takes in the N for the N by N matrix with 0's.
     * @param N Number or rows and columns with the minimum integer value of 1.
     */
    explicit SqrMatrix(int N); // cannot initialize without a value since it's explicit

    // destructor (marked with ~) uses default so we don't have to write a custom destructor
    ~SqrMatrix() = default;

    /**
     * Description: Outputs all values through standard out.
     */
    // friend grants access to protected/private classes to classes or functions that don't belong to the class
    friend std::ostream& operator << (std::ostream& out, const SqrMatrix* matrix);

    /**
     * Description: Allows ints to be passed in to the matrix through standard in.
     */
    friend std::istream& operator >> (std::istream& in, SqrMatrix* matrix);

    /**
     * Description: multiplies this matrix by the incoming matrix.
     * @param smPtrB a matrix of the same size that will be multiplied by this matrix.
     * @return Returns a new SqrMatrix.
     */

    SqrMatrix* operator * ( SqrMatrix* smPtrB);

    /**
     * Description: Accessor function; returns the value at row i and column j
     * @param i row index, between 0 and N-1
     * @param j column index, between 0 and N-1
     * @return Returns the int stored at row i and column j
     */
    int getElement(int i, int j);

    /**
     * Description: mutator function; stores the provided integer value (val) at row i, column j
     * @param val integer to be inserted in the matrix
     * @param i row index, between 0 and N-1
     * @param j column index, between 0 and N-1
     * @return nothing, this is void
     */
    void putElement(int val, int i, int j);

};
#endif 
