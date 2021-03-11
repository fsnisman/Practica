#include <iostream>
#include <math.h>
#include <cstdint>
#include <Windows.h>

using namespace std;

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
struct Answer
{
    char yn = 0;
    char N = 78;
    char Y = 89;
    char n = 110;
    char y = 121;
    char adr = 0;
    char a = 97;
    char A = 65;
    char d = 100;
    char D = 68;
    char r = 114;
    char R = 82;
};
void SetColor(int text)
{
    HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Color, text);
}

class Power
{
private:
    double number1 = 0;
    double number2 = 0;
public:
    Power()
    {};
    int getcalculate()
    {
        double pw;
        pw = pow(number1, number2);
        cout << pw << "\n\n";
        return pw;
    }
    void setnumber()
    {
        while (true)
        {
            cout << "Value of the first double number: ";
            cin >> number1;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
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
            cout << "Value of the second double number: ";
            cin >> number2;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }
        }
    }
    ~Power()
    {};
};
class RGBA
{
private:
    uint8_t  m_red = 0;
    uint8_t  m_green = 0;
    uint8_t  m_blue = 0;
    uint8_t  m_alpha = 255;
public:
    RGBA(int red, int green, int blue, int alpha)
    {
        while (true)
        {
            cout << "Enter red value: ";
            cin >> red;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (red < 0 || red > 255)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "This number if not included in the range from 0 to 255. Repeat input." << endl << endl;
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
            cout << "Enter green value: ";
            cin >> green;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (green < 0 || green > 255)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "This number if not included in the range from 0 to 255. Repeat input." << endl << endl;
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
            cout << "Enter blue value: ";
            cin >> blue;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (blue < 0 || blue > 255)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "This number if not included in the range from 0 to 255. Repeat input." << endl << endl;
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
            cout << "Enter alpha value: ";
            cin >> alpha;
            if (!cin)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "It's not a number. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else if (alpha < 1 || alpha > 255)
            {
                SetColor(Red);
                cout << "Error! ";
                SetColor(White);
                cout << "This number if not included in the range from 1 to 255. Repeat input." << endl << endl;
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }
        }

        m_red = red;
        m_green = green;
        m_blue = blue;
        m_alpha = alpha;
    };
    void print()
    {
        SetColor(Red);
        cout << "red: " << m_red << endl;
        SetColor(White);
        SetColor(Green);
        cout << "green: " << m_green << endl;
        SetColor(White);
        SetColor(Blue);
        cout << "blue: " << m_blue << endl;
        SetColor(White);
        cout << "alpha: " << m_alpha << endl << endl;
    }
    ~RGBA()
    {};
};
class Stack
{
private:
    int Array[10] = { 0 };
    int length = 0;
public:
    Stack()
    {};
    int i = 0;
    void reset()
    {
        for (int i = 0; i < 10; i++)
        {
            Array[i] = 0;
        };
        length = 0;
        i = 0;
    };
    bool push(int value)
    {
        for (; length <= 10;)
        {
            if (Array[length] == 0)
            {
                break;
            }
            else if (Array[0] != 0 && Array[1] != 0 && Array[2] != 0 && Array[3] != 0 && Array[4] != 0 && Array[5] != 0 && Array[6] != 0 && Array[7] != 0 && Array[8] != 0 && Array[9] != 0)
            {
                SetColor(Red);
                cout << "false\n";
                SetColor(White);
                return false;
            }
            else
            {
                break;
            }
        }
        for (; i < 10;)
        {
            while (true)
            {
                cout << "Enter to value element of massiv: ";
                cin >> value;
                if (!cin)
                {
                    SetColor(Red);
                    cout << "Error! ";
                    SetColor(White);
                    cout << "It's not a number. Repeat input." << endl << endl;
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else
                {
                    break;
                }
            }
            Array[i] = value;
            length++;
            break;
        }
        i++;
        return true;
    };
    void pop()
    {
        Array[length] = 0;
        --length;
        --i;
    };
    void print()
    {
        SetColor(Yellow);
        cout << "Array" << endl;
        SetColor(White);
        cout << "( ";
        for (int i = 0; i < length; i++)
        {
            cout << Array[i] << " ";
        }
        cout << ")" << endl;;
    };
    ~Stack()
    {};
};

int main()
{

    Power p;
    p.setnumber();
    p.getcalculate();

    uint8_t red = 0;
    uint8_t green = 0;
    uint8_t blue = 0;
    uint8_t alpha = 0;
    RGBA rgba(red, green, blue, alpha);
    rgba.print();

    int value = 0;
    Stack stack;
    Answer ans;

    while (true)
    {
        cout << "Do you want to edit an value of array? (Y/N): ";
        cin >> ans.yn;
        if (ans.yn != ans.y && ans.yn != ans.n && ans.yn != ans.N && ans.yn != ans.Y)
        {
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (ans.yn == ans.y || ans.yn == ans.Y)
        {
            while (true)
            {
                cout << "Do enter to value of array? (Y/N): ";
                cin >> ans.yn;
                if (ans.yn != ans.y && ans.yn != ans.n && ans.yn != ans.N && ans.yn != ans.Y)
                {
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else if (ans.yn == ans.y || ans.yn == ans.Y)
                {
                    while (true)
                    {
                        cout << "Do edit to value of array(add/delete/reset)? (A/D/R): ";
                        cin >> ans.adr;
                        if (ans.adr != ans.a && ans.adr != ans.A && ans.adr != ans.d && ans.adr != ans.D && ans.adr != ans.r && ans.adr != ans.R)
                        {
                            cin.clear();
                            while (cin.get() != '\n');
                        }
                        else
                        {
                            while (true)
                            {
                                if (ans.adr == ans.a || ans.adr == ans.A)
                                {
                                    stack.push(value);
                                }
                                else if (ans.adr == ans.d || ans.adr == ans.D)
                                {
                                    stack.pop();
                                }
                                else if (ans.adr == ans.r || ans.adr == ans.R)
                                {
                                   stack.reset();
                                }
                                 break;
                            }
                            break;
                        }
                    }
                    stack.print();
                    continue;
                }
                else if (ans.yn == ans.n || ans.yn == ans.N)
                {
                    break;
                }
            }
        }
        else if (ans.yn == ans.n || ans.yn == ans.N)
        {
            exit(0);
        }
        else
        {
            break;
        }
    }

}