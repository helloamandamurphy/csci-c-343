# Assignment 4

## Assignment Details (from Canvas)
Read carefully first and then watch the lecture video in the Module.

In this assignment, you will implement a spell checker. Using the randomized dictionary (random_dictionary.txt) given in the list of files, read in the dictionary (words in the random_dictionary.txt) into an array of 26 Sequence class objects, one for each letter of the alphabet. Thus the first Sequence would contain only those words starting with the letter 'a', while the last would contain only those words starting with the letter 'z'. Notice that all words are in lowercase. This is similar to a hash table but more inefficient since we are not hashing words with a hash function.

Then, you read in the book (oliver.txt) using a string parser that you have to write. The book contains paragraphs of text. For example, "What do I mean by a man of family? - O, I'll give you a general idea of what I mean.  Let us give him a first-rate fit-out; it costs us nothing. It may cost us $19." is a paragraph from the book.  The parser should generate tokens or separate words from the book's content, such as "what, do, I, mean, by, a, man,... first, rate, fit, out, ...., cost, us." they should be proper alphabetical words and must be in lower case. Every time the parser generates a single token or a word, it should be searched in the dictionary and counted as a word found or not found. This prevents the program from storing all the words in a data structure and wasting space.

When the parser generates a token/word, we examine the first character of each word and traverse one of the 26 Sequences. Each word read from the book should be searched in the corresponding Sequence. If it is not found, this word is either misspelled or not in the dictionary, then count it as a word not found. If the word is found, count it as a word found. You should also count the number of string comparisons done during the search. Maintain two counters for comparisons, one is for the number of comparisons for words that are found in the dictionary, and the other is for the number of comparisons for words that were not found in the dictionary. At the end of the program, compute and display the average number of string comparisons for words that were found and the words that were not found. (ex: average number of comparisons for words found = number of words found / total number of comparisons for words found, compute the average comparisons for words not found similarly).

AVGCOMPSFOUND = COMPSFOUND / WDFOUND

AVGCOMPSNOTFOUND = COMPSNOTFOUND / WDNOTFOUND

You are allowed to implement any other functions you see necessary. You should implement a function in the Sequence class to search for a given word and return the number of comparisons it performs to find or not find the word. If the word is not found, this function should return the length of the Sequence, otherwise, it should return the number of comparisons to find the word.



DO NOT use the C++ map or list template container in this assignment; you are required to build your data structure to store the dictionary. We do not store the words from the book!


### Deliverables
What to Turn in:

**Cover page (page 1)**: a PDF file containing your name, assignment number, assignment title, and due date.

**One-page synopsis (page 2)**: A PDF file describing the problem, the algorithms, the program design, results, and observations. Make sure to check spelling and grammar. The synopsis should be typed in Times New Roman style font with single spacing and a font size of 12.

**Outputs**: A single page containing a clear image of the output window. The image should show the counters for words found, words not found, the number of comparisons for words found, the number of comparisons for words not found, and the averages.

**Source Program(s)**: Your C++ source code (.cpp, .h, .hpp files) or codes if you have multiple files (Not images or word documents of the programs).  All programs should be properly indented and commented on with proper comments.

Upload a single ZIP file with ALL  of the above via Canvas.

Acceptable results (you may not get the same results, but a variance of a few thousand is acceptable)

**Results and Observations**

• Words found: 937716

• Words not found: 54341

• Average comparisons for words found: 3558.92

• Average comparisons for words not found: 7371.01

## Amanda Notes (Thoughts on Approach)
- Random Dictionary is a text file of ~130,000 words.
  - We want to read it,
  - Store the words into an aray of 26 Sequence class objects (all a words in one, b words in another, etc. for all of the letters in the alphabet).
  - All words should be lowercase.
- Oliver is a text file from a book. We want to check how many of the words in Oliver are included in the dictionary text file.
  - Develop a string parser to read the book file
  - The parser should generate a single token or word
  - Each word should be checked against the dictionary sequence of the correct letter, to see if the word is included in the collection
  - Count how many words are included/not included in the dictionary
- Count number of string comparisons
  - Count how many strings were traversed for words found
  - Count how many strings were traversed for words not found
  - Calculate the average
- Sequence class needs one function to search for a word + return the number of comparisons to find/not find the word

Thoughts it may help to map A -> 0, B ->1, C-> 2, etc. for the first letter of the word (what we are doing for the dictionary), but creating subarrays for the second letter, third letter, etc. would limit the number of words to compare.

## Always forget this, so writing it down: 
```bash
mkdir build
cd build

cmake ..
cmake --build .

./assignment_4
```