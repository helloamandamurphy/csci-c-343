#include <iostream>
#include "src/Sequence.h"

int main() {
    // Test
    Sequence seq = Sequence();

    seq.add("cat");
    seq.add("dog");
    seq.add("rat");
    std::cout << "Length is: " << seq.getLength() << std::endl;

    return 0;
}
