#include "square.h"
#include "grid.h"

#include <iostream>
#include <string>

using namespace std;


int main() {

    // declare strands to be aligned
    string strand1, strand2;

    // get strands
    cout << "Enter the first DNA sequence: ";
    getline(cin, strand1);

    cout << "Enter the second DNA sequence: ";
    getline(cin, strand2);

    // initliaze grid with given strands and penalties
    Grid grid = Grid(strand1, strand2, -2, -1, 1);

    // formatted grid output
    grid.print_grid();


    return 0;
}

