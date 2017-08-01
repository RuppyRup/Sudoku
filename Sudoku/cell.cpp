#include "cell.hpp"
using namespace std;

Cell::Cell(int row, int column) {
    this->row = row;
    this->column = column;
    solutionValue = 0;
    cellIsSolved = false;
    optionalCount = 9;
    cout << "Cell has been created" << endl;
}
Cell::~Cell() {
    cout << "Cell has been destroyed" << endl;
}
bool Cell::setCell(int solutionValue) {
    if ((solutionValue >= 1) && (solutionValue <= 9)) {
        this->solutionValue = solutionValue;
        optionalCount = 1;
        cellIsSolved = true;
        cout << "Cell has been set" << endl;
        return true;
    }
    else {
        cout << "Cell not set" << endl;
        return false;
    }
}

bool Cell::removeOptionalValue(int numberToRemove) {
    int arrayIndex = 0;
    for (int i = 0; i < optionalCount; i++) {
        if (optionalValues[i] == numberToRemove) {
            arrayIndex = i;
            cout << "Removing value " << optionalValues[i] << " at " << arrayIndex << endl;
            break;
        }
    }
    if (arrayIndex == 0) {
        cout << "Couldn't find number to remove from optionals" << endl;
        return false;
    }
    --optionalCount;
    for (int i = arrayIndex; i < optionalCount; i++) {
        optionalValues[i] = optionalValues[i+1];
    }
    return true;
}

void Cell::displayCell() {
    cout << " _" << endl;
    cout << "|" << solutionValue << "|" << endl;
    cout << " -" << endl;
}

void Cell::displayOptionals() {
    cout << "(";
    for (short i = 0; i < optionalCount; i++) {
        cout << optionalValues[i] << ",";
    }
    cout << ")" << endl;
}

void Cell::displayCellAttributes() {
    cout << "row: " << getRow() << endl;
    cout << "column: " << getColumn() << endl;
    cout << "solved? " << getCellIsSolved() << endl;
    cout << "Optional Count: " << getOptionalCount() << endl;
    displayOptionals();
    displayCell();
}
    
    
