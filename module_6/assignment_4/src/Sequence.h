//
// Created by Amanda Murphy on 10/31/26.
//

#ifndef ASSIGNMENT_4_SEQUENCE_H
#define ASSIGNMENT_4_SEQUENCE_H
#pragma once
#include <string>
#include "Node.h"

class Sequence {
    // private by default
    Node* head;
    Node* tail;
    int length;
public:
    // Constructor
    Sequence();

    // Deconstructor
    ~Sequence();

    // Get Length
    int getLength() const;

    void add(const std::string& word); // see note on const in ReadMe under Lessons Learned

    int search(const std::string &word) const;
};


#endif //ASSIGNMENT_4_SEQUENCE_H
