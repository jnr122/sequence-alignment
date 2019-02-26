//
// Created by Jonah Rubin on 2019-02-24.
//

#include "Grid.h"

#ifndef SEQUENCE_ALIGNMENT_LOCAL_GRID_H
#define SEQUENCE_ALIGNMENT_LOCAL_GRID_H


class Local_Grid : public Grid {
public:
    Local_Grid(Sequence_pair &seq_pair, int gap_penalty, int mismatch_penalty, int match_bonus);

    /*
     * Creates grid of Squares from sequence input
     * Requires: nothing
     * Modifies: cols, the 2d vector of squares
     * Effects: generates actual grid
    */
    void populate() override;

    /*
     * Gets the max of 3 scores
     * Requires: 3 scores
     * Modifies: nothing
     * Effects: gives max
    */
    int get_max(int top, int left, int diag, int i, int j) override;

    /*
     * Uses assembled grid to get optimal alignment
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns two aligned strings in a vector
    */
    string traceback(int i, int j, string seq) override;

};


#endif //SEQUENCE_ALIGNMENT_LOCAL_GRID_H
