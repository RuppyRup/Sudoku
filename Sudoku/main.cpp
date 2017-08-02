#include <iostream>
#include "cell.hpp"
#include "nonet.hpp"
using namespace std;

int main() {

    Nonet A("A");
    
    
    A.fillNonet();
    A.getCell(5).setCell(4);
    A.getCell(3).setCell(9);
    
    A.displayNonet();
    
    return 0;
}
