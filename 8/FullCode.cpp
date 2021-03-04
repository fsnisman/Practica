#include <iostream>
#include <random>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>


using namespace std;

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(0, 1);


//====================================================================================

enum ConsoleColorText
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void SetColor(int text)
{
    HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(Color, text);
}

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


//====================================================================================

void clearScr()
{
    system("cls");
};

//====================================================================================

int random()
{
    return distrib(gen);
};

//====================================================================================

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
    cout << endl<< endl;
}

void initFieldbot(Field& f)
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
        f.human = CROSS;
        f.ai = ZERO;
        f.First = true;
    }
    else
    {
        f.human = ZERO;
        f.ai = CROSS;
        f.First = false;
    }

    f.progress = GAME_IN_PROGRESS;

    clearScr();
};

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

//====================================================================================

Coord getHumanCoord(const Field& f)
{
    Coord c;

    do
    {
        while (true)
        {
            cout << "Введите номер строки: ";
            cin >> c.x;
            if (!cin)
            {
                cout << "Введено не число, введите снова\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.x < 1 || c.x > f.sizeX)
            {
                cout << "Введеное число выходит за диапозон клеток, введите снова\n";
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
            cout << "Введите номер столбца: ";
            cin >> c.y;
            if (!cin)
            {
                cout << "Введено не число, введите снова\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.y < 1 || c.y > f.sizeY)
            {
                cout << "Введеное число выходит за диапозон клеток, введите снова\n";
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
            cout << "Введите номер строки: ";
            cin >> c.x;
            if (!cin)
            {
                cout << "Введено не число, введите снова\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.x < 1 || c.x > f.sizeX)
            {
                cout << "Введеное число выходит за диапозон клеток, введите снова\n";
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
            cout << "Введите номер столбца: ";
            cin >> c.y;
            if (!cin)
            {
                cout << "Введено не число, введите снова\n";
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (c.y < 1 || c.y > f.sizeY)
            {
                cout << "Введеное число выходит за диапозон клеток, введите снова\n";
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

//====================================================================================

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

//====================================================================================

void WelcomeToTheClubBuddy()
{
    SetColor(Yellow);
    cout << "__$$$_____$$$$___$$$$$___$$$$$____$$$$  $$$$$$___$$$$___$$_$_$$___$$$$______$$$___$$$$___$$$$$____$$$$___$$$$$$__$$" << endl;
    cout << "_$$_$$___$$__$$__$$______$$__$$__$$__$$ $$__$$__$$__$$___$$$$$___$$__$$____$_$$__$$__$$__$$__$$__$$__$$____$$____$$" << endl;
    cout << "_$$_$$___$$__$$__$$$$$___$$$$$$__$$__$$ $$__$$__$$__$$____$$$____$$$$$$___$__$$__$$__$$__$$$$$___$$$$$$____$$____$$$$" << endl;
    cout << "$$$$$$$__$$__$$__$$__$$__$$______$$__$$ $$__$$__$$__$$___$$$$$___$$__$$__$$__$$__$$__$$__$$__$$__$$__$$____$$____$$__$$" << endl;
    cout << "$_____$___$$$$___$$$$$___$$_______$$$$  $$__$$___$$$$___$$_$_$$__$$__$$__$$__$$___$$$$___$$$$$___$$__$$____$$____$$$$$" << endl << endl;
    cout << "                                                $$$$$" << endl;
    cout << "                                                $$__$$" << endl;
    cout << "                                                $$$$$" << endl;
    cout << "                                                $$__$$" << endl;
    cout << "                                                $$$$$" << endl << endl;
    cout << "$$__$$__$$$$$___$$$$$$___$$$$___$$$$$$__$$__$$__$$__$$__$$__$$  $$__$$  $$__$$___$$$$______$$$__$$__$$__$$__$$__$$__$$" << endl;
    cout << "$$_$$___$$__$$__$$______$$__$$____$$____$$__$$__$$_$$___$$__$$  _$$$$   $$__$$__$$__$$____$_$$__$$__$$__$$_$$___$$__$$" << endl;
    cout << "$$$$____$$$$$$__$$$$____$$________$$____$$_$$$__$$$$____$$_$$$  __$$    $$$$$$__$$__$$___$__$$__$$_$$$__$$$$____$$_$$$" << endl;
    cout << "$$_$$___$$______$$______$$__$$____$$____$$$_$$__$$_$$___$$$_$$  _$$$$   $$__$$__$$__$$__$$__$$__$$$_$$__$$_$$___$$$_$$" << endl;
    cout << "$$__$$__$$______$$$$$$___$$$$_____$$____$$__$$__$$__$$__$$__$$  $$__$$  $$__$$___$$$$___$$__$$__$$__$$__$$__$$__$$__$$" << endl << endl;
    SetColor(White);
}

void printStart(Field& f)
{
    char yn;
    char N = 78;
    char Y = 89;
    char n = 110;
    char y = 121;

    while (true)
    {
        cout << "Начать играть? (Y/N): ";
        cin >> yn;
        if (yn != y && yn != n && yn != N && yn != Y)
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == n || yn == N)
        {
            exit(0);
        }
        else
        {
            break;
        }
    }

    cout << endl;

    SetColor(Green);
    cout << "Справка: " << endl;
    SetColor(White);
    cout << "1. Кто первый совершает ход выпадает рандомно. Так что, у кого выпал 'Крестик' тот и будет ходить первым. " << endl << "2. Размер поля задается в ручную. Оно работает 3х3, 4х4, 5х5 и т.д." << endl << "3. Ты можешь играть один с компьютером, либо с кем-нибудь" << endl;
    SetColor(Green);
    cout << "Удачной игры!" << endl << endl;
    SetColor(White);
}

void printFieldBot(Field& f)
{

    cout << "";

    cout << "Игрок ходить: " << char(f.human) << endl;
    cout << "Компьютер ходить: " << char(f.ai) << endl << endl;

    cout << "    ";

    for (size_t x = 0; x < f.sizeX; x++)
    {
        if (x < 9)
        {
            cout << x + 1 << "  ";
        }
        else
        {
            cout << x + 1 << " ";
        }
    }
    cout << endl;
    for (size_t x = 0; x < f.sizeX; x++)
    {
        cout << " " << "|";
        for (size_t y = 0; y < f.sizeY; y++)
        {
            cout << "  " << (char)f.pCells[x][y];
        }
        cout << " | " << x + 1 << endl;
    }
    cout << endl;
}

void printNamePlayer(Field& f)
{
    cout << "Введите ваши имена" << endl;
    cout << "Первый игкрок: " << endl;
    cin >> f.name1;
    cout << "Второй игкрок: " << endl;
    cin >> f.name2;
    cout << endl;
}

void printFieldPlayer(Field& f)
{

    cout << "Игрок " << f.name1 << " ходит: " << char(f.player1) << endl;
    cout << "Игрок " << f.name2 << " ходит: " << char(f.player2) << endl << endl;

    cout << "    ";

    for (size_t x = 0; x < f.sizeX; x++)
    {
        if (x < 9)
        {
            cout << x + 1 << "  ";
        }
        else
        {
            cout << x + 1 << " ";
        }
    }
    cout << endl;
    for (size_t x = 0; x < f.sizeX; x++)
    {
        cout << " " << "|";
        for (size_t y = 0; y < f.sizeY; y++)
        {
            cout << "  " << (char)f.pCells[x][y];
        }
        cout << " | " << x + 1 << endl;
    }
    cout << endl;
}

void printWonOrDrawBot(const Field& field)
{
    if (field.progress == DRAW)
    {
        cout << "Ничья" << endl << endl;
    }
    else if (field.progress == WON_HUMAN)
    {
        SetColor(Green);
        cout << "Вы победили!" << endl << endl;
        SetColor(White);
    }
    else if (field.progress == WON_AI)
    {
        SetColor(Red);
        cout << "Вы прогирали..." << endl << endl;
        SetColor(White);
    }

};

void printWonOrDrawPlayers(const Field& field)
{
    if (field.progress == DRAW)
    {
        cout << "Ничья" << endl << endl;
    }
    else if (field.progress == WON_PLAYER1)
    {
        SetColor(Green);
        cout << "Победил игрок: " << field.name1 << endl << endl;
        SetColor(White);
    }
    else if (field.progress == WON_PLAYER2)
    {
        SetColor(Green);
        cout << "Победил игрок: " << field.name2 << endl << endl;
        SetColor(White);
    }

};
//====================================================================================

int main()
{

    setlocale(LC_ALL, "Russian");

    char yn;
    char N = 78;
    char Y = 89;
    char n = 110;
    char y = 121;

    Field field;
    WelcomeToTheClubBuddy();
    printStart(field);

    size_t turn = (field.First) ? 0 : 1;
    size_t turnNumber = 1;

    Coord c;

    while (true)
    {
        cout << "Вы будете играть один? (Y/N): ";
        cin >> yn;
        if (yn != y && yn != n && yn != N && yn != Y)
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == y || yn == Y)
        {
            initFieldbot(field);

            while (field.progress == GAME_IN_PROGRESS)
            {
                printFieldBot(field);

                if (turn % 2 == 0)
                {
                    c = getHumanCoord(field);
                    field.pCells[c.x][c.y] = field.human;
                }
                else
                {
                    c = getAICoord(field);
                    field.pCells[c.x][c.y] = field.ai;
                }

                turn++;

                clearScr();

                if (!checkWinBot(field, field.human) && !checkWinBot(field, field.ai))
                {
                    if (turnNumber == field.sizeX * field.sizeX)
                    {
                        field.progress = DRAW;
                    };
                }

                turnNumber++;
            }

            printFieldBot(field);
            printWonOrDrawBot(field);
            break;
        }
        else if (yn == n || yn == N)
        {
            initFieldPlayers(field);
            printNamePlayer(field);

            while (field.progress == GAME_IN_PROGRESS)
            {
                printFieldPlayer(field);

                if (turn % 2 == 0)
                {
                    c = getPlayerCoord(field);
                    field.pCells[c.x][c.y] = field.player1;
                }
                else
                {
                    c = getPlayerCoord(field);
                    field.pCells[c.x][c.y] = field.player2;
                }

                turn++;

                clearScr();

                if (!checkWinPlayer(field, field.player1) && !checkWinPlayer(field, field.player2))
                {
                    if (turnNumber == field.sizeX * field.sizeX)
                    {
                        field.progress = DRAW;
                    };
                }

                turnNumber++;
            }

            printFieldPlayer(field);
            printWonOrDrawPlayers(field);
            break;
        }
        else
        {
            break;
        }
    }

    while (true)
    {
        cout << "Сыграть еще раз? (Y/N): ";
        cin >> yn;
        if (yn != y && yn != n && yn != N && yn != Y)
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == y || yn == Y)
        {
            clearScr();
            return main();
            break;
        }
        else if (yn == n || yn == N)
        {
            exit(0);
        }
        else
        {
            break;
        }
    }

    cin.get();
    deinitField(field);

    return 0;
}
