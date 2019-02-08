//
// Created by Jonah Rubin on 2019-01-24.
//

#include "square.h"

using namespace std;

Square::Square() : score(0),
                   top_path(false),
                   left_path(false),
                   diag_path(false),
                   active(false) {}

Square::Square(int score, bool top_path, bool left_path, bool diag_path, bool active) : score(score),
                                                                                        top_path(top_path),
                                                                                        left_path(left_path),
                                                                                        diag_path(diag_path),
                                                                                        active(active) {}
// destructor
Square::~Square() {

}

// getters
int Square::get_score() const {
    return score;
}

bool Square::is_top_path() const {
    return top_path;
}

bool Square::is_left_path() const {
    return left_path;
}
bool Square::is_diag_path() const {
    return diag_path;
}

bool Square::is_active() const {
    return active;
}

// setters
void Square::set_score(int score) {
    Square::score = score;
    active = true;
}

void Square::set_top_path(bool top_path) {
    Square::top_path = top_path;
}

void Square::set_left_path(bool left_path) {
    Square::left_path = left_path;
}

void Square::set_diag_path(bool diag_path) {
    Square::diag_path = diag_path;
}

void Square::set_active(bool active) {
    Square::active = active;
}