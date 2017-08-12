#include "sudoku.hpp"
#include <iostream>
using namespace std;

Sudoku::Sudoku() {
    fillSudoku();
}

Sudoku::~Sudoku() {
}

int Sudoku::sudokuCellsSolved() {
    int totalCellsSolved = 0;
    for (int i = 0; i < NONET_COUNT; i++) {
        totalCellsSolved += myNonets[i].getSolvedCount();
    }
    return totalCellsSolved;
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

void Sudoku::sudokuReduction() {
    for (int i = 0; i < NONET_COUNT; i++) {
        getNonet((char)(65 + i)).nonetReduction();
        getNonet((char)(65 + i)).nonetFindUniqueOptionals();
    }
}

int Sudoku::crossCheckAll() {
    int cellsSolved = 0;
    for (int i = 0; i < NONET_COUNT; i++) {
        for(int j = 1; j <= CELL_COUNT; j++) {
            crossCheckRow(getNonet((char)(65 + i)).getCell(j));
            crossCheckColumn(getNonet((char)(65 + i)).getCell(j));
        }
        //sudokuReduction();
    }
    return cellsSolved;
}

void Sudoku::crossCheckRow(Cell & cellObj) {
    char myNonetID = cellObj.getNonetID();
    int myCellID = cellObj.getCellID();
    //cout << "myNonetID: " << myNonetID << endl;
    //cout << "myCellID: " << myCellID << endl;
    for (int m = 0; m < NONET_COUNT; m += 3) {
        if ((myNonetID >= 65 + m) && (myNonetID <= 67 + m)) {
            if (myCellID <= 3) {
                for (int i = 65 + m; i < 68 + m; i++) {
                    for (int k = 1; k < 4; k++) {
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else if ((myCellID > 3) && (myCellID <= 6)) {
                for (int i = 65 + m; i < 68 + m; i++) {
                    for (int k = 4; k < 7; k++) {
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else if ((myCellID > 6) && (myCellID <= 9)) {
                for (int i = 65 + m; i < 68 + m; i++) {
                    for (int k = 7; k < 10; k++) {
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else {
                cout << "Cross Check cell id not found" << endl;
            }
        }
    }
}

void Sudoku::crossCheckColumn(Cell & cellObj) {
    char myNonetID = cellObj.getNonetID();
    int myCellID = cellObj.getCellID();
    //cout << "myNonetID: " << myNonetID << endl;
    //cout << "myCellID: " << myCellID << endl;
    for (int m = 0; m < 3; m++) {
        if ((myNonetID == 65 + m) || (myNonetID == 68 + m) || (myNonetID == 71 + m)) {
            if ((myCellID == 1) || (myCellID == 4) || (myCellID == 7)) {
                for (int i = 65 + m; i < 72 + m; i+=3) {
                    for (int k = 1; k <= CELL_COUNT; k+=3) {
                        //cout << "Nonet: " << char(i) << "Cell: " << k << endl;
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else if ((myCellID == 2) || (myCellID == 5) || (myCellID == 8)) {
                for (int i = 65 + m; i < 72 + m; i+=3) {
                    for (int k = 2; k <= CELL_COUNT; k+=3) {
                        //cout << "Nonet: " << char(i) << "Cell: " << k << endl;
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else if ((myCellID == 3) || (myCellID == 6) || (myCellID == 9)) {
                for (int i = 65 + m; i < 72 + m; i+=3) {
                    for (int k = 3; k <= CELL_COUNT; k+=3) {
                        //cout << "Nonet: " << char(i) << "Cell: " << k << endl;
                        if (getNonet((char)i).getCell(k).getCellIsSolved()) {
                            if (getNonet((char)i).removeCellOptionalValue(cellObj, getNonet((char)i).getCell(k).getSolutionValue())) {
                                sudokuReduction();
                            }
                        }
                    }
                }
            }
            else {
                cout << "Cross Check cell id not found" << endl;
            }
        }
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

