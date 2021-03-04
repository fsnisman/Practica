/*
ПЕЧАТЬ.
ПРОЦЕСС ИГРЫ.
*/

#include "Coord.cpp"
#include "color.h"
#include "ai.cpp"
#include "players.cpp"
#include "checkwin.cpp"
#include "gamestructur.h"

using namespace std;


void clearScr()
{
    system("cls");
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

    while (true)
    {
        cout << "Начать играть? (Y/N): ";
        cin >> yn;
        if (yn != 'y' && yn != 'n' && yn != 'N' && yn != 'Y')
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == 'n' || yn == 'N')
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
        if (yn != 'y' && yn != 'n' && yn != 'N' && yn != 'Y')
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == 'y' || yn == 'Y')
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
        else if (yn == 'n' || yn == 'N')
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
        if (yn != 'y' && yn != 'n' && yn != 'N' && yn != 'Y')
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (yn == 'y' || yn == 'Y')
        {
            clearScr();
            return main();
            break;
        }
        else if (yn == 'n' || yn == 'N')
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

