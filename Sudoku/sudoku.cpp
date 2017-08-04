#include "sudoku.hpp"
#include <iostream>
using namespace std;

Sudoku::Sudoku(Nonet * nonetArray) {
    myNonets = nonetArray;
}

Sudoku::~Sudoku() {
}

Nonet & Sudoku::getNonet(char nonetID) {
    /** returns the reference cell to the corresponding nonetID (A-I) **/
    return myNonets[0];
}
