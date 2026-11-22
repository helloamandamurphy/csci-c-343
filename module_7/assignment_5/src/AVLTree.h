//
// Created by Amanda Murphy on 11/21/26.
//

#ifndef ASSIGNMENT_5_AVLTREE_H
#define ASSIGNMENT_5_AVLTREE_H
#include <algorithm>
#include <string>
#include "AvlNode.h"


template<typename Comparable>

class AVLTree {
// Using AVL Code from textbook as example
    public:
    // initializes AVLTree with a root that is a nullptr so it starts out empty
    // (different way of writing: AVLTree() = default; / AvlNode<Comparable> *root = nullptr;)
    AVLTree() : root{ nullptr } {}

    // Deconstructor
    ~AVLTree() {
        makeEmpty(root);
    }

    // public insert method
    void insert (const std::string & x) {
        insert(x, root);
    }

    // public search method, returns bool and updates counters
    int search(const Comparable & x, bool & found) const {
        return contains(x, root, found);
    }

    private:
    AvlNode<Comparable>* root;

    // From Figure 4.41
    // Returns the height of node t or -1 if nullpointer
    int height (AvlNode<Comparable> *t) const {
        // if t is a nullptr, return -1; if false, return the height of t
        return t  == nullptr ? -1 : t->height;
    }

    /**
     * From Figure 4.42
     * Internal method to insert into a subtree
     * x is the item to insert
     * t is the node that roots the subtree
     * Set the new root of the subtree.
    */
    void insert(const Comparable & x, AvlNode<Comparable> * & t) {
        if (t == nullptr) {
            t = new AvlNode<Comparable>{ x, nullptr, nullptr};
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
    void balance(AvlNode<Comparable> * & t) {
        if (t == nullptr) {
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

        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE) {
            if (height(t->right->right) >= height(t->right->left)) {
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
        }
        t->height = std::max(height(t->left), height(t->right)) + 1;

    }

    /**
     * From figure 4.44
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(AvlNode<Comparable>* & k2) { // reference to a pointer of unbalanced root k2
        AvlNode<Comparable> *k1 = k2->left; // saves temporary pointer (k1) to k2's left child
        k2->left = k1->right; // detaches k1's right subtree (Y from diagram) and reattaches it to k2 (as left child)
        k1->right = k2; // sets k2 as the right child of k1 (moves k1 up to the root position)
        k2->height = std::max(height(k2->left), height(k2->right)) + 1; // recalculates k2's height
        k1->height = std::max(height(k1->left), k2->height) + 1; // recalculates k1's height
        k2 = k1; // Updates incoming reference parameter k2 to point at k1 (now the root)
    }

    /**
     * Wrote without textbook reference
     * Rotate tree node with right child, update heights, then set new root
     */
    void rotateWithRightChild(AvlNode<Comparable> * & k1) {
        AvlNode<Comparable> *k2 = k1->right; // saves temporary pointer (k2) to k1's right child
        k1->right = k2->left; // detaches k2's left subtree and reattaches it as k1's right child
        k2->left = k1; // sets k1 as the left child of k2 (moves k2 up to the root position)
        k1->height = std::max(height(k1->left), height(k1->right)) + 1; // recalculates k1's height
        k2->height = std::max(height(k2->right), k1->height) + 1; // recalculates k2's height
        k1 = k2; // Updates incoming reference parameter to k1 to point at k2 (now the root)
    }

    /**
     * From figure 4.46
     * Double rotate binary tree node: first left child
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild(AvlNode<Comparable> * & k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    /** Wrote without textbook reference
     * Double rotate binary tree node: first right child
     * with its left child; then node k1 with new right child.
     * Update heights, then set new root.
     */
    void doubleWithRightChild(AvlNode<Comparable> * & k1) {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }

    int contains(const Comparable & x, AvlNode<Comparable> *t, bool & found) const {
        int comparisons = 0;
        while (t != nullptr) {
            comparisons++;
            if (x < t->word) {
                t = t->left;
            }
            else {
                comparisons++;
                if (t->word < x) {
                    t = t->right;
                }
                else {
                    found = true; // match
                    return comparisons;
                }
            }
        }
        found = false;
        return comparisons; // no match
    }


    // HELPERS

    // Helper function for the desconstructor--uses recursion to empty nodes and set to nullptr.
    void makeEmpty(AvlNode<Comparable> * & t) {
        if (t != nullptr) {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

};

#endif //ASSIGNMENT_5_AVLTREE_H
