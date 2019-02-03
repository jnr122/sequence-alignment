#include "grid.h"
#include "sequence_pair.h"
#include "square.h"

#include <iostream>
#include <string>

using namespace std;


int main() {

    // declare strands to be aligned
    string strand1, strand2;

    // get strands
    cout << "Enter the first sequence: ";
    getline(cin, strand1);

    cout << "Enter the second sequence: ";
    getline(cin, strand2);

    // initliaze grid with given strands and penalties
    Grid grid = Grid(strand1, strand2, -2, -1, 1);

    // print best global alignmemnts
    cout << grid.get_aligned1() << endl;
    cout << grid.get_aligned2() << endl;

    // formatted grid output
//    cout << grid << endl;

//    Sequence_pair seq_pair = Sequence_pair(strand1, strand2);

//    cout << seq_pair << endl;





    return 0;
}

