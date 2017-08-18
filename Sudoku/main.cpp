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
    mySudoku.getNonet('A').getCell(4).setCell(6);
    mySudoku.getNonet('A').getCell(6).setCell(2);
    mySudoku.getNonet('A').getCell(7).setCell(9);
    mySudoku.getNonet('B').getCell(1).setCell(8);
    mySudoku.getNonet('B').getCell(6).setCell(4);
    mySudoku.getNonet('B').getCell(9).setCell(7);
    mySudoku.getNonet('C').getCell(5).setCell(5);
    mySudoku.getNonet('D').getCell(3).setCell(3);
    mySudoku.getNonet('D').getCell(7).setCell(1);
    mySudoku.getNonet('D').getCell(8).setCell(5);
    mySudoku.getNonet('E').getCell(1).setCell(6);
    mySudoku.getNonet('E').getCell(3).setCell(1);
    mySudoku.getNonet('E').getCell(5).setCell(3);
    mySudoku.getNonet('E').getCell(9).setCell(2);
    mySudoku.getNonet('F').getCell(1).setCell(9);
    mySudoku.getNonet('F').getCell(2).setCell(8);
    mySudoku.getNonet('F').getCell(9).setCell(7);
    mySudoku.getNonet('G').getCell(2).setCell(1);
    mySudoku.getNonet('G').getCell(4).setCell(2);
    mySudoku.getNonet('G').getCell(6).setCell(5);
    mySudoku.getNonet('G').getCell(8).setCell(9);
    mySudoku.getNonet('H').getCell(3).setCell(9);
    mySudoku.getNonet('H').getCell(4).setCell(4);
    mySudoku.getNonet('H').getCell(7).setCell(5);
    mySudoku.getNonet('I').getCell(2).setCell(2);
    mySudoku.getNonet('I').getCell(7).setCell(4);
    mySudoku.getNonet('I').getCell(8).setCell(1);
    
    
    /** Set additional cells for testing purposes
    
    mySudoku.getNonet('H').getCell(6).setCell(6);**/
    

    mySudoku.displaySudoku();
    
    /** Need to debug using individual nonets.
     Cells are trying to be set that have already been set
     **/
    
    
    
    
    mySudoku.sudokuReduction();
    
    int tmp = 0;
    int final = 0;
    do {
        tmp =  mySudoku.sudokuCellsSolved();
        mySudoku.crossCheckAll();
        mySudoku.sudokuReduction();
        final =  mySudoku.sudokuCellsSolved();;
        cout << tmp << " : " << final << endl;
    } while (tmp < final);
    
    /** need to solve for hidden pairs -> two pairs in different cells 
     of a nonet. The two cells must contain one of this pair, so the options
     additional to this pair can be deleted from these cells. **/
    
    if (final < 81) {
        char mostSolvedNonet = 'x';
        int mostSolvedCells = 0;
        int solvedCells = 8;
        while (solvedCells-- != 0) {
            for (int i = 0; i < NONET_COUNT; i++) {
                if (mySudoku.getNonet((char)(65 + i)).isNonetSolved()) {
                    continue;
                }
                if (mySudoku.getNonet((char)(65 + i)).getSolvedCount() == solvedCells) {
                    //cout << "Nonet " << (char)(65 + i) << " has solved " << solvedCells << " cells" << endl;
                    if (solvedCells > mostSolvedCells) {
                        mostSolvedCells = solvedCells;
                        mostSolvedNonet = (char)(65 + i);
                    }
                }
            }
        }
        int solutions = CELL_COUNT - mostSolvedCells;
        cout << "Nonet " << mostSolvedNonet << " has " << solutions << " cells unsolved" << endl;
        int * solutionArray = new int[solutions];
        solutionArray = mySudoku.getNonet(mostSolvedNonet).returnSolvedCells();
        for (int i = 0; i < solutions; i++) {
            cout << "Solution Cell: " << solutionArray[i] << endl;
        }
        
        
        
        delete [] solutionArray;
    }
    /**
    
    
    mySudoku.getNonet(non).nonetReduction();
    mySudoku.getNonet(non).nonetFindUniqueOptionals();
    for (int i = 1; i <= CELL_COUNT; i++) {
        mySudoku.crossCheckRow(mySudoku.getNonet(non).getCell(i));
        mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(i));
    }
    
   
     **/
    
    //int cell1 = 6;
    //int cell2 = 9;
    
    //mySudoku.getNonet(non).getCell(cell).displayOptionals();
    
    /*mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(cell1));
    mySudoku.crossCheckColumn(mySudoku.getNonet(non).getCell(cell2));
    mySudoku.crossCheckRow(mySudoku.getNonet(non).getCell(cell1));
    mySudoku.crossCheckRow(mySudoku.getNonet(non).getCell(cell2));*/
    
    //mySudoku.getNonet(non).getCell(cell1).removeOptionalValue(7);
    //mySudoku.getNonet(non).getCell(cell2).removeOptionalValue(7);
    
    /**mySudoku.getNonet(non).cellsSolved();
    mySudoku.getNonet(non).displayCellsSolved();
    mySudoku.getNonet(non).nonetSetCell(mySudoku.getNonet('H').getCell(6), 2);**/
    
    char non = 'H';
    cout << "Solved count for nonet " << non << " " << mySudoku.getNonet(non).getSolvedCount() << endl;
    
    mySudoku.displaySudoku();
    
    for (int i = 1; i <= CELL_COUNT; i++) {
        mySudoku.getNonet(non).getCell(i).displayCellAttributes();
    }
    
    
    
    return 0;
}
