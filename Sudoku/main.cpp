#include <iostream>
#include <vector>
#include <map>
#include "cell.hpp"
#include "nonet.hpp"
#include "sudoku.hpp"


int solveSudoku(Sudoku &s) {
    /** Runs code to solve sudoku and returns the final count
     of solved cells**/
    s.sudokuReduction();
    int tmp = 0;
    int final = 0;
    do {
        tmp =  s.sudokuCellsSolved();
        s.crossCheckAll();
        s.sudokuReduction();
        final =  s.sudokuCellsSolved();
        cout << tmp << " : " << final << endl;
    } while (tmp < final);
    
    return final;
}


using namespace std;

int main() {
    //Nonet A('A'), B('B');
    //Nonet array[2] = {A, B};
    Sudoku mySudoku;
    // Sunday Times Warm-Up Sudoku
    /**mySudoku.getNonet('A').getCell(4).setCell(6);
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
    mySudoku.getNonet('I').getCell(8).setCell(1);**/
    mySudoku.getNonet('A').getCell(3).setCell(7);
     mySudoku.getNonet('A').getCell(4).setCell(9);
     mySudoku.getNonet('A').getCell(8).setCell(8);
     mySudoku.getNonet('B').getCell(1).setCell(2);
     mySudoku.getNonet('B').getCell(5).setCell(8);
     mySudoku.getNonet('B').getCell(9).setCell(1);
     mySudoku.getNonet('C').getCell(4).setCell(5);
     mySudoku.getNonet('C').getCell(5).setCell(6);
     mySudoku.getNonet('C').getCell(6).setCell(7);
     mySudoku.getNonet('D').getCell(4).setCell(1);
     mySudoku.getNonet('D').getCell(8).setCell(9);
     mySudoku.getNonet('D').getCell(9).setCell(4);
     mySudoku.getNonet('E').getCell(3).setCell(6);
     mySudoku.getNonet('E').getCell(7).setCell(8);
     mySudoku.getNonet('F').getCell(1).setCell(3);
     mySudoku.getNonet('F').getCell(2).setCell(9);
     mySudoku.getNonet('F').getCell(6).setCell(4);
     mySudoku.getNonet('G').getCell(4).setCell(2);
     mySudoku.getNonet('G').getCell(5).setCell(6);
     mySudoku.getNonet('G').getCell(6).setCell(3);
     mySudoku.getNonet('H').getCell(1).setCell(6);
     mySudoku.getNonet('H').getCell(5).setCell(7);
     mySudoku.getNonet('H').getCell(9).setCell(5);
     mySudoku.getNonet('I').getCell(2).setCell(4);
     mySudoku.getNonet('I').getCell(6).setCell(8);
     mySudoku.getNonet('I').getCell(7).setCell(2);
         

    mySudoku.displaySudoku();
    
    /** Need to debug using individual nonets.
     Cells are trying to be set that have already been set
     **/
    
    
    
    
    
    
    /** need to solve for hidden pairs -> two pairs in different cells 
     of a nonet. The two cells must contain one of this pair, so the options
     additional to this pair can be deleted from these cells. **/
    
    if (solveSudoku(mySudoku) == 81) {
        cout << "Sudoku has been solved" << endl;
        mySudoku.displaySudoku();
        return 0;
    }
    
    Sudoku tmpSudoku = mySudoku;
    //Nonet & mostSolvedNonet = tmpSudoku.mostSolvedNonet();
    //map<int, int *> solutionArray = mostSolvedNonet.returnUnSolvedCells();
    Nonet & mostSolvedNonet = tmpSudoku.mostSolvedNonet();
    map<int, int *> solutionArray = mostSolvedNonet.returnUnSolvedCells();
    for (int n = 0; n < 1; n++) {
        tmpSudoku = mySudoku;
        // Need to store current sudoku before guessing
       
        
        //int solutions = CELL_COUNT - mostSolvedCells;
        //cout << "Nonet " << mostSolvedNonet << " has "  << " cells unsolved" << endl;
        //int * solutionArray = new int[solutions];
        
        for (auto it: solutionArray) {
            cout << "optional: " << it.first << " : " << it.second[0] << ", " << it.second[1] << endl;
            Cell & cellTotry = mostSolvedNonet.getCell(it.first);

            int options = cellTotry.getOptionalCount();
            for (int i = 0; i < options; i++ ) {
                tmpSudoku = mySudoku;
                mostSolvedNonet = tmpSudoku.mostSolvedNonet();
                mostSolvedNonet.nonetSetCell(cellTotry, it.second[i]);
                tmpSudoku.displaySudoku();
                if (solveSudoku(tmpSudoku) == 81) {
                    mySudoku = tmpSudoku;
                    cout << "Sudoku has been solved" << endl;
                    mySudoku.displaySudoku();
                    return 0;
                    
                }
            }

            //mySudoku.getNonet(mostSolvedNonet).getCell(it->first).setCell(it->second[0]);
            //cellTotry.setCell(it->second[0]);
        }
    }
    
    cout << "Solution has failed!!" << endl;
    mySudoku.displaySudoku();
        
        /** need to implment unsolved cells map to get options to try
        
        //solutionArray = mySudoku.getNonet(mostSolvedNonet).returnSolvedCells();
        for (int i = 0; i < solutions; i++) {
            cout << "Solution Cell: " << solutionArray[i] << endl;
        }**/
        
        //mySudoku.getNonet('H').getCell(6).setCell(6);
        
        //delete[] solutionArray;
    
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
    
    
    
    return 1;
}
