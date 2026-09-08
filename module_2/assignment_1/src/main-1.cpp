#include <iostream>
#include "src/Sequence.cpp"
int main() {
    auto seq = std::make_unique<Sequence<int>>();
    int v1 = 37;
    int v2 = 29;
    int v3 = 52;
    //test add
    seq->add(v1, 0);
    seq->add(v2, 0);
    seq->add(v3, 0);

    //Todo: output sequence here.

    auto seq1 = std::make_unique<Sequence<std::string>>();
    std::string value = "fish";
    std::string value2 = "sun";
    std::string value3 = "cat";
    std::string value4 = "dog";
    //Todo: output sequence here.
    //Todo: output the entry at position 1 here.
    //Todo: output the length of seq1 here

    seq1->add(value, 0);
    seq1->add(value2, 1);
    seq1->add(value3, 2);
    seq1->add(value4, 3);
    //test remove using seq1
    int removed = 5;
    seq->remove(removed, 0);

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
    //Todo: output seq3 here. must be the same as seq2

    Sequence<int> seq4;
    Sequence<int> seq5 ;
    v1 = 5;
    v2 = 4;
    v3 = 6;
    //test transferFrom with seq2 and seq3
    seq4.add(v1, 0);
    seq4.add(v2, 1);
    seq5.add(v3, 2);
    seq5 = seq4; //this gives an error if the operator= is not implemented.
    //Todo: output seq3 here. must be the same as seq2


    return 0;
}