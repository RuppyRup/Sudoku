#include <iostream>
#include "cell.hpp"
using namespace std;

int main() {
    Cell a1(1,1), a2(1,2);
    
    a1.displayCellAttributes();
    a2.displayCellAttributes();
    a2.setCell(7);
    a2.displayCellAttributes();
    
    return 0;
}
