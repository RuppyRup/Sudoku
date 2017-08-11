#ifndef nonet_hpp
#define nonet_hpp
#include <iostream>
#include <stdio.h>
#include "cell.hpp"

using namespace std;

class Nonet {
private:
    char nonetID;
    bool nonetSolved;
    int solvedCount;
    Cell myCells[CELL_COUNT];
    int solvedCells[CELL_COUNT];
public:
    Nonet();
    ~Nonet();
    char getNonetID() { return nonetID; }
    void setNonetID(char);
    bool isNonetSolved();
    int getSolvedCount();
    void cellsSolved();
    Cell & getCell(int);
    bool nonetSetCell(Cell &, int);
    void fillNonet();
    void displayNonet();
    void nonetReduction();
    void nonetFindUniqueOptionals();
};

#endif
