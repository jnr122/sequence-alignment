//
// Created by Jonah Rubin on 2019-01-24.
//

#include "grid.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <stdio.h>

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
    for (int j = 0; j < this->seq2.size(); j++) {
        vector<Square> row;
        for (int i = 0; i < this->seq1.size(); i++) {
            Square square;
            if (i == 0) {
                square = Square(j * this->gap_penalty);
            } else if (j == 0) {
                square = Square(i * this->gap_penalty);
            }

            row.push_back(square);
        }
        this->cols.push_back(row);
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

