//
// Created by Jonah Rubin on 2019-01-24.
//

#include "grid.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>



#include <stdlib.h>     /* srand, rand */


using namespace std;

Grid::Grid() {
    this->seq1 = "atgc";
    this->seq2 = "cgta";
    this->cols;
    this->gap_penalty = -2;
    this->mismatch_penalty = -1;
    this->match_bonus = 1;

    populate();
}

Grid::Grid(string s1, string s2, int gap_penalty, int mismatch_penalty, int match_bonus) {
    this->seq1 = s1;
    this->seq2 = s2;
    this->cols;
    this->gap_penalty = gap_penalty;
    this->mismatch_penalty = mismatch_penalty;
    this->match_bonus = match_bonus;

    populate();
}

// getters
string Grid::get_seq1() {
    return this->seq1;
}
string Grid::get_seq2() {
    return this->seq2;
}
int Grid::get_gap_penalty() {
    return this->gap_penalty;
}
int Grid::get_mismatch_penalty() {
    return this->mismatch_penalty;
}
int Grid::get_match_bonus() {
    return this->mismatch_penalty;
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

void Grid::populate() {
    for (int i = 0; i < this->seq2.size(); i++) {
        vector<Square> row;
        for (int j = 0; j < this->seq1.size(); j++) {
            Square square;
            if (j == 0) {
                square = Square(i * this->gap_penalty);
            } else if (i == 0) {
                square = Square(j * this->gap_penalty);
            }
//            int v1 = rand() % 100;
//            Square square = Square(v1);


            row.push_back(square);
        }
        this->cols.push_back(row);
    }

    calculate(this->seq2.size()-1, this->seq1.size()-1);

}

int Grid::calculate(int i, int j) {


//     base case
//     square above left and diag of ij are activated
    if (cols[i-1][j-1].is_active() and cols[i][j-1].is_active() and cols[i-1][j].is_active()) {
        int top, left, diag;

        diag = get_match_score(this->seq1.at(j), this->seq2.at(i));
//        cout << "******" << diag;

//        this->cols[i][j] = max();

        return 0;

    } else {
//        return ;
    }



}

int Grid::get_match_score(char ch1, char ch2) {
    if (ch1 == ch2) {
        return 1;
    }

    return 0;
}

int Grid::max(int top, int left, int diag, int i, int j) {

    if (top >= left)  {

        if (top >= diag) {
            this->cols[i][j].set_top_path(true);
            return top;
        } else {
            this->cols[i][j].set_diag_path(true);
            return diag;
        }

    } else {
        if (left >= diag) {
            this->cols[i][j].set_left_path(true);
            return left;
        } else {
            this->cols[i][j].set_diag_path(true);
            return diag;
        }
    }

}

void Grid::print_grid() {
    cout << "  |";
    for (int i = 0; i < this->seq1.size(); i++) {
        cout << "  " << left << setw(5) << this->seq1[i];
    }

    cout << "\n";
    for (int i = 0; i < this->seq1.size(); i++) {
        cout << "-------";
    }
    cout << "\n";
    for (int i = 0; i < this->cols.size(); i++) {
        cout << right << setw(1) << this->seq2[i] << " ";
        cout << "|";
        for (int j = 0; j < this->cols[0].size(); j++){
            cout << "  " << left << setw(5) << this->cols[i][j].get_score();
        }
        cout << "\n";
    }
}


