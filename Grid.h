//
// Created by Jonah Rubin on 2019-01-24.
//

#ifndef SEQUENCE_ALIGNMENT_GRID_H
#define SEQUENCE_ALIGNMENT_GRID_H

#include "Sequence_pair.h"

#include <experimental/optional>
#include <vector>
#include <ostream>

enum paths {top_path, left_path, diag_path};

struct Square {

    // Square constructor
    Square(int score, paths path);

    // fields
    int score;
    paths path;

};

using experimental::optional;
typedef optional<Square> OptSquare;

class Grid {
private:
    Sequence_pair &seq_pair;
    vector<vector<OptSquare>> cols;
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
     * Constructor
     * Requires: sequence pair reference, gap penalty, mismatch penalty
     * Modifies: grid
     * Effects: constructs grid grid
    */
    Grid(Sequence_pair &seq_pair, int gap_penalty, int mismatch_penalty, int match_bonus);

    /*
     * Overloaded print method
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints formatted seq pair
    */
    friend ostream &operator<<(ostream &os, const Grid &grid);

    /*
     * Overloaded equality operator
     * Requires: nothing
     * Modifies: nothing
     * Effects: checks equality of two grids
    */
    bool operator==(const Grid &rhs) const;

    // destructor
    virtual ~Grid();

    /*
     * Getters for field vars
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns field var
    */
    Sequence_pair &get_seq_pair() const;
    const vector<vector<OptSquare>> &get_cols() const;
    int get_gap_penalty() const;
    int get_mismatch_penalty() const;
    int get_match_bonus() const;

    /*
     * Setters for field vars
     * Requires: new value
     * Modifies: field values
     * Effects: sets new value
    */
    void set_seq_pair(Sequence_pair &seq_pair);
    void set_cols(const vector<vector<OptSquare>> &cols);
    void set_gap_penalty(int gap_penalty);
    void set_mismatch_penalty(int mismatch_penalty);
    void set_match_bonus(int match_bonus);
};


#endif //SEQUENCE_ALIGNMENT_GRID_H
