//
// Created by Amanda Murphy on 10/31/26.
//

#ifndef ASSIGNMENT_4_NODE_H
#define ASSIGNMENT_4_NODE_H
#pragma once
#include <string>

// Using Linked List (following the example from the MIT lecture on hashing)
struct Node {
    std::string word;
    Node* next;

    // Constructor
    Node(const std::string& w) {
        word = w; // word = member variable vs. w = input parameter
        next = nullptr;
    }
};

#endif //ASSIGNMENT_4_NODE_H
