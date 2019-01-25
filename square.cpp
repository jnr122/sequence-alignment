//
// Created by Jonah Rubin on 2019-01-24.
//

#include "square.h"


using namespace std;

Square::Square() {
    this->score = 0;
    this->top_path = false;
    this->left_path = false;
    this->diag_path = false;
}

Square::Square(int score, bool top_path, bool left_path, bool diag_path) {
    this->score = score;
    this->top_path = top_path;
    this->left_path = left_path;
    this->diag_path = diag_path;
}

// getters
int Square::get_score() {
    return this->score;
}

bool Square::get_top_path() {
    return this->top_path;
}

bool Square::get_left_path() {
    return this->left_path;
}

bool Square::get_diag_path() {
    return this->diag_path;
}

// setters
void Square::set_score(int score) {
    this->score = score;
}

void Square::set_top_path(bool top_path) {
    this->top_path = top_path;
}

void Square::set_left_path(bool left_path) {
    this->left_path = left_path;
}

void Square::set_diag_path(bool diag_path) {
    this->diag_path = diag_path;
}

