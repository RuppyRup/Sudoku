#include <iostream>
#include "cell.hpp"
#include "nonet.hpp"
using namespace std;

int main() {

    Nonet A("A");
    
    
    A.getCell(2).displayCellAttributes();
    A.getCell(5).setCell(4);
    A.getCell(3).setCell(9);
    A.getCell(5).displayCellAttributes();
    A.displayNonet();
    int * array = A.cellsSolved();
    cout << "Cells solved = " << array[0] << " " << array[1] << endl;
    
    return 0;
}
