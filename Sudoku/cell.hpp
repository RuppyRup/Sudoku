#ifndef cell_hpp
#define cell_hpp
#include <iostream>
#include <stdio.h>
using namespace std;

class Cell {
private:
    string cellID;
    int row;
    int column;
    int optionalValues[9] = {1,2,3,4,5,6,7,8,9};
    int solutionValue;
    bool cellIsSolved;
    int optionalCount;
public:
    Cell(int, int);
    ~Cell();
    int getRow() { return row; }
    int getColumn() { return column; }
    bool getCellIsSolved() { return cellIsSolved; }
    int getSolutionValue() { return solutionValue; }
    int getOptionalCount() { return optionalCount; }
    int * getOptionalValues() { return optionalValues; }
    void displayCell();
    void displayOptionals();
    bool setCell(int);
    void displayCellAttributes();
    bool removeOptionalValue(int);
};




#endif
