#ifndef C343_ASSIGNMENT0_SQRMATRIX_H
#define C343_ASSIGNMENT0_SQRMATRIX_H
#include <iostream>

class SqrMatrix {

private:

    /**
     * Description: Holds the size of the NxN matrix where size is analogous to N
     */
    int size;

    /**
     * Description: A pointer to a two dimensional array. This is equivalent to int * sq[]
     */
    int **sq;

public:

    SqrMatrix();

    /**
     * Description: Constructor that takes in the N for the N by N matrix with 0's.
     * @param N Number or rows and columns with the minimum integer value of 1.
     */
    explicit SqrMatrix(int N);

    ~SqrMatrix() = default;

    /**
     * Description: Outputs all values through standard out.
     */
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
     * Description: //TODO Fill out what this description is
     * @param i //TODO Fill out what this param is
     * @return j //TODO Fill out what this
     */
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
