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

int Sequence::getLength() const {
    return length;
}

void Sequence::add(const std::string& word) {
    // make new linked list node with the new word
    Node* newNode = new Node(word);

    // if the Sequence is empty (header is a nullptr), then set head/tail to newNode
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    // otherwise set the tail node's next value to the pointer to newNode
    // and set tail to the newNode
    else {
        tail->next = newNode;
        tail = newNode;
    }

    length++;
}
