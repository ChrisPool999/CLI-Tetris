#include <ncurses.h>
#include "block.h"
#include "interface.h"

int main()
{  
    Interface myInterface = Interface();
    myInterface.drawNewFrame();
    myInterface.addNewBlock();
    getch();
    return 0;
}
