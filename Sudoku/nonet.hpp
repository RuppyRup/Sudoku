#ifndef nonet_hpp
#define nonet_hpp
#include <iostream>
#include <stdio.h>
#include "cell.hpp"

using namespace std;

class Nonet {
private:
    string nonetID;
    bool nonetSolved;
    int solvedCount;
    Cell myCells[CELL_COUNT];
    int solvedCells[CELL_COUNT];
public:
    Nonet(string);
    ~Nonet();
    string getNonetID() { return nonetID; }
    int getSolvedCount() { return solvedCount; }
    int * cellsSolved();
    Cell & getCell(int);
    void fillNonet();
    void displayNonet();
    void nonetReduction();
};


#endif
