
#include "Sequence.h"
#include <optional>
#include <string>
#include <sstream>
// !!!Do not use the following line!!!.
//using namespace std;
// This is a horrible practice and leads to invisible side effects.
// Instead, use the scope resolution operator :: to prefix std to the method.
// ex. std::cout

// Constructor
// Sequence is initialized with no parameters, head defaults to NULL and size to 0
template <class T>
Sequence<T>::Sequence ()
{
    head = NULL;
    size = 0;
}

// Deconstructor
// Utilizes custom desconstructor that calls reclaimAllNodes()
template <class T>
Sequence<T>::~Sequence ()
{
    reclaimAllNodes(head);
}

template <class T>
void Sequence<T>::clear ()
{
    reclaimAllNodes(head);
    head = NULL;
    size = 0;
}

// Destructor helper function
// Recursive function that takes initalP as a pass by reference
template <class T>
void Sequence<T>::reclaimAllNodes (NodeRecord*& initialP)
{
    if (initialP != NULL) { // if initialP is not NULL
        reclaimAllNodes(initialP->next); // recursively calls itself with the pointer of the next element of the sequence
        delete (initialP); // deletes node from memory and sets head to NULL
    }
}


template <class T>
void Sequence<T>::transferFrom(Sequence& source)
{
    //Nothing to do in this
    std::optional<T> temp;
    clear(); //clears self
    for (int i = 0; i < source.length(); i++)//traverses source
    {
        temp = source.entry(i);
        if(temp != std::nullopt) {
            add(temp.value(), length());//adds source elements to self
        }
    }
    source.clear();//clears source
}

template <class T>
Sequence<T>& Sequence<T>::operator=(const Sequence& rhs) {
   // Todo: must return a Sequence.
}


template<class T>
void Sequence<T>::add(T &x, int pos) {
    // Todo: Add x at position pos
}

template<class T>
void Sequence<T>::remove(T &x, int pos) {
    // Todo: remove element at position pos and place it in x
}

template<class T>
std::optional<T> Sequence<T>::entry(int pos)  {
    NodeRecord* currentValue = head;

    if (pos >= size) {
        return std::nullopt;
    }
    else {
        // Todo: Take the value at pos and return it. You will need to replace the return here.
        return std::nullopt;
    }

}

template<class T>
int Sequence<T>::length() {
    return size;
}

template<class T>
std::string Sequence<T>::outputSequence() {
    std::stringstream ss;
    //Todo: build a string(ss) with all the entries of the Sequence.
    //Use insertion operator (<<) to build the string.
    return ss.str();

}

