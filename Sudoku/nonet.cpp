#include "nonet.hpp"
#include <iostream>
#include <set>
using namespace std;

Nonet::Nonet() {
    nonetID = 'X'; //contructors provide the nonetID
    nonetSolved = false; // flag to say if the nonet has been solved
    solvedCount = 0; // current number of solved cells in the nonet
    //fillNonet(); //fills the nonet with ids etc
    //cout << "Nonet with ID: " << nonetID << " created" << endl;
}
Nonet::~Nonet() {
    //cout << "A nonet has been destroyed" << endl;
}

void Nonet::setNonetID(char nonetID) {
    this->nonetID = nonetID;
    fillNonet();
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

int * Nonet::returnUnSolvedCells() {
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
    //cout << "cells solved: " << count << endl;
    solvedCount = count;
}

void Nonet::displayCellsSolved() {
    cout << "Solved values : ";
    for (int i = 0; i < solvedCount; i++) {
        cout << solvedCells[i] << ", ";
    }
    cout << endl;
}

bool Nonet::nonetSetCell(Cell & cellObj, int solutionValue) {
    cellsSolved();
    bool alreadySet = false;
    for (int i = 0; i < solvedCount; i++) {
        cout << "solved value = " << solvedCells[i] << endl;
        if (solutionValue == solvedCells[i]) {
            alreadySet = true;
            cout << "A nonet cell has already been set at that value" << endl;
        }
    }
    if (alreadySet) {
        return false;
    }
    else {
        cellObj.setCell(solutionValue);
        return true;
    }
}

void Nonet::nonetReduction() {
/** checks the values of the cells solved in the nonet
 and removes these from the optional value array for each cell
 that hasn't yet been solved **/
    cellsSolved();
/** removes optional values for solved cells **/
    for (int j = 0; j < CELL_COUNT; j++) {
        //cout << "Nonet reduction" << endl;
        for (int i = 0; i < solvedCount; i++) {
            //cout << "Nonet reduction" << endl;
            //cout << "true: " << myCells[j].removeOptionalValue(solvedCells[i]) << endl;
            if (removeCellOptionalValue(myCells[j], solvedCells[i])) {
                cellsSolved();
                cout << "Nonet Reduction: solution found" << endl;
                break;
            }
        }
    }
}
    
void Nonet::nonetFindUniqueOptionals() {
/** removes optional values where that is the only option for a 
 particular nonet **/
    int * newArray = new int[81];
    int arrayIndex = 0;
    for (int i = 0; i < CELL_COUNT; i++) {
        if (myCells[i].getCellIsSolved()) {
            continue;
        }
        //cout << "Checking cell " << i+1 << endl;
        for (int k = 0; k < myCells[i].getOptionalCount(); k++) {
            newArray[arrayIndex++] = myCells[i].getOptionalValues()[k];
        }
    }
    /*for(int i = 0; i < arrayIndex; i++) {
        cout << newArray[i] << ", ";
    }
    cout << endl;*/
    /** remove all values greater than one by replacing with zero**/
    int tmp = 0;
    for(int i = 0; i < arrayIndex; i++) {
        tmp = newArray[i];
        for(int j = i+1; j < arrayIndex; j++ ) {
            if(tmp == newArray[j]) {
                newArray[i] = 0;
                newArray[j] = 0;
            }
        }
    }
    
    for(int j = 0; j < arrayIndex; j++) {
        if (newArray[j]) {
            for (int i = 0; i < CELL_COUNT; i++) {
                if (myCells[i].getCellIsSolved()) {
                    continue;
                }
                for (int k = 0; k < myCells[i].getOptionalCount(); k++) {
                    if (newArray[j] == myCells[i].getOptionalValues()[k]) {
                        cout << nonetID << " Setting Cell " << i+1 << " with " << newArray[j] << endl;
                        //myCells[i].setCell(newArray[j]);
                        if (nonetSetCell(myCells[i], newArray[j])) {
                            cout << nonetID << " Setting Cell " << i+1 << " with " << newArray[j] << "PASS" << endl;
                        }
                        else {
                            cout << nonetID << " Setting Cell " << i+1 << " with " << newArray[j] << "FAIL" << endl;
                        }
                    }
                }
            }

        }
    }
    delete [] newArray;
}


bool Nonet::removeCellOptionalValue(Cell & cellObj, int numberToRemove) {
    /** each cell (unless it is set at the start) is initalised with
     an array of optional values from 1 - 9. The process of Sudoku is
     to reduce these options down to 1 which will then be the
     solutionValue. Returns true if a solution value is found by running this method **/
    int arrayIndex = 0;
    bool foundNumber = false;
    // If cell has already been solved return true.
    // otherwise optional count is reduced to zero.
    if (cellObj.getCellIsSolved()) {
        return false;
    }
    for (int i = 0; i < cellObj.getOptionalCount(); i++) {
        if (cellObj.getOptionalValues()[i] == numberToRemove) {
            arrayIndex = i;
            cout << "Removing value " << cellObj.getOptionalValues()[i] << " at " << arrayIndex + 1;
            cout << " " << getNonetID() << "-" <<cellObj.getNonetID() << " : " << cellObj.getCellID() << endl;
            foundNumber = true;
            break;
        }
    }
    if (!foundNumber) {
        //cout << "Couldn't find number to remove from optionals" << endl;
        return false;
    }
    cellObj.decrementOptionalCount();
    //cout << "Optional count" << optionalCount << endl;
    for (int i = arrayIndex; i < cellObj.getOptionalCount(); i++) {
        cellObj.getOptionalValues()[i] = cellObj.getOptionalValues()[i+1];
    }
    
    if (cellObj.getOptionalCount() == 1) {
        //cout << "bob" << endl;
        cout << "setting cell with " << cellObj.getOptionalValues()[0] << cellObj.getNonetID() << cellObj.getCellID() << endl;
        nonetSetCell(cellObj, cellObj.getOptionalValues()[0]);
        cout << "bob" << endl;
        return true;
    }
    
    return false;
}
    
    
    /** if optional value = 1 then the solution must have been found
     if (optionalCount == 1) {
     cellIsSolved = true;
     solutionValue = optionalValues[0];
     cout << "Opt Nonet: "<< nonetID << " cell: " << cellID << " is set by optional value "<< optionalValues[0] << endl;
     } **/

