#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "interface.h"

Interface::Interface()  
{
    enableNcurses();

    for (size_t i = 0; i < SCR_HEIGHT; i++) 
    {
        for (size_t j = 0; j < SCR_WIDTH; j++)
        {
            bool isBorder = (i == 0 || i == SCR_HEIGHT - 1 || j == 0 || j == SCR_WIDTH - 1);
            gameUI[i][j] = (isBorder ? Color::WHITE : Color::BLACK);
        }
    }   
}

Interface::~Interface()
{
    turnOffNcurses();
}

void Interface::turnOffNcurses()
{
    endwin();    
}

void Interface::enableNcurses()
{
    initscr();
    start_color();
    noecho();
    clear();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_GREEN, COLOR_GREEN);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_BLUE, COLOR_BLUE);
    init_pair(6, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(7, COLOR_CYAN, COLOR_CYAN);
    init_pair(8, COLOR_WHITE, COLOR_WHITE);
}

int Interface::getColor_Pair(Color newColor)
{
    switch (newColor)
    {
        case Color::BLACK:
            return COLOR_PAIR(1);
        case Color::RED:
            return COLOR_PAIR(2);
        case Color::GREEN:
            return COLOR_PAIR(3);
        case Color::YELLOW:
            return COLOR_PAIR(4);
        case Color::BLUE:
            return COLOR_PAIR(5);
        case Color::MAGENTA:
            return COLOR_PAIR(6);
        case Color::CYAN:
            return COLOR_PAIR(7);
        case Color::WHITE:
            return COLOR_PAIR(8);
        default:
            throw std::invalid_argument("getColor_Pair() - Unhandled color");
    }
}

void Interface::drawNewFrame()
{
    for (size_t i = 0; i < SCR_HEIGHT; i++) 
    {
        for (size_t j = 0; j < SCR_WIDTH; j++)
        {
            int attrValue = getColor_Pair(gameUI[i][j]);

            attron(attrValue);
            mvaddch(static_cast<int>(i), static_cast<int>(j), ' ');                       
            attroff(attrValue);
        }
    }    
    refresh();
}

void Interface::addNewBlock()
{
    size_t newBlockStart = (SCR_WIDTH / 2) - (BLOCK_WIDTH / 2);
    size_t newBlockEnd   = (SCR_WIDTH / 2) + (BLOCK_WIDTH / 2);

    if (newBlockStart <= 0 || newBlockEnd >= SCR_WIDTH) 
    {
        throw std::runtime_error("Screen size too small to fit block size. ");
    }

    for (size_t i = 1; i <= BLOCK_HEIGHT; i++) 
    {
        for (size_t j = newBlockStart; j < newBlockEnd; j++)
        {
            attron(getColor_Pair(Color::BLUE));
            mvaddch(static_cast<int>(i), static_cast<int>(j), ' ');                       
            attroff(getColor_Pair(Color::BLUE));
        }
    }    
    refresh();
}