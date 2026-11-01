//
// Created by Amanda Murphy on 10/31/26.
//

#ifndef UNTITLED_SEQUENCE_H
#define UNTITLED_SEQUENCE_H
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

    //TODO: Additional functions
};


#endif //UNTITLED_SEQUENCE_H
