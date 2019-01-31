//
// Created by Jonah Rubin on 2019-01-31.
//

#include <string>

#include "DNA_pair.h"

using namespace std;

DNA_pair::DNA_pair() {
    this->seq1 = "agct";
    this->seq2 = "gtac";
}

DNA_pair::DNA_pair(string seq1, string seq2) {
    this->seq1 = seq1;
    this->seq2 = seq2;
}

void DNA_pair::setSeq1(const string &seq1) {
    DNA_pair::seq1 = seq1;
}

const string &DNA_pair::getSeq2() const {
    return seq2;
}

void DNA_pair::setSeq2(const string &seq2) {
    DNA_pair::seq2 = seq2;
}

const string &DNA_pair::getAligned1() const {
    return aligned1;
}

void DNA_pair::setAligned1(const string &aligned1) {
    DNA_pair::aligned1 = aligned1;
}

const string &DNA_pair::getAligned2() const {
    return aligned2;
}

void DNA_pair::setAligned2(const string &aligned2) {
    DNA_pair::aligned2 = aligned2;
}
