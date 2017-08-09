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
    mySudoku.getNonet('A').getCell(7).setCell(4);
    mySudoku.getNonet('B').getCell(1).setCell(6);
    mySudoku.getNonet('B').getCell(3).setCell(2);
    mySudoku.getNonet('B').getCell(8).setCell(1);
    mySudoku.getNonet('C').getCell(9).setCell(9);
    mySudoku.getNonet('D').getCell(3).setCell(4);
    mySudoku.getNonet('D').getCell(6).setCell(7);
    mySudoku.getNonet('D').getCell(7).setCell(1);
    mySudoku.getNonet('D').getCell(8).setCell(8);
    mySudoku.getNonet('E').getCell(1).setCell(9);
    mySudoku.getNonet('E').getCell(3).setCell(8);
    mySudoku.getNonet('F').getCell(1).setCell(7);
    mySudoku.getNonet('F').getCell(4).setCell(2);
    mySudoku.getNonet('F').getCell(8).setCell(4);
    mySudoku.getNonet('F').getCell(9).setCell(6);
    mySudoku.getNonet('G').getCell(2).setCell(6);
    mySudoku.getNonet('G').getCell(8).setCell(5);
    mySudoku.getNonet('G').getCell(9).setCell(2);
    mySudoku.getNonet('H').getCell(1).setCell(7);
    mySudoku.getNonet('H').getCell(2).setCell(2);
    mySudoku.getNonet('H').getCell(3).setCell(1);
    mySudoku.getNonet('H').getCell(4).setCell(8);
    mySudoku.getNonet('H').getCell(6).setCell(9);
    mySudoku.getNonet('H').getCell(7).setCell(3);
    mySudoku.getNonet('H').getCell(9).setCell(4);
    mySudoku.getNonet('I').getCell(2).setCell(8);
    mySudoku.getNonet('I').getCell(7).setCell(9);
    mySudoku.getNonet('I').getCell(8).setCell(7);
    mySudoku.displaySudoku();
    mySudoku.sudokuReduction();
    
    /*int tmp = 0;
    int final = 0;
    do {
        tmp =  mySudoku.crossCheckAll();
        final =  mySudoku.crossCheckAll();
        cout << tmp << " : " << final << endl;
    } while (tmp < final);*/
    
    char non = 'G';
    int cell = 6;
    
    mySudoku.getNonet(non).getCell(cell).displayOptionals();
    
    mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(cell));
    
    //mySudoku.displaySudoku();
    
    mySudoku.getNonet(non).getCell(cell).displayOptionals();
    
    
    return 0;
}
