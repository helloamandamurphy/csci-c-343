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

    // this will be a mutation function
    SqrMatrix* operator * ( SqrMatrix* smPtrB);

    /**
     * Description: //TODO Fill out what this description is
     * @param i //TODO Fill out what this param is
     * @return j //TODO Fill out what this
     */

    // this will be a accessor function
    int getElement(int i, int j);

    /**
     * Description: //TODO Fill out what this description is
     * @param val //TODO Fill out what this param is
     * @param i //TODO Fill out what this param is
     * @return j //TODO Fill out what this
     */
    void putElement(int val, int i, int j);

};
#endif 
