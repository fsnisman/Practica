#include <iostream>

using namespace std;
//Начало четвертого задания
struct KresticNolic {                                       
    int RazmerPolja[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    const char X = 88;
    const char x = 120;
    const char O = 79;
    const  char o = 111;
    const  char Х = 213;
    const  char х = 245;
    const  char О = 206;
    const  char о = 238;
};                                                          
//Конец четвертого задания
//Начало пятого задания
struct Uni                                                  
{
    union Ub
    {
        int isInt;
        float isFloat;
        char isChar;
    };
    unsigned int isInt : 1;
    unsigned int isFloat : 1;
    unsigned int isChar : 1;
};                                                          

int main()
{
    setlocale(LC_ALL, "Russian");

    //Начало первого задания
    short int a = 32767;
    cout << "short int = " << a << endl;
    int b = 4000000;
    cout << "int = " << b << endl;
    long long c = 9223372036854775807;
    cout << "long long = " << c << endl;
    char d = 60;
    cout << "char = " << d << endl;
    bool f = false;
    cout << "bool = " << f << endl;
    float g = 3.48138751952484;
    cout << "float = " << g << endl;
    double h = 1.798452654219843754891915749546874681698498798462491951954197484631919819;
    cout << "double = " << h << endl;
    //Конец первого задания

    //Начало второго задания
    enum Deistvie                  
    {
        X,
        x,
        O,
        o,
        Х,
        х,
        О,
        о,
    };
    Deistvie igrok = X;
    cout << igrok << " ";
    igrok = x;
    cout << igrok << " ";
    igrok = O;
    cout << igrok << " ";
    igrok = o;
    cout << igrok << " ";
    igrok = Х;
    cout << igrok << " ";
    igrok = х;
    cout << igrok << " ";
    igrok = О;
    cout << igrok << " ";
    igrok = о;
    cout << igrok << endl;                  
    //Конец второго задания

    //Начало третьего задания
    char dei[8] = { 88, 120, 79, 111, 213, 245, 206, 238 };
    for (int x = 0; x < 8; ++x)
    {
        cout << dei[x] << " ";
    }
    cout << endl;
    //Конец третьего задания

    Uni u;
    u.isInt = 1;
    cout << u.isInt << " ";
    u.isFloat = 0.3;
    cout << u.isFloat << " ";
    u.isChar = 1;
    cout << u.isChar << endl;

    cout << sizeof(u);          //Проверил размер для себя
    //Конец пятого задания

    return 0;

}

