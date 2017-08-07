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

void Sudoku::displaySudoku() {
    /** Displays the cells with solutionvalue of the nonet **/
    for (int m = 0; m < CELL_COUNT; m+= 3) {
        for (int k = 0; k < CELL_COUNT; k+=3) {
            for (int j = 0; j < 3; j++) {
                for (int i = 0; i < 3; i++) {
                    cout << "|" << getNonet((char)(65 + j + m)).getCell(i+1+k).getSolutionValue();
                }
                cout << "| ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

