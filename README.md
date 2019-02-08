# Sequence Pair alignment 

Recursive dynamic algorithm to find the best possible alignment of two strings given a match, mismatch, and gap score. 

Currently supports: 
- Global position alignment using Needleman-Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
- Linear gap penalties 

Example run:

Enter the first sequence: gattatgactgatggacgatcagatttagaccgtag

Enter the second sequence: aggagattcacagtattaagacaaaaata

seq1: gattatgactgatggacgatcagatttagaccgtag

seq2: aggagattcacagtattaagacaaaaata

aligned1: gattatgactgatggacgatcagatttagaccgtag

aligned2: -agga-gattcacagtat-taagacaaaaa---ta-

Overall score: -13

# Optionals

The Grid class now holds a vector of vector of optional square objects. 
This was a good use case for optionals because the grid is initialized to an almost empty 
matrix of default squares. 

# New function

The new function I declared calculate_score() uses the calculations from the Grid class, but belongs to the Sequence_pair
class. I put it in this class because various sequence types will have their own scoring system, 
so it made more sense to leave this up to the sequence class. I chose this function because even though
the program also creates an alignment and a grid, a final score is helpful for comparisons

# Testing
All of my test cases passed the first time around. The ones I added weren't originally included 
because I didn't think of the cases that would cause them until I was implementing the function