# Sequence Pair alignment 

Recursive dynamic algorithm to find the best possible alignment of two strings given a match, mismatch, and gap score. 

Currently supports: 
- Global position alignment using Needleman-Wunsch algorithm
https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm
- Linear gap penalties 

Component class: The Sequence Pair object is a component of a Grid object. This makes sense because the sequence pair 
determines the properties of the grid, so storing it in the grid allows it to be easily accessed 

Overloaded operators: Both the Sequence and Grid classes both contain overloaded equality and print operators. This makes
it easy to check equality of grids and sequences, and then print them to view the final calculations

Enum: In order to traceback the best possible alignment, each square holds the direction that leads to 
the square that gave it its best score, which allows the recursive calculation. There are only three possible
paths, so each square holds a direction enum: top, left, or diagonal

Struct: The grid object is a collection of squares, but because squares require no additional functionality, and only 
store information I decided to make squares structs instead of objects
