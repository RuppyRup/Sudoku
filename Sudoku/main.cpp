#include <iostream>
#include "cell.hpp"
#include "nonet.hpp"
using namespace std;

int main() {

    Nonet A('A');
    
    A.getCell(1).setCell(1);
    A.getCell(2).setCell(2);
    A.getCell(3).setCell(3);
    A.getCell(5).setCell(5);
    A.getCell(6).setCell(6);
    A.getCell(7).removeOptionalValue(8);
    A.getCell(8).removeOptionalValue(8);
    A.getCell(9).setCell(9);
    A.displayNonet();
    A.nonetReduction();
    for(int i = 1; i <= CELL_COUNT; i++) {
        A.getCell(i).displayCellAttributes();
    }
    cout << A.isNonetSolved() << endl;
       
    return 0;
}
