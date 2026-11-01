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