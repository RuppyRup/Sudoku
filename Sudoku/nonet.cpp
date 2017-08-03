#include "nonet.hpp"
#include <iostream>
#include <set>
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

int Nonet::getSolvedCount() {
    cellsSolved();
    return solvedCount;
}

bool Nonet::isNonetSolved() {
    if (getSolvedCount() == 9) {
        nonetSolved = true;
    }
    return nonetSolved;
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

void Nonet::cellsSolved() {
/** Produces an array of values that have been solved
 in this nonet. Updates the value solvedCount **/
    int count = 0;
    for (int i = 0; i < CELL_COUNT; i++) {
        if (myCells[i].getCellIsSolved()) {
            solvedCells[count++] = myCells[i].getSolutionValue();
        }
    }
    cout << "count: " << count << endl;
    solvedCount = count;
}

void Nonet::nonetReduction() {
/** checks the values of the cells solved in the nonet
 and removes these from the optional value array for each cell
 that hasn't yet been solved **/
    cellsSolved();
/** removes optional values for solved cells **/
    for (int j = 0; j < solvedCount; j++) {
        for (int i = 0; i < CELL_COUNT; i++) {
            myCells[i].removeOptionalValue(solvedCells[j]);
        }
    }
/** removes optional values where that is the only option for a 
 particular nonet **/
    int * newArray = new int[81];
    int arrayIndex = 0;
    for (int i = 0; i < CELL_COUNT; i++) {
        if (myCells[i].getCellIsSolved()) {
            continue;
        }
        cout << "Checking cell" << i+1 << endl;
        for (int k = 0; k < myCells[i].getOptionalCount(); k++) {
            newArray[arrayIndex++] = myCells[i].getOptionalValues()[k];
        }
    }
    for(int i = 0; i < arrayIndex; i++) {
        cout << newArray[i] << ", ";
    }
    cout << endl;
    
    for(int i = 0; i < arrayIndex; i++) {
        for(int j = i+1; j < arrayIndex; j++ ) {
            if(newArray[i] == newArray[j]) {
                for(int k = i; k < j-1; k++)
                    newArray[k] = newArray[k+1];
                arrayIndex--;
                for(int m = j; m < arrayIndex-1; m++)
                    newArray[m] = newArray[m+1];
                arrayIndex--;
            }
        }
    }
    
    for(int i = 0; i < arrayIndex; i++) {
        cout << newArray[i] << ", ";
    }
    cout << endl;
    
    
    
    delete [] newArray;
}
