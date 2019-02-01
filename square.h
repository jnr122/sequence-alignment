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
    bool active;
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
    Square(int score, bool top_path = false, bool left_path = false, bool diag_path = false, bool active = true);

    /*
     * Getters for field vars
     * Requires: nothing
     * Modifies: nothing
     * Effects: returns field var
     */
    int get_score() const;
    bool is_top_path() const;
    bool is_left_path() const;
    bool is_diag_path() const;
    bool is_active() const;

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
    void set_active(bool active);
};

#endif //SEQUENCE_ALIGNMENT_SQUARE_H
