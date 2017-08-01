#ifndef cell_hpp
#define cell_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

class Cell {
private:
    string cellID;
    short row;
    short column;
    short optionalValues[9] = {1,2,3,4,5,6,7,8,9};
    short solutionValue;
    bool cellIsSolved;
    short optionalCount;
public:
    Cell(short, short);
    ~Cell();
    short getRow() { return row; }
    short getColumn() { return column; }
    bool getCellIsSolved() { return cellIsSolved; }
    short getSolutionValue() { return solutionValue; }
    short * getOptionalValues() { return optionalValues; }
    void displayCell();
    void displayOptionals();
    bool setCell(short);
    void displayCellAttributes();
};




#endif
