//
// Created by Jonah Rubin on 2019-01-24.
//

#include "grid.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>



#include <stdlib.h>


using namespace std;

// TODO: add destructor
Grid::Grid() {
    this->seq1 = "atgc";
    this->seq2 = "cgta";
    this->gap_penalty = -2;
    this->mismatch_penalty = -1;
    this->match_bonus = 1;
//    this->aligned1 = "";
//    this->aligned2 = "";

    populate();
}

// TODO: add error handling
Grid::Grid(string s1, string s2, int gap_penalty, int mismatch_penalty, int match_bonus) {
    this->seq1 = s1;
    this->seq2 = s2;
    this->gap_penalty = gap_penalty;
    this->mismatch_penalty = mismatch_penalty;
    this->match_bonus = match_bonus;
//    this->aligned1 = "";
//    this->aligned2 = "";

    populate();
}

// TODO: use references for getters and setters

// getters
string Grid::get_seq1() {
    return seq1;
}
string Grid::get_seq2() {
    return seq2;
}
int Grid::get_gap_penalty() {
    return gap_penalty;
}
int Grid::get_mismatch_penalty() {
    return mismatch_penalty;
}
int Grid::get_match_bonus() {
    return mismatch_penalty;
}

string Grid::get_aligned1() {
    return aligned1;
}

string Grid::get_aligned2() {
    return aligned2;
}

//setters
void Grid::set_seq1(string seq1) {
    this->seq1 = seq1;
}
void Grid::set_seq2(string seq2) {
    this->seq2 = seq2;
}
void Grid::set_gap_penalty(int gap_penalty) {
    this->gap_penalty = gap_penalty;
}
void Grid::set_mismatch_penalty(int mismatch_penalty) {
    this->mismatch_penalty = mismatch_penalty;
}
void Grid::set_match_bonus(int match_bonus){
    this->match_bonus = match_bonus;
}

// TODO: get rid of all the redundancies here
void Grid::populate() {
    // set up matrix with default values
    for (int i = 0; i <= seq2.size(); i++) {
        vector<Square> row;
        for (int j = 0; j <= seq1.size(); j++) {
            Square square;
            if (j == 0) {
                square = Square(i * gap_penalty);
            } else if (i == 0) {
                square = Square(j * gap_penalty);
            }

            row.push_back(square);
        }
        cols.push_back(row);
    }

    // definitely a better way to compute the last square
    cols[seq2.size()][seq1.size()].set_score(calculate(seq2.size(), seq1.size()));
    cols[seq2.size()][seq1.size()].set_score(calculate(seq2.size(), seq1.size()));

    aligned1 = traceback(seq2.size(), seq1.size(), seq1);
    aligned2 = traceback(seq2.size(), seq1.size(), seq2);

    reverse(aligned1.begin(), aligned1.end());
    reverse(aligned2.begin(), aligned2.end());
}


// TODO: get rid of all the redundancies here
int Grid::calculate(int i, int j) {
    int top, left, diag;

    // base case
    if (cols[i-1][j-1].is_active() and cols[i][j-1].is_active() and cols[i-1][j].is_active()) {
        top = cols[i-1][j].get_score() + gap_penalty;
        left = cols[i][j-1].get_score() + gap_penalty;
        diag = get_match_score(seq1.at(j-1), seq2.at(i-1)) + cols[i-1][j-1].get_score();
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

// TODO: get rid of all the redundancies here
string Grid::traceback(int i, int j, string seq) {
    string s;

    // base case
    if (i == 0 or j == 0){
        return "";
    }

    // move out diag so it doesn't need to be coded twice
    if (seq == seq1) {
        if (cols[i][j].get_top_path()) {
            return "-" + traceback(i-1, j, seq);
        } else if (cols[i][j].get_diag_path()) {
            return string(1, (seq.at(j-1))) + traceback(i-1, j-1, seq);
        } else {
            return string(1, (seq.at(j-1))) + traceback(i, j-1, seq);
        }
    } else {
        if (cols[i][j].get_top_path()) {
            return string(1, (seq.at(i-1))) + traceback(i-1, j, seq);
        } else if (cols[i][j].get_diag_path()) {
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

// TODO: get rid of all the redundancies here
int Grid::get_max(int top, int left, int diag, int i, int j) {
    // lots of redundancy here
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

// TODO: get rid of all the redundancies here
void Grid::print_grid() {
    cout << "  |\t\t  ";
    for (int i = 0; i < seq1.size(); i++) {
        cout << "  " << left << setw(5) << seq1[i];
    }

    cout << "\n";
    for (int i = 0; i < seq1.size(); i++) {
        cout << "----------";
    }
    cout << "\n";
    for (int i = 0; i < cols.size(); i++) {
        if (i > 0) {
            cout << right << setw(1) << seq2[i-1] << " ";
            cout << "|";
        } else {
            cout << "  |";
        }

        for (int j = 0; j < cols[0].size(); j++){
            cout << "  " << left << setw(5) << cols[i][j].get_score();
        }
        cout << "\n";
    }
}


