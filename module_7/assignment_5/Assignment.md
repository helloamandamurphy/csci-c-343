# Assignment 5
## Assignment Details (from Canvas)
Read carefully first and then watch the lecture video in the Module.

In this assignment, you will implement a spell checker again, as in Programming Assignment #4. Using the randomized dictionary (random_dictionary.txt) given, read in the dictionary (words in the random_dictionary.txt file) into an array of 26 AVL Tree class objects, one for each letter of the alphabet. Thus, the first AVLTree would contain only those words starting with the letter 'a', while the last would contain only those words starting with the letter 'z'. Notice that all words are in lowercase. This is similar to a hash table but more inefficient since we are not hashing words with a hash function.

Then, you read in the book (oliver.txt) using a string parser that you wrote in the previous assignment. The book contains paragraphs of text. For example, "What do I mean by a man of family? - O, I'll give you a general idea of what I mean.  Let us give him a first-rate fit-out; it costs us nothing. It may cost us $19." is a paragraph from the book.  The parser should generate tokens or separate words from the book's content, such as "what, do, I, mean, by, a, man,... first, rate, fit, out, ...., cost, us." they should be proper alphabetical words and must be in lower case. Every time the parser generates a single token or a word, it should be searched in the dictionary and counted as a word found or not found. This prevents the program from storing all the words in a data structure and wasting space.

When the parser generates a token/word, we examine the first character of each word and traverse one of the 26 AVLTrees. Each word read from the book should be searched in the corresponding AVLTree. If it is not found, this word is either misspelled or not in the dictionary, then count it as a word not found. If the word is found, count it as a word found. You should also count the number of string comparisons done during the search. Maintain two counters for comparisons; one is for the number of comparisons for words found in the dictionary, and the other is for the number of comparisons for words not found in the dictionary. At the end of the program, compute and display the average number of string comparisons for words that were found and the words that were not found. (ex: average number of comparisons for words found = number of words found / total number of comparisons for words found, compute the average comparisons for words not found similarly).

AVGCOMPSFOUND = COMPSFOUND / WDFOUND

AVGCOMPSNOTFOUND = COMPSNOTFOUND / WDNOTFOUND

You should implement and TEST your AVLTree first. The code you need to AVL Tree can be found in your textbook (go through the IU eTexts(Unizin Engage) link in the left tab.  You only need the insert (including tree rotation to balance) and the search functions of the AVL Tree.

You are allowed to implement any other functions necessary in any of your programs as long as you justify in the comments why you need them. Once again, your search function in AVLTree should return the number of comparisons it performs to find or not find the word.



DO NOT use the C++ map or list template container in this assignment; you are required to build your data structure to store the dictionary. We do not store the words from the book!



## What to Turn in:
Cover page (page 1): a PDF file containing your name, assignment number, assignment title, and due date.

One-page synopsis (page 2): A PDF file describing the problem, the algorithms, the program design, results, and observations. Make sure to check spelling and grammar. The synopsis should be typed in Times New Roman style font with single spacing and a font size of 12.

Outputs: A single page containing a clear image of the output window. The image should show the counters for words found, words not found, the number of comparisons for words found, the number of comparisons for words not found, and the averages.

Source Program(s): Your C++ source code (.cpp, .h, .hpp files) or codes if you have multiple files (Not images or word documents of the programs).  All programs should be properly indented and commented on with proper comments.

Upload a single ZIP file with ALL  of the above via Canvas.