//
// Created by Amanda Murphy on 11/21/26.
//

#ifndef ASSIGNMENT_5_AVLTREE_H
#define ASSIGNMENT_5_AVLTREE_H

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

    private:
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
