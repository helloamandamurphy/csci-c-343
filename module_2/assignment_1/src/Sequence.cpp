
#include "Sequence.h"
#include <optional>
#include <string>
#include <sstream>

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

// clear() utilizes reclaimAllNodes, but also sets head and size to their defaults of NULL and 0
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

// Transfers values from source to temp Sequence
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

// Overloaded operator that sets lhs to rhs
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
        ++size;

        // Go through rest of nodes
        NodeRecord* destination = head;
        NodeRecord* source = rhs.head->next;

        while (source != NULL) {
            destination->next = new NodeRecord;
            destination = destination->next;

            destination->value = source->value;
            destination->next = NULL;
            ++size;

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
    if (pos < 0 || pos > length()) {
        std::cout << "Position out of bounds. Position=" + std::to_string(pos) + " is less than 0 or greater than Sequence size=" + std::to_string(size) << std::endl;
        return;
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
        return;
    }

    // Increase size to reflect a new Node has joined the Sequence
    ++size;

}

template<class T>
void Sequence<T>::remove(T &x, int pos) {

    // Check if position is valid
    if (pos < 0 || pos > length()-1) {
        std::cout << "Cannot remove from a position that does not exist";
        return;
    }

    // If the element is the only one in the Sequence, set the value to x and reclaimAllNodes()
    if (length() == 1) {
        x = head->value;
        clear();
        return;
    }

    NodeRecord* delete_node;
    // if position = 0, set head to the next element
    if (pos == 0) {
        delete_node = head;
        head = head->next;
    } else {
        NodeRecord* preceding = head;

        // iterate to the position before the remove position
        int i = 0;
        while (i < pos-1) {
            preceding = preceding->next;
            i++;
        }

        // Set delete_node to the next item after ahead
        delete_node = preceding->next;
        // Set the preceding item's next to the delete_node's next
        preceding->next = delete_node->next;
    }

    // Set delete_node to x
    x = delete_node->value;

    // Delete the delete_node
    delete delete_node;

    // Decrement size
    --size;
}

// Get value of position pos
template<class T>
std::optional<T> Sequence<T>::entry(int pos)  {
    NodeRecord* currentValue = head;

    // if position is greater than size, return nullopt and exit
    if (pos < 0 || pos >= size ) {
        std::cout << "Cannot retrieve value from a position that does not exist";
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

// Get length/size of the Sequence
template<class T>
int Sequence<T>::length() {
    return size;
}

// Print out the values of the Sequence
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

