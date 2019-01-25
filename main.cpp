#include "square.h"
#include "grid.h"

#include <iostream>
#include <vector>

using namespace std;


int main() {

    string strand1, strand2;

    cout << "Enter the first DNA sequence: ";
    getline(cin, strand1);

    cout << "Enter the second DNA sequence: ";
    getline(cin, strand2);

    cout << strand1 << endl;
    cout << strand2 << endl;


    Square square;

    Grid grid = Grid(strand1, strand2, -2, -1, 1);

    grid.populate();

    grid.print_grid();






    return 0;
}

