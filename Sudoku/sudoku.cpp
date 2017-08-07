#include "sudoku.hpp"
#include <iostream>
using namespace std;

Sudoku::Sudoku() {
    fillSudoku();
}

Sudoku::~Sudoku() {
}

Nonet & Sudoku::getNonet(char nonetID) {
    /** returns the reference cell to the corresponding nonetID (A-I) **/
    for (int i = 0; i < NONET_COUNT; i++) {
        if (myNonets[i].getNonetID() == nonetID) {
            return myNonets[i];
        }
    }
    return myNonets[0];
}

void Sudoku::fillSudoku() {
    /** Fills the sudoku array of nonets (myNonets) with IDs (A-I) **/
    for (int i = 0; i < NONET_COUNT; i++) {
        myNonets[i].setNonetID((char)(65 + i));
    }
}
