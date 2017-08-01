#include <iostream>
#include "cell.hpp"
using namespace std;

int main() {
    Cell a1(1,1), a2(1,2);
    
    a1.displayCellAttributes();
    a1.removeOptionalValue(5);
    a1.displayCellAttributes();
    
    return 0;
}
