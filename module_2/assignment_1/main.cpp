#include <iostream>
#include "src/Sequence.cpp"

int main() {
    // make seq
    auto seq = std::make_unique<Sequence<int>>();
    int v1 = 37;
    int v2 = 29;
    int v3 = 52;

    //test add
    seq->add(v1, 0);
    seq->add(v2, 0);
    seq->add(v3, 0);

    std::cout << "Sequence: " << seq->outputSequence() << std::endl; // exp: 37 29 52

    // make seq1
    auto seq1 = std::make_unique<Sequence<std::string>>();
    std::string value = "fish";
    std::string value2 = "sun";
    std::string value3 = "cat";
    std::string value4 = "dog";

    seq1->add(value, 0);
    seq1->add(value2, 1);
    seq1->add(value3, 2);
    seq1->add(value4, 3);

    std::cout << "Sequence 1: " << seq1->outputSequence() << std::endl; // exp: fish sun cat dog
    std::cout << "Entry 1: " << seq1->entry(1).value_or("") << std::endl; // exp: sun
    std::cout << "Length: " << seq1->length()<< std::endl; // exp: 4

    //test remove using seq1
    int removed = 5; // this value will be overwritten by whatever the removed value is
    seq->remove(removed, 0);
    std::cout << "Sequence after remove(): " << seq->outputSequence() << std::endl;
    std::cout << "Removed: " << removed << std::endl;
    std::cout << "Length: " << seq->length()<< std::endl;

    auto seq2 = std::make_unique<Sequence<int>>();
    auto seq3 = std::make_unique<Sequence<int>>();
     v1 = 5;
     v2 = 4;
     v3 = 6;

    //test transferFrom with seq2 and seq3
    seq2->add(v1, 0);
    seq2->add(v2, 1);
    seq2->add(v3, 2);
    seq3->transferFrom(*seq2);
    std::cout << "Sequence 2: " << seq2->outputSequence() << std::endl; // exp: 5 4 6
    std::cout << "Sequence 3: " << seq3->outputSequence() << std::endl; // exp: 5 4 6

    // make seq4 and seq5
    Sequence<int> seq4;
    Sequence<int> seq5;
    v1 = 5;
    v2 = 4;
    v3 = 6;

    //test equals operator with seq4 and seq5
    seq4.add(v1, 0);
    seq4.add(v2, 1);
    // seq5.add(v3,2);
    seq5.add(v3, 0); // changed position 2 to position 0 because this was breaking things since seq5 was empty
    seq5 = seq4; //this gives an error if the operator= is not implemented.
    std::cout << "Sequence 4: " << seq4.outputSequence() << std::endl; // exp: 5 4
    std::cout << "Sequence 5: " << seq5.outputSequence() << std::endl; // exp 5 4

    return 0;
}