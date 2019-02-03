//
// Created by Jonah Rubin on 2019-01-24.
//

#include "grid.h"
#include "sequence_pair.h"

#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

Grid::Grid(Sequence_pair &seq_pair, int gap_penalty = -2,int mismatch_penalty = -1, int match_bonus = 1): seq_pair(seq_pair),
                                                                                              gap_penalty(gap_penalty),
                                                                                              mismatch_penalty(
                                                                                                      mismatch_penalty),
                                                                                              match_bonus(
                                                                                                      match_bonus) {
    populate();
}

// destructor
Grid::~Grid() {

}

const vector<vector<Square>> &Grid::get_cols() const {
    return cols;
}
int Grid::get_gap_penalty() const {
    return gap_penalty;
}
int Grid::get_mismatch_penalty() const {
    return mismatch_penalty;
}
int Grid::get_match_bonus() const {
    return match_bonus;
}

void Grid::set_cols(const vector<vector<Square>> &cols) {
    Grid::cols = cols;
}
void Grid::set_gap_penalty(int gap_penalty) {
    Grid::gap_penalty = gap_penalty;
}
void Grid::set_mismatch_penalty(int mismatch_penalty) {
    Grid::mismatch_penalty = mismatch_penalty;
}
void Grid::set_match_bonus(int match_bonus) {
    Grid::match_bonus = match_bonus;
}

// TODO: get rid of all the redundancies here
void Grid::populate() {
    // set up matrix with default values
    for (int i = 0; i <= seq_pair.get_seq2().size(); i++) {
        vector<Square> row;
        for (int j = 0; j <= seq_pair.get_seq1().size(); j++) {
            Square square;
            if (j == 0) {
                square = Square(i * gap_penalty);
                square.set_top_path(true);
            } else if (i == 0) {
                square = Square(j * gap_penalty);
                square.set_left_path(true);
            }

            row.push_back(square);
        }
        cols.push_back(row);
    }
    // definitely a better way to compute the last square
    cols[seq_pair.get_seq2().size()][seq_pair.get_seq1().size()].set_score(calculate(seq_pair.get_seq2().size(), seq_pair.get_seq1().size()));
    cols[seq_pair.get_seq2().size()][seq_pair.get_seq1().size()].set_score(calculate(seq_pair.get_seq2().size(), seq_pair.get_seq1().size()));
    seq_pair.set_aligned1(traceback(seq_pair.get_seq2().size(), seq_pair.get_seq1().size(), seq_pair.get_seq1()));
    seq_pair.set_aligned2(traceback(seq_pair.get_seq2().size(), seq_pair.get_seq1().size(), seq_pair.get_seq2()));

//    seq_pair.set_aligned1(reverse(seq_pair.get_aligned1().begin(), seq_pair.get_aligned1().end()));
//    seq_pair.set_aligned2(reverse(seq_pair.get_aligned2().begin(), seq_pair.get_aligned2().end()));

}

int Grid::calculate(int i, int j) {
    int top, left, diag;

    // base case
    if (cols[i-1][j-1].is_active() and cols[i][j-1].is_active() and cols[i-1][j].is_active()) {
        top = cols[i-1][j].get_score() + gap_penalty;
        left = cols[i][j-1].get_score() + gap_penalty;
        diag = get_match_score(seq_pair.get_seq1().at(j-1), seq_pair.get_seq2().at(i-1)) + cols[i-1][j-1].get_score();
        return get_max(top, left, diag, i, j);

    } else {
        // recursive case
        if (i > 1 and j > 1)
            calculate(i - 1, j - 1);
        if (i > 1)
            calculate(i-1,j);
        if (j > 1)
            calculate(i,j-1);
        calculate(i, j);
    }
}

string Grid::traceback(int i, int j, string seq) {
    string s;

    // base case
    if ((i == 0 and j == 0)){
        return "";
    }

    // TODO: move out diagonal
    if (seq == seq_pair.get_seq1()) {
        if (cols[i][j].is_top_path()) {
            return "-" + traceback(i-1, j, seq);
        } else if (cols[i][j].is_diag_path()) {
            return string(1, (seq.at(j-1))) + traceback(i-1, j-1, seq);
        } else {
            return string(1, (seq.at(j-1))) + traceback(i, j-1, seq);
        }
    } else {
        if (cols[i][j].is_top_path()) {
            return string(1, (seq.at(i-1))) + traceback(i-1, j, seq);
        } else if (cols[i][j].is_diag_path()) {
            return string(1, (seq.at(i-1))) + traceback(i-1, j-1, seq);
        } else {
            return "-" + traceback(i, j-1, seq);
        }
    }

}

int Grid::get_match_score(char ch1, char ch2) {
    if (ch1 == ch2) {
        return match_bonus;
    }
    return mismatch_penalty;
}

int Grid::get_max(int top, int left, int diag, int i, int j) {
    // TODO: get rid of returns statements, move to bottom only need set_path, set_score once
    if (top >= left)  {
        if (top >= diag) {
            cols[i][j].set_top_path(true);
            cols[i][j].set_score(top);
            return top;
        } else {
            cols[i][j].set_diag_path(true);
            cols[i][j].set_score(diag);
            return diag;
        }
    } else {
        if (left >= diag) {
            cols[i][j].set_left_path(true);
            cols[i][j].set_score(left);
            return left;
        } else {
            cols[i][j].set_diag_path(true);
            cols[i][j].set_score(diag);
            return diag;
        }
    }
}

ostream &operator<<(ostream &os, const Grid &grid) {
    cout << "  |\t\t  ";
    for (int i = 0; i < grid.seq_pair.get_seq1().size(); i++) {
        cout << "  " << left << setw(5) << grid.seq_pair.get_seq1()[i];
    }

    cout << "\n";
    for (int i = 0; i < grid.seq_pair.get_seq1().size(); i++) {
        cout << "----------";
    }
    cout << "\n";
    for (int i = 0; i < grid.cols.size(); i++) {
        if (i > 0) {
            cout << right << setw(1) << grid.seq_pair.get_seq2()[i-1] << " ";
            cout << "|";
        } else {
            cout << "  |";
        }

        for (int j = 0; j < grid.cols[0].size(); j++){
            cout << "  " << left << setw(5) << grid.cols[i][j].get_score();
        }
        cout << "\n";
    }
}





