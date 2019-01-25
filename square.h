//
// Created by Jonah Rubin on 2019-01-24.
//

#ifndef SEQUENCE_ALIGNMENT_SQUARE_H
#define SEQUENCE_ALIGNMENT_SQUARE_H

using namespace std;

class Square {

private:
    int score;
    bool top_path;
    bool left_path;
    bool diag_path;

public:

    /*
     * Default Constructor
     * Requires: nothing
     * Modifies: square score
     * Effects: sets current score to default val
     */
    Square();

    /*
     * Overloaded Constructor
     * Requires: int score, boolean path vars
     * Modifies: square score, path
     * Effects: constructs current square to given vals
    */
    Square(int score, bool top_path = false, bool left_path = false, bool diag_path = false);


    /*
     * Getters for field vars
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns field var
     */
    int get_score();
    bool get_top_path();
    bool get_left_path();
    bool get_diag_path();

    /*
     * Setters for field vars
     * Requires: new value
     * Modifies: field values
     * Effects: sets new value
    */
    void set_score(int score);
    void set_top_path(bool top_path);
    void set_left_path(bool left_path);
    void set_diag_path(bool diag_path);



};

#endif //SEQUENCE_ALIGNMENT_SQUARE_H
