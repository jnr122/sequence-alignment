//
// Created by Jonah Rubin on 2019-01-24.
//

#ifndef SEQUENCE_ALIGNMENT_GRID_H
#define SEQUENCE_ALIGNMENT_GRID_H

#include "square.h"
#include <vector>
#include <string>

using namespace std;

class Grid {
private:
    string seq1;
    string seq2;
    vector<vector<Square>> cols;

    int gap_penalty;
    int mismatch_penalty;
    int match_bonus;

    /*
     * Creates grid of Squares from sequence input
     * Requires: nothing
     * Modifies: cols, the 2d vector of squares
     * Effects: generates actual grid
    */
    void populate();

    /*
     * Recursively traverses matrix, calculating scores
     * Requires: a starting index pair (i,j)
     * Modifies: cols, the 2d vector of squares
     * Effects: calculates and sets correct scores
    */
    int calculate(int i, int j);

    /*
     * Gets the max of 3 scores
     * Requires: 3 scores
     * Modifies: nothing
     * Effects: gives max
    */
    int get_max(int top, int left, int diag, int i, int j);

    /*
     * Calculates match score based on defined function
     * Requires: two strings
     * Modifies: nothing
     * Effects: returns calculated score
    */
    int get_match_score(char ch1, char ch2);


public:

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: grid
     * Effects: constructs default grid
    */
    Grid();

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: grid
     * Effects: constructs default grid
    */
    Grid(string s1, string s2, int gap_penalty, int mismatch_penalty, int match_bonus);

    /*
     * Getters
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns fields
     */
    string get_seq1();
    string get_seq2();
    int get_gap_penalty();
    int get_mismatch_penalty();
    int get_match_bonus();

    /*
     * Setters
     * Requires: nothing
     * Modifies: fields
     * Effects: sets field vars
     */
    void set_seq1(string seq1);
    void set_seq2(string seq2);
    void set_gap_penalty(int gap_penalty);
    void set_mismatch_penalty(int mismatch_penalty);
    void set_match_bonus(int match_bonus);

    /*
     * Formatted output
     * Requires: nothing
     * Modifies: nothings
     * Effects: generates grid from populate() for user to see
    */
    void print_grid();

};


#endif //SEQUENCE_ALIGNMENT_GRID_H
