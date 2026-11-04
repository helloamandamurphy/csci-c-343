//
// Created by Amanda Murphy on 10/31/26.
//

#include "WordParser.h"
// Constructor
WordParser::WordParser() {}

// Deconstructor
WordParser::~WordParser() {
    closeFile();
}

bool WordParser::openFile(const std::string& filename) {
    file.open(filename);
    return file.is_open();
}

void WordParser::closeFile() {
    if (file.is_open()) {
        file.close();
    }
}


// Helper--returns true if the character is a letter
bool WordParser::isLetter(char ch) const {
    return std::isalpha(ch);
}

// Helper--converts a character to lowercase
char WordParser::toLowerCase(char ch) const {
    return std::tolower(ch);
}


bool WordParser::getNextWord(std::string& word) {
    // resets word to an empty string so old characters don't linger
    word.clear();
    // ch is a local variable that holds a single character from the book file
    char ch;

    // skip anything that's not a letter character or the end of the file
    while (file.get(ch) && !isLetter(ch)) {
        // skip non alphabet characters
    }

    // if it hits the end of the file, return false
    // Checks if it's the end of the file, the word value is empty, and there's no letter character
    if (file.eof() && word.empty() && !isLetter(ch)) {
        // no more words to process--return false
        return false;
    }

    while (file) {
        if (isLetter(ch)) {
            // add characters to the word until it hits a space/non-letter character
            word += toLowerCase(ch);
        }
        else {
            // will catch any non-alphabetical characters
            break;
        }
        file.get(ch);
    }

    // returns true when a valid word was extracted or false if it hits the end of the file
    return !word.empty();

}