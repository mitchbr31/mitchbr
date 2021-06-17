To compile the program, simply enter in a terminal:
make

Then, to execute the test script, enter:
./TestApp

*Note, there are three separate testing functions, one for each data structure.
In TestScript.c, commenting out a line will allow the user to edit which structure test to display.


This is a functional Hash Map data strucutre implementation in C. It uses a Dynamic Array and Linked List Structure as the base data structures.
Some functionality included in the Hash Map:

1. hashFunction: The function used to determine the index location for a Hash Node
2. initHashMap: Initializes an empty hash map
3. addHashNode: Adds a node into the hash map
4. containsHashNode: Checks if a key exists in the hash map
5. getHashNode: Retrieves the value of a node given the key
6. removeHashNode: Remove a node from the hash map
7. dispHashMap: Displays the contents of the hash map
8. freeHashMap: Frees the hash map contents from memory. Necessary to be executed at the end of a program
