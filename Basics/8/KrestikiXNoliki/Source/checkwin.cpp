/*
опнбепйю мю онаедс анрю хкх векнбейю.
опнбепйю мю онаедс хцпнйю.
*/

#include <iostream>
#include "gamestructur.h"

bool checkWinBot(Field& f, char XY)
{

    size_t winHorizontal = 0;
    size_t winVertical = 0;
    size_t winDiagonal1 = 0;
    size_t winDiagonal2 = 0;

    for (size_t x = 0; x < f.sizeX; x++)
    {
        for (size_t y = 0; y < f.sizeY; y++)
        {
            if (f.pCells[x][y] == XY)
            {
                winHorizontal++;
            }
            if (f.pCells[y][x] == XY)
            {
                winVertical++;
            }
            if (x == y && f.pCells[y][x] == XY)
            {
                winDiagonal1++;
            }
            if (x == (f.sizeY - 1 - y) && f.pCells[x][y] == XY)
            {
                winDiagonal2++;
            }
        }
        if (winHorizontal == f.sizeX || winVertical == f.sizeY || winDiagonal1 == f.sizeY || winDiagonal2 == f.sizeY)
        {
            if (f.human == XY)
            {
                f.progress = WON_HUMAN;
            }
            else
            {
                f.progress = WON_AI;
            }
            return true;
        }
        else {
            winHorizontal = 0;
            winVertical = 0;
        }
    }

    return false;
};

bool checkWinPlayer(Field& f, char XY)
{

    size_t winHorizontal = 0;
    size_t winVertical = 0;
    size_t winDiagonal1 = 0;
    size_t winDiagonal2 = 0;

    for (size_t x = 0; x < f.sizeX; x++)
    {
        for (size_t y = 0; y < f.sizeY; y++)
        {
            if (f.pCells[x][y] == XY)
            {
                winHorizontal++;
            }
            if (f.pCells[y][x] == XY)
            {
                winVertical++;
            }
            if (x == y && f.pCells[y][x] == XY)
            {
                winDiagonal1++;
            }
            if (x == (f.sizeY - 1 - y) && f.pCells[x][y] == XY)
            {
                winDiagonal2++;
            }
        }
        if (winHorizontal == f.sizeX || winVertical == f.sizeY || winDiagonal1 == f.sizeY || winDiagonal2 == f.sizeY)
        {
            if (f.player1 == XY)
            {
                f.progress = WON_PLAYER1;
            }
            else
            {
                f.progress = WON_PLAYER2;
            }
            return true;
        }
        else {
            winHorizontal = 0;
            winVertical = 0;
        }
    }

    return false;
};