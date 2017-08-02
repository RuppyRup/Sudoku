#include "nonet.hpp"
#include <iostream>
using namespace std;

Nonet::Nonet(string nonetID) {
    this->nonetID = nonetID;
    nonetSolved = false;
    fillNonet();
}
Nonet::~Nonet() {
    cout << "A nonet has been destroyed" << endl;
}
Cell & Nonet::getCell(int cellID) {
    return myCells[cellID - 1];
}

void Nonet::fillNonet() {
    for (int i = 0; i < CELL_COUNT; i++) {
        myCells[i].setCellID(i+1);
        myCells[i].setNonetID(nonetID);
    }
}

void Nonet::displayNonet() {
    for (int i = 0; i < CELL_COUNT; i++) {
        cout << "|" << myCells[i].getSolutionValue();
        if ((i == 2) || (i == 5) || (i == 8))
            cout << "|" << endl;
    }
}

int Nonet::cellsSolved() {
    int solvedCount = 0;
    for (int i = 0; i < CELL_COUNT; i++) {
        if (myCells[i].getCellIsSolved()) {
            solvedCount++;
        }
    }
    return solvedCount;
}
