
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
    // check if it's attempting to assign a sequence to itself
    if (this == &rhs) {
        return *this;
    }

    // Remove all values from current Sequence
    reclaimAllNodes(head);
    size = 0;

    // If right hand side (rhs) has nodes, copy them over to current (left hand side)
    if (rhs.head != NULL) {
        head = new NodeRecord;
        head->value = rhs.head->value;
        head->next = NULL;
        size++;

        // Go through rest of nodes
        NodeRecord* destination = head;
        NodeRecord* source = rhs.head->next;

        while (source != NULL) {
            destination->next = new NodeRecord;
            destination = destination->next;

            destination->value = source->value;
            destination->next = NULL;
            size++;

            source = source->next;
        }
    }

    return *this;

}


template<class T>
void Sequence<T>::add(T &x, int pos) {
    // Example of an existing Sequence (thinking about size vs. pos)
    // 0: cat, 1: dog, 2: fish , size = 3
    // add(bird, 3)
    // adding a new element to the end, pos is equal to the size, because size is 1 greater than the highest index value.

    // Check if position is valid
    if (pos > length()) {
        std::cout << "Position out of bounds. Position=" + std::to_string(pos) + " is greater than Sequence size=" + std::to_string(size) << std::endl;
    }

    // Create new NodeRecord for with value x
    NodeRecord* newNode = new NodeRecord;
    newNode->value = x;

    // Set newNode's next value to NULL as a default;
    // Set value of head later if the node is not the first in an empty Sequence or last element
    newNode->next = NULL;

    // if position is the first element of an existing Sequence with size > 0
    if (pos == 0) {
        newNode->next = head;
        head = newNode;
    }

    // if position is in an existing Sequence
    else if (pos <= length()) {
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

    else {
        std::cout << "You're in the else loop." << std::endl;
    }

    // Increase size to reflect a new Node has joined the Sequence
    ++size;

}

template<class T>
void Sequence<T>::remove(T &x, int pos) {
    // Todo: remove element at position pos and place it in x

    // Check if position is valid
    if (pos > length()-1) {
        std::cout << "Cannot remove from a position that does not exist";
    }

    // If the element is the only one in the Sequence, set the value to x and reclaimAllNodes()
    if (length() == 1) {
        NodeRecord* one_item_seq = head;
        reclaimAllNodes(one_item_seq);
    }

    else {
        NodeRecord* ahead = head;

        // iterate to the position ahead of the remove position
        int i = 0;
        while (i < pos-1) {
            ahead = ahead->next;
            i++;
        }

        NodeRecord* delete_node = ahead->next;

        // If the delete node is the last item in the list, set the item ahead of it to NULL
        if (delete_node->next == NULL) {
            x = delete_node->value;
            ahead->next = NULL;
        } else {
            // Set ahead's next value to the node behind the deleted node.
            NodeRecord* behind = delete_node->next;
            ahead->next = behind;
        }

        // Set delete_node to x
        x = delete_node;

        // Delete the delete_node
        delete delete_node;

    }

    // Decrement size
    --size;
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

