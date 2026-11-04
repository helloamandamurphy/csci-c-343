#include <iostream>
#include "src/Sequence.h"
#include "src/WordParser.h"

int main() {
    // Test
    Sequence seq = Sequence();

    seq.add("cat");
    seq.add("dog");
    seq.add("rat");
    std::cout << "Length is: " << seq.getLength() << std::endl;

    // Test open/close file
    WordParser parser;
    std::string testFile = "test_poem.txt";

    // test open
    std::cout << "Trying to open file: " << testFile << std::endl;
    if (!parser.openFile(testFile)) {
        std::cerr << "Failed to open file: " << testFile << std::endl;
    }
    else {
        std::cout << "Success!" << std::endl;
    }

    // test getNextWord
    std::string word;
    int count = 0;

    while (parser.getNextWord(word) && count < 10) {
        ++count;
        std::cout << word << std::endl;
    }

    // test file closing
    parser.closeFile();
    std::cout << "File closed" << std::endl;

    return 0;
}
