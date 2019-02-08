#include "Grid.h"
#include "Sequence_pair.h"
#include "Square.h"

#include <iostream>
#include <string>
#include <optional>

using namespace std;

int main() {

    // Testing suite for Seuquence_pair::get_score()
    // Requires any valid sequence pair (seq length > 0)

    bool passed = true;


    // matching seqs
    Sequence_pair seq_pair = Sequence_pair("aaaa", "aaaa");
    Grid grid = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != 4) {
        cout << "failed equal strings" << endl;
        passed = false;
    }

    // entirely unique seqs same length
    seq_pair = Sequence_pair("abcdefg", "hijklmn");
    Grid grid2 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -7) {
        cout << "failed entirely unique seqs same length" << endl;
        passed = false;
    }

    // matching but 1 > 2
    seq_pair = Sequence_pair("aaaaaaaaa", "aaaaa");
    Grid grid3 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -3) {
        cout << "failed matching but 1 > 2" << endl;
        passed = false;
    }

    // matching but 2 > 1
    seq_pair = Sequence_pair("aaaaa", "aaaaaaaaa");
    Grid grid4 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -3) {
        cout << "failed matching but 2 > 1" << endl;
        passed = false;
    }

    // unique but 1 > 2
    seq_pair = Sequence_pair("ahdjkladfhalj", "yreuio");
    Grid grid7 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -20) {
        cout << "failed unique but 1 > 2" << endl;
        passed = false;
    }

    // matching but 2 > 1
    seq_pair = Sequence_pair("yreuio", "ahdjkladfhalj");
    Grid grid8 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -20) {
        cout << "failed unique but 2 > 1" << endl;
        passed = false;
    }

    // 2 is a subseq of 1
    seq_pair = Sequence_pair("ahfjdaklfeuilwha", "klfeui");
    Grid grid5 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -14) {
        cout << "failed 2 is a subseq of 1" << endl;
        passed = false;
    }

    // 1 is a subseq of 2
    seq_pair = Sequence_pair("klfeui", "ahfjdaklfeuilwha");
    Grid grid6 = Grid(seq_pair, -2, -1, 1);

    if (seq_pair.get_score() != -14) {
        cout << "failed 1 is a subseq of 2" << endl;
        passed = false;
    }

    if (passed) {
        cout << "Passed all test casses" << endl;
    }


    return 0;
}

