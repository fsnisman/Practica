#pragma once
#include <iostream>

enum Cell
{
    ZERO = '0',
    CROSS = 'X',
    EMPTY = '-',
};

enum GameProgress
{
    GAME_IN_PROGRESS,
    WON_HUMAN,
    WON_PLAYER1,
    WON_PLAYER2,
    WON_AI,
    DRAW
};

struct Field
{
    Cell** pCells;
    size_t sizeX;
    size_t sizeY;
    Cell human;
    Cell ai;
    Cell player1;
    Cell player2;
    bool First;
    string name1;
    string name2;
    GameProgress progress;
};

struct Coord
{
    size_t x;
    size_t y;
};
