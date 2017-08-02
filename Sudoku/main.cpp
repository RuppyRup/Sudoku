#include <iostream>
#include "cell.hpp"
using namespace std;

int main() {
    Cell a1(1,1), a2(1,2);
    
    a1.displayCellAttributes();
    a1.removeOptionalValue(9);
    a1.removeOptionalValue(8);
    a1.removeOptionalValue(7);
    a1.removeOptionalValue(5);
    a1.removeOptionalValue(4);
    a1.removeOptionalValue(3);
    a1.removeOptionalValue(2);
    a1.removeOptionalValue(1);
    a1.displayCellAttributes();
    
    return 0;
}
