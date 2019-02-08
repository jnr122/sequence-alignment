# Sequence Pair alignment 

Recursive dynamic algorithm to find the best possible alignment of two strings given a match, mismatch, and gap score. 

Currently supports: 
- Global position alignment using Needleman-Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
- Linear gap penalties 

# Optionals

The Grid object now holds a vector of vector of optional square objects. 
This was a good use case for optionals because the grid is initialized to an almost empty 
matrix of default squares. 

The new function I declared uses the calculations from the Grid class, but belongs to the Sequence_pair
class. I put it in this class because various sequence types will have their own scoring system, 
so it made more sense to leave this up to the sequence class. 