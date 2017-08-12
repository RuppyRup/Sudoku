#include <iostream>
#include "cell.hpp"
#include "nonet.hpp"
#include "sudoku.hpp"
using namespace std;

int main() {
    //Nonet A('A'), B('B');
    //Nonet array[2] = {A, B};
    Sudoku mySudoku;
    // Sunday Times Warm-Up Sudoku
    mySudoku.getNonet('A').getCell(3).setCell(7);
    mySudoku.getNonet('A').getCell(6).setCell(1);
    mySudoku.getNonet('A').getCell(8).setCell(9);
    mySudoku.getNonet('B').getCell(4).setCell(4);
    mySudoku.getNonet('B').getCell(5).setCell(2);
    mySudoku.getNonet('B').getCell(6).setCell(6);
    mySudoku.getNonet('B').getCell(9).setCell(8);
    mySudoku.getNonet('C').getCell(1).setCell(5);
    mySudoku.getNonet('C').getCell(2).setCell(2);
    mySudoku.getNonet('C').getCell(6).setCell(7);
    mySudoku.getNonet('C').getCell(9).setCell(4);
    mySudoku.getNonet('D').getCell(3).setCell(6);
    mySudoku.getNonet('D').getCell(5).setCell(3);
    mySudoku.getNonet('D').getCell(6).setCell(9);
    mySudoku.getNonet('D').getCell(7).setCell(2);
    mySudoku.getNonet('E').getCell(4).setCell(1);
    mySudoku.getNonet('E').getCell(8).setCell(4);
    mySudoku.getNonet('F').getCell(1).setCell(4);
    mySudoku.getNonet('F').getCell(2).setCell(8);
    mySudoku.getNonet('F').getCell(5).setCell(5);
    mySudoku.getNonet('F').getCell(8).setCell(7);
    mySudoku.getNonet('H').getCell(2).setCell(7);
    mySudoku.getNonet('H').getCell(3).setCell(9);
    mySudoku.getNonet('H').getCell(5).setCell(6);
    mySudoku.getNonet('H').getCell(7).setCell(3);
    mySudoku.getNonet('I').getCell(2).setCell(4);
    mySudoku.getNonet('I').getCell(3).setCell(2);
    mySudoku.getNonet('I').getCell(4).setCell(9);

    mySudoku.displaySudoku();
    mySudoku.sudokuReduction();
    
    int tmp = 0;
    int final = 0;
    do {
        tmp =  mySudoku.sudokuCellsSolved();
        mySudoku.crossCheckAll();
        mySudoku.sudokuReduction();
        final =  mySudoku.sudokuCellsSolved();
        cout << tmp << " : " << final << endl;
    } while (tmp < final);
    
    
    mySudoku.sudokuReduction();
    
    /*mySudoku.crossCheckAll();
    mySudoku.crossCheckAll();
    mySudoku.crossCheckAll();
    mySudoku.crossCheckAll();*/
    
    char non = 'H';
    int cell1 = 6;
    int cell2 = 9;
    
    //mySudoku.getNonet(non).getCell(cell).displayOptionals();
    
    /*mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(cell1));
    mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(cell2));
    mySudoku.crossCheckRow(mySudoku.getNonet(non).getCell(cell1));
    mySudoku.crossCheckRow(mySudoku.getNonet(non).getCell(cell2));*/
    
    //mySudoku.getNonet(non).getCell(cell1).removeOptionalValue(7);
    //mySudoku.getNonet(non).getCell(cell2).removeOptionalValue(7);
    mySudoku.displaySudoku();
    
    mySudoku.getNonet(non).getCell(cell1).displayCellAttributes();
    mySudoku.getNonet(non).getCell(cell2).displayCellAttributes();
    
    return 0;
}
