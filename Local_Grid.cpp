//
// Created by Jonah Rubin on 2019-02-24.
//
#include "Local_Grid.h"

#include <experimental/optional>

using namespace std;
using experimental::nullopt;
using experimental::make_optional;

Local_Grid::Local_Grid(Sequence_pair &seq_pair, int gap_penalty, int mismatch_penalty, int match_bonus) :
                       Grid(seq_pair, gap_penalty, mismatch_penalty, match_bonus) {


}

void Local_Grid::populate() {
    // set up matrix with default values
    for (int i = 0; i <= seq_pair.get_seq2().size(); i++) {
        vector<OptSquare> row;
        for (int j = 0; j <= seq_pair.get_seq1().size(); j++) {

            OptSquare square = nullopt;
            if (j == 0) {
                square = Square(0, top_path);
            } else if (i == 0) {
                square = Square(0, left_path);
            }
            row.push_back(square);
        }
        cols.push_back(row);
    }

    // 'forgets' square i,j for some reason, even though it calculates everything correctly
    // recalling the method solely to fill in i and j is a working patch
    cols[seq_pair.get_seq2().size()][seq_pair.get_seq1().size()]-> score = (calculate(seq_pair.get_seq2().size(), seq_pair.get_seq1().size()));
    cols[seq_pair.get_seq2().size()][seq_pair.get_seq1().size()]-> score =(calculate(seq_pair.get_seq2().size(), seq_pair.get_seq1().size()));


    int max = 0;
    int row = 0;
    int col = 0;

    for (int i = 0; i < cols.size(); i++) {
        for (int j = 0; j < cols[0].size(); j++) {
            if (cols[i][j]->score > max) {
                max = cols[i][j]->score;
                row = j;
                col = i;
            }
        }
    }
    

    // set both alignments
    seq_pair.set_local_aligned1(traceback(col, row, seq_pair.get_seq1()));
    seq_pair.set_local_aligned2(traceback(col, row, seq_pair.get_seq2()));

    // reverse alignments
    string rev = seq_pair.get_local_aligned1();
    reverse(rev.begin(), (rev.end()));
    seq_pair.set_local_aligned1(rev);
    rev = seq_pair.get_local_aligned2();
    reverse(rev.begin(), (rev.end()));
    seq_pair.set_local_aligned2(rev);

    seq_pair.set_local_score(cols[col][row]->score);


}

string Local_Grid::traceback(int i, int j, string seq) {

    // base case
    if ((i == 0 and j == 0) or (cols[i][j]->score == 0)){
        return "";
    }

    // TODO: move out diagonal
    if (seq == seq_pair.get_seq1()) {
        if (cols[i][j]->path == top_path) {
            return "-" + traceback(i-1, j, seq);
        } else if (cols[i][j]->path == diag_path) {
            return string(1, (seq.at(j-1))) + traceback(i-1, j-1, seq);
        } else {
            return string(1, (seq.at(j-1))) + traceback(i, j-1, seq);
        }

    } else {
        if (cols[i][j]->path == top_path) {
            return string(1, (seq.at(i-1))) + traceback(i-1, j, seq);
        } else if (cols[i][j]->path == diag_path) {
            return string(1, (seq.at(i-1))) + traceback(i-1, j-1, seq);
        } else {
            return "-" + traceback(i, j-1, seq);
        }
    }
}

int Local_Grid::get_max(int top, int left, int diag, int i, int j) {

    int max;

    // TODO: get rid of returns statements, move to bottom only need set_path, set_score once
    if (top >= left)  {
        if (top >= diag) {
            if (top < 0) {
                cols[i][j] = make_optional<Square>(Square(0, top_path));
                max = 0;
            } else {
                cols[i][j] = make_optional<Square>(Square(top, top_path));
                max = top;
            }
        } else {
            if (diag < 0) {
                cols[i][j] = make_optional<Square>(Square(0, diag_path));
                max = 0;
            } else {
                cols[i][j] = make_optional<Square>(Square(diag, diag_path));
                max = diag;
            }
        }
    } else {
        if (left >= diag) {
            if (left < 0) {
                cols[i][j] = make_optional<Square>(Square(0, left_path));
                max = 0;
            } else {
                cols[i][j] = make_optional<Square>(Square(left, left_path));
                max = left;
            }
        } else {
            if (diag < 0) {
                cols[i][j] = make_optional<Square>(Square(0, diag_path));
                max = 0;
            } else {
                cols[i][j] = make_optional<Square>(Square(diag, diag_path));
                max = diag;
            }
        }
    }

    return max;
}