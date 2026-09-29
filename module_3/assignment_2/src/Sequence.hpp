// Needs to be template class, given: typedef Sequence<EmployeeRecord> EmployeeSequence;
// Needs to have .add(r,0)
// Needs .outputSequence
// Also needs to have std::vector pointer to sort the records
// and able to call something like .get(index)

// Quick sort--is that built in or is that something I need to build?

#include <iostream> // for std::cout/endl
#include <stdexcept> // for out_of_range exception

template <class T>
class Sequence {
    int count;
    const int MAX_EMPLOYEES = 1001; // Array maximum set to the number of employees--1000 employees, adding 1 just in case
    T data[MAX_EMPLOYEES]; // Create dynamic array with max size of 1001

public:
    // Constructor
    Sequence() {
        count = 0;
    }

    // Deconstructor--using default
    ~Sequence() {}

    // Return size of array (real values added, not the max)
    int size() {
        return count;
    }

    // Add element x at position y, defaulting to position 0
    void add(T& element, int position = 0) {
        // Check if the count is larger than the size of the array
        if (this->size() >= MAX_EMPLOYEES) {
            throw std::out_of_range("Cannot add more than 1001 entries due to array size. ");
        }

        // Check if we are trying to insert the element in a position past the end of the current size
        if (position < 0 || position > this->size()) {
            throw std::out_of_range("You cannot insert at this position because it is out of bounds. ");
        }

        // Check if an element already exists at this position and shift everything behind it back one position

        // Set current to the last element in the array
        int current = this->size() - 1;

        // While current is larger than the position we are inserting at, shift each element up one index
        while (current >= position) {
            data[current + 1] = data[current];
            --current;
        }

        // Put specified element in at the specified position
        data[position] = element;

        // Increment the count up
        ++count;
    }

    // Uses overloaded << operator from EmployeeRecord.h
    void outputSequence() {
        for (int i = 0; i < this->size(); ++i) {
            std::cout << data[i] << std::endl;
        }
    }
};