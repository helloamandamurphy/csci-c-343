#include "BumpList.h"

// Constructor default
template<class T>
BumpList<T>::BumpList() = default;

// Deconstructor default
template<class T>
BumpList<T>::~BumpList() = default;

// Clear both sides
template<class T>
void BumpList<T>::clear() {
    right.clear();
    left.clear();
}

template<class T>
void BumpList<T>::transferFrom(BumpList &source) {
    left.transferFrom(source.left);
    right.transferFrom(source.right);
}

template<class T>
void BumpList<T>::advance() {
    if (right.length() == 0) {
        throw std::out_of_range("BumpList<T>::advance() called on empty right");
    }
    T x;
    right.remove(x, 0);
    left.add(x, left.length());
}

template<class T>
BumpList<T>& BumpList<T>::operator=(BumpList const& rhs) = default;

template<class T>
void BumpList<T>::moveToStart() {
    // TODO
}

template<class T>
void BumpList<T>::moveToFinish() {
    // TODO
}

template<class T>
void BumpList<T>::addRightFront(T &x) {
    right.add(x,0);
}

template<class T>
void BumpList<T>::removeRightFront(T &x) {
    if (right.length() == 0) {
        throw std::out_of_range("BumpList<T>::removeRightFront() called on empty right");
    }
    right.remove(x,0);
}


template<class T>
void BumpList<T>::replaceRightFront(T &x) {
    if (right.length() == 0) {
        throw std::out_of_range("BumpList<T>::replaceRightFront() called on empty right");
    }
    T startingFront;
    right.remove(startingFront, 0);
    right.add(x,0);
    x = startingFront;
}

template<class T>
void BumpList<T>::swapRights(BumpList &otherS) {
    // Return if swapping with self
    if (this == &otherS) {
        return;
    }

    // Create temporary Sequence to transfer right from
    Sequence<T> temp;
    temp.transferFrom(right); // lhs's right, otherS.right = rhs's right
    right.transferFrom(otherS.right);
    otherS.right.transferFrom(temp);
}

template<class T>
int BumpList<T>::leftLength() {
    return left.length();
}

template<class T>
int BumpList<T>::rightLength() {
    return right.length();
}


template<class T>
std::optional<T> BumpList<T>::rightFront() {
    return right.entry(0);
}

template<class T>
std::optional<int> BumpList<T>::find(T elementToFind) {
    // Check left side using .entry()
    for (int i = 0; i < left.length(); i++) {
        if (left.entry(i) == elementToFind) {
            return i;
        }
    }
    // Check right using .entry()
    for (int i = 0; i < right.length(); i++) {
        if (right.entry(i) == elementToFind) {
            // return the position from the left (left length + right index)
            return left.length() + i;
        }
    }

    // if it's not in either, return a nullopt
    return std::nullopt;
}

template<class T>
std::string BumpList<T>::outputBumpList() {
   return "<" + left.outputSequence() + ">, <" + right.outputSequence() + ">";
}


