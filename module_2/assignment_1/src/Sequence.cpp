
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
    // TODO: Do we need to check if pos is valid?
    // 0 <= pos <= length()

    // Create new NodeRecord for with value x
    NodeRecord* newNode = new NodeRecord;
    newNode->value = x;

    // Set newNode's next value to NULL as a default; update later if the node is not the first/last element
    newNode->next = NULL;

    // 0: cat, 1: dog, 2: fish size = 3
    // add(bird, 3)
    // last element is equal to the size, because size is 1 greater than the highest index value.

    // if position is the first element of an existing Sequence with 0 < size
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    }

    // if position is in the middle of the existing Sequence
    if (pos < length()) {
        NodeRecord* current = head;
        int i = 0;
        while(i < pos-1) {
            current = current->next;
            i++;
        }
        // Set newNode's next value to the current element's next value
        newNode->next = current->next;
        // Set current element's value to the newNode
        current->next = newNode;
    }

    // Increase size to reflect a new Node has joined the Sequence
    ++size;

}

template<class T>
void Sequence<T>::remove(T &x, int pos) {
    // Todo: remove element at position pos and place it in x
}

template<class T>
std::optional<T> Sequence<T>::entry(int pos)  {
    NodeRecord* currentValue = head;

    // if position is greater than size, return nullopt and exit
    if (pos >= size) {
        return std::nullopt;
    }

    // iterate up through the currentValue to the correct index to get the value
    int i = 0;
    while (i < pos) {
        currentValue = currentValue->next;
        i++;
    }
    return currentValue->value;
}

template<class T>
int Sequence<T>::length() {
    return size;
}

template<class T>
std::string Sequence<T>::outputSequence() {
    std::stringstream ss;
    NodeRecord* current = head;
    while (current != NULL) {
        ss << current->value << " ";
        current = current->next;
    }
    return ss.str();

}

