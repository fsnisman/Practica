#include <iostream>
#include <valarray>
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

//Функция для краски текста
void SetColor(int text)
{
    HANDLE Color = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(Color, text);
}  

//Функция которая выводит True массив
void TrueMassiv()
{
    SetColor(Green);
    cout << "True" << endl;
    SetColor(White);
}

//Функция которая выводит False массив
void FalseMassiv()
{
    SetColor(Red);
    cout << "False" << endl;
    SetColor(White);
}



int ARRAY_DOUBLE()
{
    double arr[5];
   
    for (int i = 0; i < 5; i++)
    {
        while (true)
        {
            cout << "Введите число: ";
            cin >> arr[i];                                   //Вводим значение массива
            if (!cin) 
            {
                cout << "Введено не число, введите снова\n"; //Проверка ввода пользователя
                cin.clear();
                while (cin.get() != '\n');
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";                                //Выводим сам массив
    }
    cout << "\n\n\n";
    return 0;
}

int ARRAY_ZERO_AND_ONE()
{
    int arr[10] = { 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };

    cout << "Вывод изночального массива:" << endl;

    for (int number : arr)                              //Вывод массива
    {
        cout << number << " ";
    }

    cout << endl;

    cout << "Перевод массива: " << endl;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 1)                                //Если элемента массива равен 1, то заменяем на 0
        {
            arr[i] = 0;
            cout << arr[i] << " ";
        }
        else                                            //Иначе заменяем на 1
        {
            arr[i] = 1;
            cout << arr[i] << " ";
        }
    }
    cout << "\n\n\n";
    return 0;
}

int ARRAY_FOR_ARRAY(int arr1[8])                        //Задаем параметр функции массив, для дальнейшего использования в функции main
{
    int arr2[8] = { 1, 4, 7, 10, 13, 16, 19, 22 };      //Массив который будем использовать для замены

    cout << endl;
    cout << "Массив с измененым значением:" << endl;

    for (int i = 0; i < 8; i++)
    {
        if (arr1[i] == arr1[i])                         //Проводим проверку массива
        {
            arr1[i] = arr2[i];                          //Заменяем элементы первого массива на второй массив
            cout << arr1[i] << " ";                     //Вывод измененого массива
        }
        else
        {
            break;
        }
    }
    cout << "\n\n\n";
    return 0;
}

int ARRAY_SHIFT()
{

    valarray < int > arr{1, 2, 3, 4, 5, 6, 7, 8};               //Задаем целочисленный массив через valarray

    cout << "Первоначальное значение массива:" << endl;         //Выводим первоначальный массив
    for (int number : arr) 
    {
        cout << number << " ";
    }
    cout << endl;

    int n;                                                       
    cout << "Ввод смещения: ";                                  //Вводим на сколько позиций мы сместим массив
    cin >> n;

    valarray < int > shift = arr.shift(-n);                     //Задаем целочисленное значение shift для смещение и используем оператор "shift(на сколько позиций смещаем)" для массива arr

    cout << "Измененый массив:" << endl;
    for (int number : shift) 
    {
        cout << number << " ";                                  //Выводим измененый массив со смещением
    }
    cout << "\n\n\n";

    return 0;
}

int ARRAY_BALANCE (int arr[], int size)
{
    int sum = 0;

    for (size_t i = 0; i < size; i++)                           //Выводим сумму массива
    {
        sum += arr[i];
    }
    cout << "Сумма массива: " << sum << ";" << " Значение: ";
    if (sum % 2 == 0)                                           //Провермя делится ли сумма без остатка
    {
        TrueMassiv();                                           //Если да, то массив true
    }
    else
    {
        FalseMassiv();                                          //Если нет, то массив fasle
    }

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
    cout << "Задание №1" << endl;
    SetColor(White);
    
    cout << "Выводим массив размером из 5 чисел с типом данных double" << endl;
    
    ARRAY_DOUBLE();

    /*
    =====================================================================================
    Второе задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №2" << endl;
    SetColor(White);
    
    cout << "Выводим массивы, который выводит из 1 в 0, а из 0 в 1" << endl;
    
    ARRAY_ZERO_AND_ONE();

    /*
    =====================================================================================
    Третье задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №3" << endl;
    SetColor(White);
    
    cout << "Меняем значение массива с помощью массива";
    
    int arr1[8];
    
    ARRAY_FOR_ARRAY(arr1);

    /*
    =====================================================================================
    Четветое задание
    =====================================================================================
    */
    
    SetColor(Green);
    cout << "Задание №4" << endl;
    SetColor(White);
    
    cout << "Смещаем все элемениты массива размером 8 чисел на n позиции" << endl;    /* Информацию взял с интернета https://en.cppreference.com/w/cpp/numeric/valarray/shift
                                                                                      узнал о такой библеотеке "valarray", которая работает с массивами и оператор "shift", который сдвигает элементы массива
                                                                                      классная библеотека и очень нужная, например, в этом моменте задании. */
    ARRAY_SHIFT();

    /*
    =====================================================================================
    Пятое задание
    =====================================================================================
    */

    SetColor(Green);
    cout << "Задание №5" << endl;
    SetColor(White);

    cout << "Проверяем баланс в массиве" << endl;  /* Происходит проверка баланса по сумме массива.
                                                      Если деление происходит без остатка, то в любом случае в массиве есть баланс между правой и левой стороной.
                                                      Если же баланса нет, то и нет баланса между правой и левой стороной. */
    const int size = 5;
    int array1[] = { 20, 50, 12, 34, 17 };
    int array2[] = { 20, 10, 10, 10, 30 };
    int array3[] = { 71, 14, 56, 0, 33 };
    ARRAY_BALANCE(array1, size);
    ARRAY_BALANCE(array2, size);
    ARRAY_BALANCE(array3, size);
}
