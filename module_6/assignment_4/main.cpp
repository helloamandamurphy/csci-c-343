#include <iostream>
#include "src/Sequence.h"
#include "src/WordParser.h"

static bool isOpenSuccess(const std::ifstream &fileStream, const std::string& fileName) {
    if (!fileStream.is_open()) {
        std::cerr << "Error opening " << fileName << std::endl;
        return false;
    }
    return true;
}

static bool isOpenSuccess(WordParser& parser, const std::string& fileName) {
    if (!parser.openFile(fileName)) {
        std::cerr << "Error opening " << fileName << std::endl;
        return false;
    }
    return true;
}

static bool isValidCharacterRange(std::string dictionaryWord) {
    return dictionaryWord[0] >= 'a' && dictionaryWord[0] <= 'z';
}

static int getLetterIndex(char c) {
    // uses ASCII math to determine index value.
    // 'a' = 97, so 97-97 = 0
    // 'b' = 98, so 98-97 = 1, etc.
    return std::tolower(c) - 'a';
}

int main() {
    // Create a dictionary--26 Sequence objects (one for each letter of the alphabet)
    Sequence dictionary[26];

    // Load words from random_dictionary.txt
    std::string randomDictionary = "random_dictionary.txt";
    std::ifstream dictFile(randomDictionary);

    if (!isOpenSuccess(dictFile, randomDictionary)) {
        return 1;
    }

    // Load words into the dictionary by the first character.
    std::string dictionaryWord;
    while (dictFile >> dictionaryWord) {
        if (!dictionaryWord.empty() && isValidCharacterRange(dictionaryWord)) {
            int index = getLetterIndex(dictionaryWord[0]);
                dictionary[index].add(dictionaryWord);
        }
    }
    dictFile.close();
    std::cout << "Successfully loaded dictionary." << std::endl;

    // Open book file using the word parser
    WordParser bookParser;
    std::string bookFile = "oliver.txt";
    if (!isOpenSuccess(bookParser, bookFile)) {
        return 1;
    }

    // create counters for search
    long long comparisonsFound = 0;
    long long comparisonsNotFound = 0;
    long long wordsFound = 0;
    long long wordsNotFound = 0;

    std::string word;
    while (bookParser.getNextWord(word)) {
        if (word.empty() || !isValidCharacterRange(word)) {
            continue; // skip invalid words
        }

        int index = getLetterIndex(word[0]);
        int comparisons = dictionary[index].search(word);
        int seqLength = dictionary[index].getLength();

        // if comparisons == length, the word was not found
        if (comparisons == seqLength) {
            comparisonsNotFound += comparisons;
            ++wordsNotFound;
        }
        // if it was found
        else {
            comparisonsFound += comparisons;
            ++wordsFound;
        }
    }

    bookParser.closeFile();

    // Print out
    std::cout << "Words Found: " << wordsFound << std::endl;
    std::cout << "Words Not Found: " << wordsNotFound << std::endl;
    std::cout << "Total words: "  << (wordsFound + wordsNotFound) << std::endl;

    double averageCompsFound = comparisonsFound/wordsFound;
    std::cout << "Average Comparisons Found: " << averageCompsFound << std::endl;

    double averageCompsNotFound = comparisonsNotFound/wordsNotFound;
    std::cout << "Average Comparisons Not Found: " << averageCompsNotFound << std::endl;

    return 0;
}
