#include "Grid.h"
#include "Local_Grid.h"
#include "Sequence_pair.h"

#include <iostream>
#include <string>
#include <optional>
#include <fstream>



using namespace std;

int main() {

    // declare strands to be aligned
    string strand1, strand2;

    ifstream infile ("2.in");
    if (infile.is_open())
    {
        getline(infile, strand1, '\n');
        getline(infile, strand2);

        infile.close();
    }

    Sequence_pair seq_pair = Sequence_pair(strand1, strand2);

    // initialize local grid with given sequence pair and penalties
    // global alignment
    auto grid = make_unique<Grid>(seq_pair, -2, -1, 2);

    // local alignment
//     auto grid = make_unique<Local_Grid>(seq_pair, -2, -1, 2);

    grid->populate();

    ofstream out1("2.01");
    if (out1.is_open()) {
        out1 << seq_pair.get_score();
        out1.close();
    }

    ofstream out2("2.02");
    if (out2.is_open()) {
        for (int i = 0; i < grid->get_cols()[0].size(); i++) {
            for (int j = 0; j < grid->get_cols().size(); j++) {
                out2 << grid->get_cols()[j][i]->score << " ";
            }
            out2 <<  "\n";

        }
        out2.close();

    }

    ofstream out3("2.03");
    if (out3.is_open()) {
        out3 << seq_pair.get_aligned1();
        out3 << "\n";
        out3 << seq_pair.get_aligned2();
        out3.close();
    }

    ofstream out4("2.04");
    if (out4.is_open()) {
        if (grid->get_multiple_alignments()) {
            out4 << "YES";
        } else {
            out4 << "NO";

        }
        out4.close();
    }


    return 0;
}