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
    Cell myCells[CELL_COUNT];
public:
    Nonet(string);
    ~Nonet();
    string getNonetID() { return nonetID; }
    bool getNonetSolved() { return nonetSolved; }
    Cell & getCell(int);
    void fillNonet();
    void displayNonet();
};


#endif
