#include "SqrMatrix.cpp"

int main(int argc, char *argv[])
{
    // This file is required to have code insights while working on your files and run google_test.
    // DO NOT WRITE ANY CODE IN THE FILE, CHANGE IT, OR DELETE IT!!!!

    int N;
    std::cout << "What size do you want your matrix?";
    std::cin >> N;

    SqrMatrix* m1;
    m1 = new SqrMatrix(N);
    std::cin>>m1;
    std::cout<<m1;

    SqrMatrix* m2;
    m2 = new SqrMatrix(N);
    std::cin>>m2;
    std::cout<<m2;

    SqrMatrix* m3 = *m1 * m2;
    std::cout<<m3;
    std::cout<<std::endl;

    return 0;
}
