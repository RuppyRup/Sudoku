#ifndef cell_hpp
#define cell_hpp
#include <iostream>
#include <stdio.h>
#define CELL_COUNT 9
using namespace std;

class Cell {
private:
    int cellID;
    string nonetID;
    int optionalValues[CELL_COUNT] = {1,2,3,4,5,6,7,8,9};
    int solutionValue;
    bool cellIsSolved;
    int optionalCount;
public:
    Cell();
    ~Cell();
    void setCellID(int);
    void setNonetID(char);
    bool getCellIsSolved() { return cellIsSolved; }
    int getSolutionValue() { return solutionValue; }
    int getOptionalCount() { return optionalCount; }
    int * getOptionalValues() { return optionalValues; }
    int getCellID() { return cellID; }
    string getNonetID() { return nonetID; }
    void displayCell();
    void displayOptionals();
    bool setCell(int);
    void displayCellAttributes();
    bool removeOptionalValue(int);
};

#endif
