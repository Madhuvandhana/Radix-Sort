# Radix Sort

The class random generator has been updated (random_generator.h and random generator.cpp) by a member function which generates random strings of up to a given length with characters between "a" and "z".


• char* random_string(int max, int& m)
The function picks a string length m at random in between 1 and max (1<=m<= max). The length m of the random string is stored in the second parameter. The function then allocates m + 1 characters. The first m characters (0......m-1) are chosen at random in between the characters "a" and "z". The m-th character is set to 0 in order to mark the end of the string.

# Radix sort with Insertion sort & Radix sort with Counting sort

Insertion sort algorithms for strings that sorts a given array of strings according to the character at position d.
A non-existing digit d is interpreted as a 0 in the sorting process.


