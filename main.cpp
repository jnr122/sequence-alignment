#include "Grid.h"
#include "Local_Grid.h"
#include "Sequence_pair.h"

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

    // initialize grid with given sequence pair and penalties
    auto grid = make_unique<Local_Grid>(seq_pair, -2, -1, 2);

    grid->populate();

    // pair with best alignments
    cout << seq_pair << endl;

    // formatted grid output
    cout << *grid << endl;


    return 0;
}