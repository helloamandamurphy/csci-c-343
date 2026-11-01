//
// Created by Amanda Murphy on 10/31/26.
//

#include "Sequence.h"

// Not writing this as a <template> because it is built for a specific purpose/type

// Constructor
Sequence::Sequence() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

Sequence::~Sequence() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}
