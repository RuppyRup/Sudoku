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
    Nonet & mostSolvedNonet();
    void displaySudoku();
    void sudokuReduction();
    void crossCheckRow(Cell &);
    void crossCheckColumn(Cell &);
    int crossCheckAll();
    int sudokuCellsSolved();
};





#endif /* sudoku_hpp */
