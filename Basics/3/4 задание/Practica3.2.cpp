#include <iostream>

using namespace std;

/*
===========================================================================================================
Четвертое задание
===========================================================================================================
*/

extern int a;
extern int b;
extern int c;
extern int d;

int main()
{
    setlocale(LC_ALL, "Russian");

    float f = static_cast <float> (c) / d;
    f = static_cast <float> (b) + f;
    f = static_cast <float> (a) * f;


    cout << "Получаем число: " << f << endl;
}


