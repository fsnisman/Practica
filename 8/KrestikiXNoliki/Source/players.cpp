/*
РАЗМЕР ПОЛЯ.
ИГКРОКИ.
ВЫДЕЛЕНИЕ И ОЧИСТКА ПАМЯТИ ДЛЯ ПОЛЯ И КООРДИНАТ.
КТО ПЕРВЫЙ ХОДИТ ИЗ ИГРОКОВ РАНДОМНЫЙ СПОСОБ.
*/

#include <iostream>
#include <random>
#include <stdlib.h>
#include "gamestructur.h"

using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(0, 1);

int random()
{
    return distrib(gen);
};

void sizeField(Field& f)
{
    int size;

    cout << endl << endl;

    cout << "Размер поля (СТОЛБЦЫ X СТРОКИ)" << endl;
    while (true)
    {
        cout << "Введите число: ";
        cin >> size;
        if (!cin)
        {
            cout << "Введено не число, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size < 0)
        {
            cout << "Введеное отрицательное число, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size < 3)
        {
            cout << "Введеное маленькое число для построения поля, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else
        {
            break;
        }

    }

    f.sizeX = size;
    f.sizeY = f.sizeX;
    cout << endl << endl;
}

void initFieldPlayers(Field& f)
{
    sizeField(f);

    f.pCells = new Cell * [f.sizeX];
    for (size_t x = 0; x < f.sizeX; x++)
    {
        f.pCells[x] = new Cell[f.sizeY];

        for (size_t y = 0; y < f.sizeY; y++)
        {
            f.pCells[x][y] = EMPTY;
        }
    }

    if (random() > 0)
    {
        f.player1 = CROSS;
        f.player2 = ZERO;
        f.First = true;
    }
    else
    {
        f.player1 = ZERO;
        f.player2 = CROSS;
        f.First = false;
    }

    f.progress = GAME_IN_PROGRESS;

    clearScr();
};

void deinitField(Field& f)
{
    for (size_t x = 0; x < f.sizeX; x++)
    {
        delete[] f.pCells[x];
    }
    delete[] f.pCells;
    f.pCells = nullptr;
};