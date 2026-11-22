//
// Created by Amanda Murphy on 10/31/26.
//

#ifndef ASSIGNMENT_5_NODE_H
#define ASSIGNMENT_5_NODE_H
#pragma once
#include <string>

// Assignment 4: Originally single linked list node
// Assignment 5 Update: Node for AVL Tree
template <typename Comparable>
struct AvlNode {
    std::string word;
    AvlNode* left;
    AvlNode* right;
    int height;

    // Copying constructor--takes an existing string variable and makes a copy of its characters in a new node
    // Use this when reading word from random_dictionary.txt and call tree.insert(dictWord) (TODO)
    AvlNode(const std::string& w, AvlNode* lt, AvlNode* rt, int h = 0) : word{ w }, left {lt}, right {rt}, height {h} {};

    // Move constructor--takes an rvalue ref string, and moves its character buffer into a node without allocating new memory/copying characters
    AvlNode(std::string&& w, AvlNode *lt, AvlNode *rt, int h = 0) : word {std::move(w)}, left {lt}, right {rt}, height {h} {};

};

#endif //ASSIGNMENT_5_NODE_H
