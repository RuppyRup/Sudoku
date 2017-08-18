#ifndef nonet_hpp
#define nonet_hpp
#include <iostream>
#include <stdio.h>
#include "cell.hpp"
#include<map>

using namespace std;

class Nonet {
private:
    char nonetID;
    bool nonetSolved;
    int solvedCount;
    Cell myCells[CELL_COUNT];
    int solvedCells[CELL_COUNT];
    map<int, int *> unSolvedCells;
public:
    Nonet();
    ~Nonet();
    char getNonetID() { return nonetID; }
    void setNonetID(char);
    bool isNonetSolved();
    int getSolvedCount();
    void cellsSolved();
    map<int, int *> & returnUnSolvedCells() { return unSolvedCells; }
    Cell & getCell(int);
    bool nonetSetCell(Cell &, int);
    void fillNonet();
    void displayNonet();
    void displayCellsSolved();
    void nonetReduction();
    void nonetFindUniqueOptionals();
    bool removeCellOptionalValue(Cell &, int);
};

#endif
