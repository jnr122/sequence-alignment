//
// Created by Jonah Rubin on 2019-01-31.
//

#ifndef SEQUENCE_ALIGNMENT_DNA_PAIR_H
#define SEQUENCE_ALIGNMENT_DNA_PAIR_H

#include <string>

using namespace std;

class DNA_pair {

private:
    string seq1, seq2, aligned1, aligned2;

public:

    /*
     * Default constructor
     * Requires: Nothing
     * Modifies: Object field vars
     * Effects: Initializes object to default vals
     */
    DNA_pair();

    /*
     * Default constructor
     * Requires: Nothing
     * Modifies: Object field vars
     * Effects: Initializes object to given vals
    */
    DNA_pair(string seq1, string seq2);

    const string &getSeq1() const;

    void setSeq1(const string &seq1);

    const string &getSeq2() const;

    void setSeq2(const string &seq2);

    const string &getAligned1() const;

    void setAligned1(const string &aligned1);

    const string &getAligned2() const;

    void setAligned2(const string &aligned2);


};

#endif //SEQUENCE_ALIGNMENT_DNA_PAIR_H
