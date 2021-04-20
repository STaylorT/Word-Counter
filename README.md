# Word-Counter
# Author: Taylor Thomas
This program takes in a file, reads words in, counts the number of occurrences for each word, then outputs the words and their # of occurrences.

Takes text file from standard input, parses words (removing unwanted punctuation) individually, then places each unique word (key) into a hash table. when keys match, the value associated is incremented.

After being inserted, the array of hash elements is sorted via quickSort partition method. one quickSort sorts the hashtable by key, lexigraphically; the other sorts by value, highest to lowest number.

