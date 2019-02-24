# Sequence Pair alignment 


In order to run, have two sequences in an a file named "2.in" placed in the cmake-build-debug
directory. In order to use local alignment, comment out line 32 of main.cpp and uncomment line 35.
In order to use global, do the opposite. Then run main.cpp, and check cmake-build-debug for the new printed files.

Recursive dynamic algorithm to find the best possible alignment of two strings given a match, mismatch, and gap score. 

Currently supports: 
- Linear gap penalties 
- Global position alignment using Needleman-Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
- Local position alignment using Smith-Waterman algorithm 
https://en.wikipedia.org/wiki/Smith%E2%80%93Waterman_algorithm
