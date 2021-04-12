#include <iostream>
#include <limits>

using namespace std;
//==================================================================================================================
int mycin(int &numbers){
    while (true){
        cin >> numbers;
        if (!cin) {
            cout << "Error enter numbers!!!" << endl;
            cout << "Repeat enter numbers:";
            cin.clear();  //очистка ввода
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //игнор символов
            continue;
        }
        else{
            cout << "Your numbers: " << numbers << endl;
            break;
        }
    }
    return numbers;
}
//==================================================================================================================
class Endll{
private:
    string m_str;
public:
    Endll(){};
    friend ostream& operator<< (ostream &out, const Endll &endll);
    ~Endll(){};
};
//перегрузка оператора вывода
ostream& operator<< (ostream &out, const Endll &endll) {
        printf("\n\n");  //перевод строки два раза
        cout.flush();           //очистка буфера вывода
        out << endll.m_str;
    return out;
}
//==================================================================================================================

int main() {
    cout << "Enter any count numbers:";
    int numbers = 1;
    mycin(numbers);
    cout << numbers << endl;

    Endll endll;
    string a;
    cout << "Enter any word or numbers or symbols:";
    cin >> a;
    cout << a << endll;
}
