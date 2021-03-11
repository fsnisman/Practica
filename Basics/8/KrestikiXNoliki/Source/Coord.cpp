/*
������� ����������
1. ���������� ��������
2. ���������� ��
3. ���������� �������
*/

#include <iostream>
#include "gamestructur.h"

using namespace std;

Coord getHumanCoord(const Field& f)
{
    Coord c;

    do
    {
        while (true)
        {
            cout << "������� ����� ������: ";
            cin >> c.x;
            if (!cin)
            {
                cout << "������� �� �����, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.x < 1 || c.x > f.sizeX)
            {
                cout << "�������� ����� ������� �� �������� ������, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }

        }

        while (true)
        {
            cout << "������� ����� �������: ";
            cin >> c.y;
            if (!cin)
            {
                cout << "������� �� �����, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.y < 1 || c.y > f.sizeY)
            {
                cout << "�������� ����� ������� �� �������� ������, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }
        }
    } while (f.pCells[c.x - 1][c.y - 1] != EMPTY);

    c.x--;
    c.y--;

    return c;
};

Coord getAICoord(const Field& f)
{

    Coord c;

    size_t x;
    size_t y;


    for (;;)
    {
        x = rand() % f.sizeX;
        y = rand() % f.sizeY;
        if (f.pCells[x][y] == EMPTY)
        {
            c = { x, y };
            return c;
        }
    }

    return c;
};

Coord getPlayerCoord(const Field& f)
{
    Coord c;

    do
    {
        while (true)
        {
            cout << "������� ����� ������: ";
            cin >> c.x;
            if (!cin)
            {
                cout << "������� �� �����, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.x < 1 || c.x > f.sizeX)
            {
                cout << "�������� ����� ������� �� �������� ������, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }

        }

        while (true)
        {
            cout << "������� ����� �������: ";
            cin >> c.y;
            if (!cin)
            {
                cout << "������� �� �����, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.y < 1 || c.y > f.sizeY)
            {
                cout << "�������� ����� ������� �� �������� ������, ������� �����\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }
        }
    } while (f.pCells[c.x - 1][c.y - 1] != EMPTY);

    c.x--;
    c.y--;

    return c;
};