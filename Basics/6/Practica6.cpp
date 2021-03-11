#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

//Палитра цветов от 0 до 15
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

//Функция для краски
void SetColor(int text)
{
    HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(Color, text);
}


int ARRAY_DINAMIC(int size)
{
    int* ptrArr;

    if (size > 0)
    {
        ptrArr = new int[size];                                             //Определяем размер массива и выделяем память

        int k = 1;
        for (size_t i = 0; i < size; i++, k *= 2)
        {
            ptrArr[i] = k;
            cout << k << " ";
        }
        delete[] ptrArr;                                                    //Очищаем память
        ptrArr = nullptr;                                                   //Сбрасываем указатель
    }

    cout << "\n\n\n";
    return 0;
}

int ARRAY_DINAMIC_MATRIX_RAND()
{
    int** ptrArr;                                           //Указываем указатель на два массива
    const size_t size1 = 4;
    const size_t size2 = 4;

    ptrArr = new int* [size1];                             //Указываем на новый массив размером size1
    for (size_t i = 0; i < size1; i++)
    {
        ptrArr[i] = new int[size2];                         //Указываем с помощью указателя элементы первого массива на создание второго массива размером size2
    }

    for (size_t i = 0; i < size1; i++)                      //Вывод певого массива
    {
        for (size_t j = 0; j < size2; j++)                  //Вывод второго массива
        {
            ptrArr[size1 - 1][size2 - 1] = rand();          //Задаю рандомные числа
            cout << ptrArr[size1 - 1][size2 - 1] << " ";    //Вывожу эти числа
        }
        cout << endl;
    }

    for (size_t i = 0; i < size2; i++)                      //Очищаю память для второго массива
    {
        delete[] ptrArr[i];
    }
    delete[] ptrArr;                                        //Очищаю память для первого массива
    ptrArr = nullptr;                                       //Сбрасываю указатель

    cout << "\n\n\n";

    return 0;
}

int OFSTREAM_RANDOM_NUMBER(string& j)
{
    int a;
    const int n = 100;

    cout << "Введите название первого файла: ";
    cin >> j;

    ofstream fout(j + ".txt");

    for (int i = 0; i < n; i++)
    {
        a = rand();
        fout << "number [" << i << "]=" << a << endl;
    }
    fout.close();

    return 0;
}

int OFSTREAM_RANDOM_CHAR(string& j)
{
    char a;
    const int n = 100;

    cout << "Введите название второго файла: ";
    cin >> j;

    ofstream fout(j + ".txt");
    for (int i = 0; i < n; i++)
    {
        a = rand();
        fout << "symbol [" << i << "]=" << a << endl;
    }
    fout.close();

    cout << "\n\n\n";

    return 0;
}

int MERGER(string& a, string& b)
{
    ifstream in1(a + ".txt");
    ifstream in2(b + ".txt");

    string j;

    cout << "Введите название третьего файла: ";
    cin >> j;

    ofstream out(j + ".txt");
    string str1, str2;

    while (!in1.eof() || !in2.eof())
    {
        if (getline(in1, str1))
            out << str1 << endl;
        if (getline(in2, str2))
            out << str2 << endl << endl;
    }

    cout << "\n\n\n";

    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");

    /*
    =====================================================================================
    Первое задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №1" << endl << "Инициализировать динамический массив с числами степенями двойки: 1, 2, 4, 8, 16, 32, 64, 128..." << endl;
    SetColor(White);

    int a;
    while (true)
    {
        cout << "Ввести размер массива: ";
        cin >> a;                                                            //Вводим значение элементов массива
        if (!cin)
        {
            cout << "Введено не число, введите снова\n";                     //Проверка ввода пользователя
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (a < 0)
        {
            cout << "Введено отрицательное условие, введите снова\n";        //Проверка ввода пользователя
            cin.clear();
            while (cin.get() != '\n');
        }
        else
        {
            break;
        }
    }
    ARRAY_DINAMIC(a);                                                        //Вывоз функции


    /*
    =====================================================================================
    Второе задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №2" << endl << "Динамически выделить матрицу 4х4 типа int. Инициализировать ее псевдослучайными числами через функцию rand" << endl;
    SetColor(White);

    ARRAY_DINAMIC_MATRIX_RAND();                                             //Вывоз функции

    /*
    =====================================================================================
    Третье задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №3" << endl << "Написать программу c 2-я функциями, которая создаст два текстовых файла (*.txt), примерно по 50-100 символов в каждом. Имена файлов запросить у польлзователя." << endl;
    SetColor(White);

    string c;
    string v;

    OFSTREAM_RANDOM_NUMBER(c);
    OFSTREAM_RANDOM_CHAR(v);

    /*
    =====================================================================================
    Четвертое задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №4" << endl << "Написать функцию, «склеивающую» эти файлы в третий текстовый файл." << endl;
    SetColor(White);

    MERGER(c, v);

    /*
    =====================================================================================
    Пятое задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №5" << endl << "Написать программу, которая проверяет присутствует ли указанное пользователем при запуске программы слово в указанном пользователем файле" << endl;
    SetColor(White);

    string k;
    string j;
    string word_in;

    cout << "Введите название файла: ";
    cin >> j;

    cout << "Ввести что-нибудь: ";
    cin >> k;

    ofstream fout(j + ".txt");
    fout << k;
    fout.close();

    ifstream fin(j + ".txt");
    while (fin >> word_in)
        if (word_in == k)
        {
            cout << "Проверка: " << k << endl << "Есть сходство";
            fin.close();
            return 0;
        }
        else
        {
            "Нет, здесь такого";
        }

    cout << "\n\n\n";

    return 0;
}

