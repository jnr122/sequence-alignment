//
// Created by Jonah Rubin on 2019-01-31.
//

#ifndef SEQUENCE_ALIGNMENT_DNA_PAIR_H
#define SEQUENCE_ALIGNMENT_DNA_PAIR_H

#include <string>
#include <ostream>

using namespace std;

class Sequence_pair {

private:
    string seq1, seq2, aligned1, aligned2;

    /*
     * Sequence validator
     * Requires: Sequence string
     * Modifies: Nothing
     * Effects: Returns a valid string
     */
    string validate_seq(string seq);

public:

    /*
     * Default constructor
     * Requires: Nothing
     * Modifies: Object field vars
     * Effects: Initializes object to given vals
    */
    Sequence_pair(const string &seq1 = "gatc", const string &seq2 = "catg");

    // destructor
    virtual ~Sequence_pair();

    /*
     * Overloaded print method
     * Requires: nothing
     * Modifies: nothing
     * Effects: prints formatted seq pair
    */
    friend ostream &operator<<(ostream &os, const Sequence_pair &sequence_pair);

    /*
     * Getters for field vars
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns field var
     */
    const string &get_seq1() const;
    const string &get_seq2() const;
    const string &get_aligned1() const;
    const string &get_aligned2() const;

    /*
      * Setters for field vars
      * Requires: new value
      * Modifies: field values
      * Effects: sets new value
     */
    void set_seq1(const string &seq1);
    void set_seq2(const string &seq2);
    void set_aligned1(const string &aligned1);
    void set_aligned2(const string &aligned2);

};

#endif //SEQUENCE_ALIGNMENT_DNA_PAIR_H
