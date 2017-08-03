#include "nonet.hpp"
#include <iostream>
using namespace std;

Nonet::Nonet(char nonetID) {
    this->nonetID = nonetID; //contructors provide the nonetID
    nonetSolved = false; // flag to say if the nonet has been solved
    solvedCount = 0; // current number of solved cells in the nonet
    fillNonet(); //fills the nonet with ids etc
}
Nonet::~Nonet() {
    cout << "A nonet has been destroyed" << endl;
}
Cell & Nonet::getCell(int cellID) {
/** returns the reference cell to the corresponding cellID (1-9) **/
    return myCells[cellID - 1];
}

void Nonet::fillNonet() {
/** Fills the nonet array of cells (myCells) with IDs (1-9)
 and nonet IDs from the nonet that created them **/
    for (int i = 0; i < CELL_COUNT; i++) {
        myCells[i].setCellID(i+1);
        myCells[i].setNonetID(nonetID);
    }
}

void Nonet::displayNonet() {
/** Displays the cells with solutionvalue of the nonet **/
    for (int i = 0; i < CELL_COUNT; i++) {
        cout << "|" << myCells[i].getSolutionValue();
        if ((i == 2) || (i == 5) || (i == 8))
            cout << "|" << endl;
    }
}

int * Nonet::cellsSolved() {
/** Returns a pointer to an array of values that have been solved
 in this nonet. Updates the value solvedCount **/
    int count = 0;
    for (int i = 0; i < CELL_COUNT; i++) {
        if (myCells[i].getCellIsSolved()) {
            solvedCells[count++] = myCells[i].getSolutionValue();
        }
    }
    cout << "count: " << count << endl;
    solvedCount = count;
    return solvedCells;
}

void Nonet::nonetReduction() {
/** checks the values of the cells solved in the nonet
 and removes these from the optional value array for each cell
 that hasn't yet been solved **/
    if (solvedCount > 0) {
        
    }
}
