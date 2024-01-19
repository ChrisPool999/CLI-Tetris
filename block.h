#ifndef TETRIS_BLOCK
#define TETRIS_BLOCK

#include <vector>
#include <random>
#include "interface.h"
#include "color.h"

class Block
{
public:
    using blockShape = std::vector<std::vector<bool>>;

    void initializeShape(std::default_random_engine &gen, std::uniform_int_distribution<int>&d6);
    Block(std::default_random_engine &gen, std::uniform_int_distribution<int>&d6);
    void rotate();
    Color getColor();
    int getRotation();
    blockShape getShape();

private:
    int rotation = 0;
    Color color;
    blockShape shape;
};

#endif