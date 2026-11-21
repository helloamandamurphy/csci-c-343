//
// Created by Amanda Murphy on 11/21/26.
//

#ifndef ASSIGNMENT_5_AVLTREE_H
#define ASSIGNMENT_5_AVLTREE_H
#include "AvlNode.h"

class AVLTree {
// Using AVL Code from textbook as example
    public:
    // initializes AVLTree with a root that is a nullptr so it starts out empty
    // (different way of writing: AVLTree() = default; / AvlNode *root = nullptr;)
    AVLTree() : root{ nullptr } {}

    // Deconstructor
    ~AVLTree() {
        makeEmpty(root);
    }

    // TODO Insert

    // TODO Search

    private:
    AvlNode* root;

    // From Figure 4.41
    int height (AvlNode* node) const {
        // if t is a nullptr, return -1; if false, return the height of t
        return t  == nullptr ? -1 : t->height;
    }
    
    static const int ALLOWED_IMBALANCE = 1;
    // HELPERS

    // Helper function for the desconstructor--uses recursion to empty nodes and set to nullptr.
    void makeEmpty(AvlNode * & t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }


};

#endif //ASSIGNMENT_5_AVLTREE_H
