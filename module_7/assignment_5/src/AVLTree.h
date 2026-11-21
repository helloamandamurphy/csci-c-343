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

    // public insert method
    void insert (const std::string & x) {
        insert(x, root);
    }

    // TODO Search

    private:
    AvlNode* root;

    // From Figure 4.41
    int height (AvlNode* node) const {
        // if t is a nullptr, return -1; if false, return the height of t
        return t  == nullptr ? -1 : t->height;
    }

    /**
    * Internal method to insert into a subtree
    * x is the item to insert
    * t is the node that roots the subtree
    * Set the new root of the subtree.
    */
    void insert(const Comparable & x, AvlNode * & t) {
        if (t == nullptr) {
            t = new AvlNode{ x, nullptr, nullptr};
        }
        else if (x < t->word) {
            insert(x, t->left);
        }
        else if (t->word < x) {
            insert(x, t->right);
        }

        balance(t);
    }

    static const int ALLOWED_IMBALANCE = 1;

    // From Figure 4.42
    // Assume t is balanced or within one of being balanced
    void balance(AvlNode * & t) {
        if (t== nullptr) {
            return;
        }

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE) {
            if (height(t->left->left) >= height(t->left->right)) {
                rotateWithLeftChild(t);
            }
            else {
                doubleWithLeftChild(t);
            }
        }

        else {
            if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
        t->height = max(height(t->left), height(t->right)) + 1

    }

    // TODO single+double right and left

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
