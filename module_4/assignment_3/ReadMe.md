# Assignment 3 Instructions (from Canvas)

Implementing a BumpList (List with two containers)

Implement a List data structure as discussed in Module 5 based on the Sequence class you have already developed in Programming Assignment #1. The container that holds elements of this List should be two Sequences (modeled by a string of T), one Sequence for the BumpList.left, and the other for the BumpList.right.

You should have the following source programs once you download the assignment from GitHub.

1. Sequence.h - header file containing the class declaration (function headers) of Sequence
2. Sequence.cpp - file containing function definitions  (implementation) of the Sequence class

You should replace the code in Sequence.cpp with the correct code you implemented in Programming Assignment #1.

-BumpList.h- header file containing the class declaration (function headers) of the BumpList class

-BumpList.cpp - file containing function definitions (implementation) of the BumpList class

You must write meaningful unit tests to test BumpList functions. Failure to implement your own meaningful unit tests will result in a 20% deduction.


# Amanda Notes
Running tests: 
```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
ctest --test-dir cmake-build-debug --output-on-failure

./cmake-build-debug/BumpListTests --success

```

## Note from Amanda
Submitting partially and will resubmit with the rest of the assignment later tonight
Submitting in the event I don't get back in time to finish it.