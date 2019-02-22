//
// Created by Jonah Rubin on 2019-01-31.
//

#include "Sequence_pair.h"

#include <iostream>
#include <string>

// constructor
Sequence_pair::Sequence_pair(const string &seq1, const string &seq2)
                : seq1(validate_seq(seq1)), seq2(validate_seq(seq2)) {}

// destructor
Sequence_pair::~Sequence_pair() {

}

// validator
string Sequence_pair::validate_seq(string seq) {
    while (seq.length() < 1) {
        cout << "Sequence must be at least one character long: ";
        getline(cin, seq);
    }
    return seq;
}

void Sequence_pair::calculate_score(int match, int mismatch, int gap) {
    for (int i = 0; i < aligned1.length(); i++) {
        if (aligned1.at(i) == aligned2.at(i)) {
            score += match;
        } else if ((string(1, aligned1.at(i)) == "-") or (string(1, aligned2.at(i)) == "-")) {
            score += gap;
        } else {
            score += mismatch;
        }
    }
}

// getters
const string &Sequence_pair::get_seq1() const {
    return seq1;
}
const string &Sequence_pair::get_seq2() const {
    return seq2;
}
const string &Sequence_pair::get_aligned1() const {
    return aligned1;
}
const string &Sequence_pair::get_aligned2() const {
    return aligned2;
}
int Sequence_pair::get_score() const {
    return score;
}

// setters
void Sequence_pair::set_seq1(const string &seq1) {
    Sequence_pair::seq1 = seq1;
}
void Sequence_pair::set_seq2(const string &seq2) {
    Sequence_pair::seq2 = seq2;
}
void Sequence_pair::set_aligned1(const string &aligned1) {
    Sequence_pair::aligned1 = aligned1;
}
void Sequence_pair::set_aligned2(const string &aligned2) {
    Sequence_pair::aligned2 = aligned2;
}

// overloaded == operator
bool Sequence_pair::operator==(const Sequence_pair &sequence_pair) const {
    return seq1 == sequence_pair.seq1 &&
           seq2 == sequence_pair.seq2;
}

// overloaded << operator
ostream &operator<<(ostream &os, const Sequence_pair &sequence_pair) {
    os << "\nseq1: " << sequence_pair.seq1 << "\nseq2: " << sequence_pair.seq2 << "\n\naligned1: "
       << sequence_pair.aligned1  << "\naligned2: " << sequence_pair.aligned2
       << "\n\nOverall score: " << sequence_pair.score;
    return os;
}

