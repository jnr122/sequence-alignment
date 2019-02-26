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

// getters
const string &Sequence_pair::get_seq1() const {
    return seq1;
}
const string &Sequence_pair::get_seq2() const {
    return seq2;
}
const string &Sequence_pair::get_global_aligned1() const {
    return global_aligned1;
}
const string &Sequence_pair::get_global_aligned2() const {
    return global_aligned2;
}
const string &Sequence_pair::get_local_aligned1() const {
    return local_aligned1;
}
const string &Sequence_pair::get_local_aligned2() const {
    return local_aligned2;
}
int Sequence_pair::get_global_score() const {
    return global_score;
}
int Sequence_pair::get_local_score() const {
    return local_score;
}

// setters
void Sequence_pair::set_seq1(const string &seq1) {
    Sequence_pair::seq1 = seq1;
}
void Sequence_pair::set_seq2(const string &seq2) {
    Sequence_pair::seq2 = seq2;
}
void Sequence_pair::set_global_aligned1(const string &aligned1) {
    Sequence_pair::global_aligned1 = aligned1;
}
void Sequence_pair::set_global_aligned2(const string &aligned2) {
    Sequence_pair::global_aligned2 = aligned2;
}
void Sequence_pair::set_local_aligned1(const string &aligned1) {
    Sequence_pair::local_aligned1 = aligned1;
}
void Sequence_pair::set_local_aligned2(const string &aligned2) {
    Sequence_pair::local_aligned2 = aligned2;
}
void Sequence_pair::set_global_score(int score) {
    Sequence_pair::global_score = score;
}
void Sequence_pair::set_local_score(int score) {
    Sequence_pair::local_score = score;
}

// overloaded == operator
bool Sequence_pair::operator==(const Sequence_pair &sequence_pair) const {
    return seq1 == sequence_pair.seq1 &&
           seq2 == sequence_pair.seq2;
}

// overloaded << operator
ostream &operator<<(ostream &os, const Sequence_pair &sequence_pair) {
    os << "\nseq1: " << sequence_pair.seq1 << "\nseq2: " << sequence_pair.seq2 << "\n\nGlobal aligned1: "
       << sequence_pair.global_aligned1  << "\nGlobal aligned2: " << sequence_pair.global_aligned2
       << "\n\nOverall global score: " << sequence_pair.global_score << "\n\nLocal aligned1: "
       << sequence_pair.local_aligned1  << "\nLocal aligned2: " << sequence_pair.local_aligned2
       << "\n\nOverall local score: " << sequence_pair.local_score ;
    return os;
}

