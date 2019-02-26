#include "Grid.h"
#include "Sequence_pair.h"

#include <iostream>
#include <string>
#include <optional>

using namespace std;

int main() {

    // test suite

    bool passed = true;

    // matching seqs
    Sequence_pair seq_pair = Sequence_pair("aaaa", "aaaa");
    Grid grid = Grid(seq_pair, -2, -1, 1);
    grid.populate();


    if (seq_pair.get_global_score() != 4) {
        cout << "failed equal strings score" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "aaaa") {
        cout << "failed equal strings aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "aaaa") {
        cout << "failed equal strings aligned2" << endl;
        passed = false;
    }

    // entirely unique seqs same length
    seq_pair = Sequence_pair("abcdefg", "hijklmn");
    Grid grid2 = Grid(seq_pair, -2, -1, 1);
    grid2.populate();

    if (seq_pair.get_global_score() != -7) {
        cout << "failed entirely unique seqs same length" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "abcdefg") {
        cout << "failedentirely unique seqs same length aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "hijklmn") {
        cout << "failed entirely unique seqs same length aligned2" << endl;
        passed = false;
    }

    // matching but 1 > 2
    seq_pair = Sequence_pair("aaaaaaaaa", "aaaaa");
    Grid grid3 = Grid(seq_pair, -2, -1, 1);
    grid3.populate();

    if (seq_pair.get_global_score() != -3) {
        cout << "failed matching but 1 > 2" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "aaaaaaaaa") {
        cout << "failed  matching but 1 > 2 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "aaaaa----") {
        cout << "failed  matching but 1 > 2 aligned2" << endl;
        passed = false;
    }

    // matching but 2 > 1
    seq_pair = Sequence_pair("aaaaa", "aaaaaaaaa");
    Grid grid4 = Grid(seq_pair, -2, -1, 1);
    grid4.populate();

    if (seq_pair.get_global_score() != -3) {
        cout << "failed matching but 2 > 1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "aaaaa----") {
        cout << "failed matching but 2 > 1 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "aaaaaaaaa") {
        cout << "failed matching but 2 > 1 aligned2" << endl;
        passed = false;
    }

    // unique but 1 > 2
    seq_pair = Sequence_pair("ahdjkladfhalj", "yreuio");
    Grid grid7 = Grid(seq_pair, -2, -1, 1);
    grid7.populate();

    if (seq_pair.get_global_score() != -20) {
        cout << "failed unique but 1 > 2" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "ahdjkladfhalj") {
        cout << "failed unique but 1 > 2 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "yreuio-------") {
        cout << "failed unique but 1 > 2 aligned2" << endl;

        passed = false;
    }



    // matching but 2 > 1
    seq_pair = Sequence_pair("yreuio", "ahdjkladfhalj");
    Grid grid8 = Grid(seq_pair, -2, -1, 1);
    grid8.populate();

    if (seq_pair.get_global_score() != -20) {
        cout << "failed unique but 2 > 1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "yreuio-------") {
        cout << "failed matching but 2 > 1 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "ahdjkladfhalj") {
        cout << "failed matching but 2 > 1 aligned2" << endl;

        passed = false;
    }


    // 2 is a subseq of 1
    seq_pair = Sequence_pair("ahfjdaklfeuilwha", "klfeui");
    Grid grid5 = Grid(seq_pair, -2, -1, 1);
    grid5.populate();

    if (seq_pair.get_global_score() != -14) {
        cout << "failed 2 is a subseq of 1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "ahfjdaklfeuilwha") {
        cout << "failed 2 is a subseq of 1 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "------klfeui----") {
        cout << "failed 2 is a subseq of 1 aligned2" << endl;

        passed = false;
    }


    // 1 is a subseq of 2
    seq_pair = Sequence_pair("klfeui", "ahfjdaklfeuilwha");
    Grid grid6 = Grid(seq_pair, -2, -1, 1);
    grid6.populate();

    if (seq_pair.get_global_score() != -14) {
        cout << "failed 1 is a subseq of 2" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "------klfeui----") {
        cout << "failed1 is a subseq of 2 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "ahfjdaklfeuilwha") {
        cout << "failed 1 is a subseq of 2 aligned2" << endl;

        passed = false;
    }

    // 1 is multiples of 2
    seq_pair = Sequence_pair("asdfasdfasdfasdf", "asdf");
    Grid grid9 = Grid(seq_pair, -2, -1, 1);
    grid9.populate();

    if (seq_pair.get_global_score() != -20) {
        cout << "failed 1 is multiples of 2" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "asdfasdfasdfasdf") {
        cout << "failed 1 is multiples of 2 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "asdf------------") {
        cout << "failed 1 is multiples of 2 aligned2" << endl;

        passed = false;
    }

    // 2 is multiples of 1
    seq_pair = Sequence_pair("asdf", "asdfasdfasdfasdf");
    Grid grid10 = Grid(seq_pair, -2, -1, 1);
    grid10.populate();

    if (seq_pair.get_global_score() != -20) {
        cout << "failed 2 is multiples of 1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned1() != "asdf------------") {
        cout << "failed  2 is multiples of 1 aligned1" << endl;
        passed = false;
    }

    if (seq_pair.get_global_aligned2() != "asdfasdfasdfasdf") {
        cout << "failed  2 is multiples of 1 aligned2" << endl;
        passed = false;
    }

    if (passed) {
        cout << "Passed all test cases" << endl;
    }




    return 0;
}

