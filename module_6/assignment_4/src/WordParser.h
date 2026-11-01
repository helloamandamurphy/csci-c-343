//
// Created by Amanda Murphy on 10/31/26.
//

#ifndef ASSIGNMENT_4_WORDPARSER_H
#define ASSIGNMENT_4_WORDPARSER_H
#pragma once
#include <string>
#include <fstream>

class WordParser {
    //private by default
    std::ifstream file;
public:
    // Constructor
    WordParser();
    // Deconstructor
    ~WordParser();

    // open a file
    bool openFile(const std::string& filename);

    // close a file
    void closeFile();
};


#endif //ASSIGNMENT_4_WORDPARSER_H
