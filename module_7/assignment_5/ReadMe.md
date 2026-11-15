# ReadMe

## About
This program ingests two files: random_dictionary.txt which contains a list of ~130,000 words, and another file which is the text from the book _Oliver Twist_ by Charles Dickens.
In Assignment 4, we were asked to create a “spell checker” that would store words into an array of 26 Sequence objects, based on the letter of the alphabet the words started with. As an example, all words starting with the letter a would go into the first element, b would go into the second element, and so on. We then needed to develop a string parser that would read the book file, generate one word at a time, and then check that word against the dictionary sequence for the correct starting letter to see if the word was included in the collection. We needed to return how many words were found or not found. To demonstrate how efficient (or inefficient) this approach was, we also needed to track how many strings were traversed for words found and not found, and calculate the average.

In Assignment 5, we are shifting from using Sequence objects to using AVL trees to accomplish the same thing to compare performance. Assignment instructions can be [found here](Assignment.md).

## Pre-requisites
- Install C++
- Install CMake

## How to run the program
```bash
mkdir build
cd build

cmake ..
cmake --build .

./assignment_5
```