#include "cell.hpp"
using namespace std;

Cell::Cell(short row, short column) {
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
bool Cell::setCell(short solutionValue) {
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
    displayOptionals();
    displayCell();
}
    
    
