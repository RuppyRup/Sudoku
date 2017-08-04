#include <iostream>
#include "cell.hpp"
#include "nonet.hpp"
#include "sudoku.hpp"
using namespace std;

int main() {
    Nonet A('A'), B('B');
    Nonet array[2] = {A, B};
    Sudoku mySudoku(array);
    
    A.getCell(1).setCell(1);
    A.getCell(2).setCell(2);
    A.getCell(3).setCell(3);
    A.getCell(4).removeOptionalValue(7);
    A.getCell(5).setCell(5);
    A.getCell(6).removeOptionalValue(7);
    A.getCell(6).removeOptionalValue(6);
    A.getCell(7).removeOptionalValue(7);
    A.getCell(7).removeOptionalValue(6);
    A.getCell(8).removeOptionalValue(8);
    A.getCell(8).removeOptionalValue(6);
    A.getCell(9).setCell(9);
    A.nonetReduction();
    /*for(int i = 1; i <= CELL_COUNT; i++) {
        A.getCell(i).displayCellAttributes();
    }*/
    A.displayNonet();
    A.nonetReduction();
    A.nonetFindUniqueOptionals();
    /*for(int i = 1; i <= CELL_COUNT; i++) {
        A.getCell(i).displayCellAttributes();
    }*/
    A.displayNonet();
       
    return 0;
}
