#ifndef sudoku_hpp
#define sudoku_hpp
#include <iostream>
using namespace std;
#define NONET_COUNT 9
#include <stdio.h>
#include "nonet.hpp"


class Sudoku {
private:
    Nonet myNonets[NONET_COUNT];
public:
    Sudoku();
    ~Sudoku();
    void fillSudoku();
    Nonet & getNonet(char nonetID);
};





#endif /* sudoku_hpp */
