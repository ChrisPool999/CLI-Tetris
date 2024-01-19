#include <stdexcept>
#include "block.h"

void Block::initializeShape(std::default_random_engine &gen, std::uniform_int_distribution<int>&d6)
{
    switch (d6(gen))
    {
        case 0:
            color = Color::YELLOW;
            shape = { {1, 1}, {1, 1} };
            return;
        case 1:
            color = Color::BLUE;
            shape = { {1}, {1}, {1}, {1} };
            return;
        case 2:
            color = Color::RED;
            shape = { {0, 0, 1, 1}, {1, 1, 0, 0} };
            return;
        case 3:
            color = Color::GREEN;
            shape = { {1, 1, 0}, {0, 1, 1} };
            return;
        case 4:
            color = Color::MAGENTA;
            shape = { {0, 1}, {0, 1}, {1, 1} };
            return;
        case 5:
            color = Color::CYAN;
            shape = { {1, 1, 1}, {0, 1, 0} };
            return;
        default:
            throw std::runtime_error("unexpected value from uniform_int_distribution. ");
    }
}

Block::Block(std::default_random_engine &gen, std::uniform_int_distribution<int> &d6)
{
    initializeShape(gen, d6);
}

void Block::rotate()
{
    rotation += 90;
    if (rotation == 360)
    {
        rotation = 0;
    }
}

Color Block::getColor()
{
    return color;
}

int Block::getRotation()
{
    if (rotation != 0 && rotation != 90 && rotation != 180 && rotation != 270)
    {
        throw std::runtime_error("rotation invalid state. ");
    }
    return rotation;
}

Block::blockShape Block::getShape()
{
    return shape;
}