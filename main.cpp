#include "Grid.h"
#include "Sequence_pair.h"
#include "Square.h"

#include <iostream>
#include <string>
#include <optional>

using namespace std;

int main() {

    // declare strands to be aligned
    string strand1, strand2;

    // get strands
    cout << "Enter the first sequence: ";
    getline(cin, strand1);

    cout << "Enter the second sequence: ";
    getline(cin, strand2);

    Sequence_pair seq_pair = Sequence_pair(strand1, strand2);

    // initliaze grid with given seqence pair and penalties
    Grid grid = Grid(seq_pair, -2, -1, 1);

    // pair with best alignments
    cout << seq_pair << endl;

    // formatted grid output
    cout << grid << endl;

    return 0;
}

