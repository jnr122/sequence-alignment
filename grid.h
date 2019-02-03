//
// Created by Jonah Rubin on 2019-01-24.
//

#ifndef SEQUENCE_ALIGNMENT_GRID_H
#define SEQUENCE_ALIGNMENT_GRID_H

#include "square.h"
#include "sequence_pair.h"

#include <string>
#include <vector>
#include <ostream>

using namespace std;

class Grid {
private:
    Sequence_pair seqs;
    string seq1;
    string seq2;
    string aligned1;
    string aligned2;
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

    /*
     * Uses assembled grid to get optimal alignment
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns two aligned strings in a vector
    */
    string traceback(int i, int j, string seq);


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

    friend ostream &operator<<(ostream &os, const Grid &grid);

    virtual ~Grid();

    /*
     * Getters for field vars
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns field var
     */
    const string &get_seq1() const;
    const string &get_seq2() const;
    const string &get_aligned1() const;
    const string &get_aligned2() const;
    const vector<vector<Square>> &get_cols() const;
    int get_gap_penalty() const;
    int get_mismatch_penalty() const;
    int get_match_bonus() const;

    /*
     * Setters for field vars
     * Requires: new value
     * Modifies: field values
     * Effects: sets new value
    */
    void set_seq1(const string &seq1);
    void set_seq2(const string &seq2);
    void set_aligned1(const string &aligned1);
    void set_aligned2(const string &aligned2);
    void set_cols(const vector<vector<Square>> &cols);
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
