#include "cell.hpp"
using namespace std;

Cell::Cell() {
    cellID = 0;
    nonetID = 'x';
    solutionValue = 0;
    cellIsSolved = false;
    optionalCount = CELL_COUNT;
    //cout << "Default Cell has been created" << endl;
}

Cell::~Cell() {
    //cout << "Cell has been destroyed" << endl;
}

void Cell::setCellID(int cellID) {
/** sets the ID of the cell. Used in fillNonet **/
    this->cellID = cellID;
}

void Cell::setNonetID(char nonetID) {
/** sets the ID of the cell. Used in fillNonet **/
    this->nonetID = nonetID;
}

bool Cell::setCell(int solutionValue) {
/** used to set the solution value of a cell, set optional count
 to 1 and to flag that the cellIsSolved = true. This can be set
 at the start or when a solution is found for the cell **/
    
    if ((solutionValue >= 1) && (solutionValue <= CELL_COUNT)) {
        this->solutionValue = solutionValue;
        optionalValues[0] = solutionValue;
        optionalCount = 1;
        cellIsSolved = true;
        cout << nonetID << " Cell " << cellID << " has been set with " << solutionValue << endl;
        return true;
    }
    else {
        cout << "Cell not set" << endl;
        return false;
    }
}

bool Cell::removeOptionalValue(int numberToRemove) {
/** each cell (unless it is set at the start) is initalised with 
 an array of optional values from 1 - 9. The process of Sudoku is 
 to reduce these options down to 1 which will then be the 
 solutionValue. Returns true if a solution value is found by running this method **/
    int arrayIndex = 0;
    bool foundNumber = false;
    // If cell has already been solved return true.
    // otherwise optional count is reduced to zero.
    if (cellIsSolved) {
        return false;
    }
    for (int i = 0; i < optionalCount; i++) {
        if (optionalValues[i] == numberToRemove) {
            arrayIndex = i;
            cout << "Removing value " << optionalValues[i] << " at " << arrayIndex + 1;
            cout << " " << nonetID << " : " << cellID << endl;
            foundNumber = true;
            break;
        }
    }
    if (!foundNumber) {
        //cout << "Couldn't find number to remove from optionals" << endl;
        return false;
    }
    --optionalCount;
    //cout << "Optional count" << optionalCount << endl;
    for (int i = arrayIndex; i < optionalCount; i++) {
        optionalValues[i] = optionalValues[i+1];
    }
    
    if (optionalCount == 1) {
        //cout << "bob" << endl;
        setCell(optionalValues[0]);
        //Nonet::nonetSetCell(
        cout << "bob" << endl;
        return true;
    }
    
    
    /** if optional value = 1 then the solution must have been found
    if (optionalCount == 1) {
        cellIsSolved = true;
        solutionValue = optionalValues[0];
        cout << "Opt Nonet: "<< nonetID << " cell: " << cellID << " is set by optional value "<< optionalValues[0] << endl;
    } **/
    
    return false;
}

void Cell::displayCell() {
/** Used for debug to display the value of a cell **/
    cout << " _" << endl;
    cout << "|" << solutionValue << "|" << endl;
    cout << " -" << endl;
}

void Cell::displayOptionals() {
/** Used for debug to display the optional values of a cell **/
    cout << "(";
    for (short i = 0; i < optionalCount; i++) {
        cout << optionalValues[i] << ",";
    }
    cout << ")" << endl;
}

void Cell::displayCellAttributes() {
/** Used for debug to display the attributes of a cell **/
    cout << "cellID: " << getCellID() << endl;
    cout << "nonetID: " << getNonetID() << endl;
    cout << "solved? " << getCellIsSolved() << endl;
    cout << "Optional Count: " << getOptionalCount() << endl;
    displayOptionals();
    displayCell();
}
    
    
