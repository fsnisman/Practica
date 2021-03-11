#define checknumber(number) if (number >= 0 && number < 100) cout << "true"; else cout << "false";
#define INT_MASSIV (ptrArr, size); ptrArr = new int[size]; DINAMIC_MASSIV(ptrArr, size); delete[] ptrArr;

#include <iostream>
#include <Windows.h>
#include <fstream>
#include "mylib.h"

#pragma pack(push, 1)
struct Employee
{
    long id; 
    unsigned short age; 
    double salary;
};
#pragma pack(pop)

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

//Функция для краски текста
void SetColor(int text)
{
    HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(Color, text);
}

using namespace std;

void DINAMIC_MASSIV(int a[], int& size)
{
    int temp;

    for (int i = 0; i < size; i++)
    {
        a[i] = rand();
    }

    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (a[j] > a[j + 1]) 
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) 
    {
        cout << a[i] << " ";
    }
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
    cout << "Задание №1" << endl << "Создайте проект из 2х cpp файлов и заголовочного (main.cpp, mylib.cpp, mylib.h) во втором модуле mylib объявить 3 функции: для инициализации массива (типа float), печати его на экран и подсчета количества отрицательных и положительных элементов." << endl;
    SetColor(White);

    int size;


    while (true)
    {
        cout << "Введите размер массива: ";
        cin >> size;
        if (!cin)
        {
            cout << "Введено не число, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size < 0)
        {
            cout << "Введено число отрицательное, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else
        {
            break;
        }
    }

    ARRAY_FLOAT_DINAMIC(size);

    cout << endl << endl << endl;

    /*
    =====================================================================================
    Второе задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №2" << endl << "Описать макрокоманду (через директиву define), проверяющую, входит ли переданное ей число (введенное с клавиатуры) в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно) и возвращает true или false, вывести на экран «true» или «false»." << endl;
    SetColor(White);

    int number;
    
    while (true)
    {
        cout << "Введите число: ";
        cin >> number;
        if (!cin)
        {
            cout << "Введено не число, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else
        {
            break;
        }
    }

    checknumber(number);

    cout << endl << endl << endl;

    /*
    =====================================================================================
    Третье задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №3" << endl << "Задайте массив типа int. Пусть его размер задается через директиву препроцессора #define. Инициализируйте его через ввод с клавиатуры. Напишите для него свою функцию сортировки (например Пузырьком). Реализуйте перестановку элементов как макрокоманду SwapINT(a, b). Вызывайте ее из цикла сортировки." << endl;
    SetColor(White);

    int size1;

    while (true)
    {
        cout << "Введите размер массива: ";
        cin >> size1;
        if (!cin)
        {
            cout << "Введено не число, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else if (size1 < 0)
        {
            cout << "Введено число отрицательное, введите снова\n";
            cin.clear();
            while (cin.get() != '\n');
        }
        else
        {
            break;
        }
    }

    int* ptrArr;

    INT_MASSIV(ptrArr, size1);

    cout << endl << endl << endl;

    /*
    =====================================================================================
    Четвертое задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №4" << endl << "Объявить структуру Сотрудник с различными полями. Сделайте для нее побайтовое выравнивание с помощью директивы pragma pack. Выделите динамически переменную этого типа. Инициализируйте ее. Выведите ее на экран и ее размер с помощью sizeof. Сохраните эту структуру в текстовый файл." << endl;
    SetColor(White);

    Employee* ptrEmployee = new Employee;
    ptrEmployee->id = 00020130414;
    ptrEmployee->age = 24;
    ptrEmployee->salary = 30000;

    cout << "Размер выделенное переменой: " << sizeof(ptrEmployee);

    ofstream fout("size_variable.txt");
    fout << "Размер выделенное переменой: " << sizeof(ptrEmployee);
    fout.close();

    delete ptrEmployee;

    cout << endl << endl << endl;

    return 0;
}

