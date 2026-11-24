//
// Created by Amanda Murphy on 11/23/26.
//
#include <cassert>
#include <iostream>
#include <sstream>
#include "../src/AVLTree.h"


int main () {
    AVLTree<std::string> t;
    bool found;

    // Empty tree
    t.search("hello", found);
    assert(!found);

    // Sorted words
    const char* words[] = {"Amanda", "Barbara", "Cameron", "Douglas", "Edgar"};
    for (const char* w : words) {
        t.insert(w);
    }

    for (const char* w : words) {
        t.search(w, found);
        assert(found);
    }

    // Check tree height
    assert(t.treeHeight() == 2);

    // Can't find words not included
    t.search("Fredrick", found);
    assert(!found);

    t.search("Gustav", found);
    assert(!found);

    t.search("Helga", found);
    assert(!found);

    // Add two more
    t.insert("Fredrick");
    t.insert("Gustav");

    // Check tree height again
    assert(t.treeHeight() == 2);

    // Check balanced tree with seven nodes only takes three levels or two comparisons
    assert(t.search("Gustav", found) <= 6);

    std::cout << "All tests passed" << std::endl;
}
