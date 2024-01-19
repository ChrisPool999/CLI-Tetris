#ifndef TETRIS_INTERFACE
#define TETRIS_INTERFACE

#include <vector>
#include <unistd.h>
#include "block.h"
#include "color.h"

struct GridPosition
{
    size_t col;
    size_t row;
};

class Interface
{

public:
    Interface();
    ~Interface();
    void drawNewFrame();
    void addNewBlock();

private:
    size_t const BLOCK_WIDTH = 5;
    size_t const BLOCK_HEIGHT = 2;
    size_t const SCR_WIDTH = (BLOCK_WIDTH * 30) + 1;
    size_t const SCR_HEIGHT = (BLOCK_HEIGHT * 15) + 1;
    void turnOffNcurses();
    void enableNcurses();
    int getColor_Pair(Color);
    using colorGrid = std::vector<std::vector<Color>>;
    colorGrid gameUI = colorGrid(SCR_HEIGHT, std::vector<Color>(SCR_WIDTH, Color::BLACK));
};

#endif