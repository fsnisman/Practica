#include <iostream>

using namespace std;

//Класс-исключение
class Ex {
private:
    double x;
public:
    explicit Ex(double x) {
        this->x = x;
    }
    void set(double& a, double& y) {
        x = y * a;
        cout << "Multiplication: " << x << endl;
    };
};
//Базовый класс
class Bar {
private:
    double y;
public:
    Bar(double y = 0) {
        this->y = y;
    }
    double set(double a) {
        cout << "Enter two number:";
        //Проверка ввода
        while (true) {
            cin >> a;
            if (!cin) {
                cout << "Error enter numbers!!!" << endl;
                cout << "Repeat enter numbers: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            else {
                break;
            }
        }
        y += a;
        //Проверка на превышение значение 100
        if (y > 100) {
            try {
                throw Ex(y);
            }
            catch (Ex& ex) {
                ex.set(a, y);
            }
        }
        else {
            y = a;
        }
    }
};

//=======================================================================================
//Шаблонная функция div с исключением деление на ноль
template <class T>
T div(T number1, T number2) {
    cout << "Enter one number:";
    cin >> number1;
    cout << "Enter two number:";
    cin >> number2;

    //Проверка на ноль
    if (number2 == 0) {
        throw "Division on zero it is impossible";
    }

    T number3 = number1 / number2;
    cout << "Answer: " << number3 << "\n\n";

    return 0;
}
//=======================================================================================

int main() {
    double a = 0;
    double b = 0;
    try {
        div<double>(a, b);
    }
    catch (const char* exception) {
        cerr << exception << endl;
    }

    double n = 0;
    Bar bar(0);
    while (true) {
        try {
            cout << "Enter one number:";
            //Проверка ввода
            while (true) {
                cin >> n;
                if (!cin) {
                    cout << "Error enter numbers!!!" << endl;
                    cout << "Repeat enter numbers: ";
                    cin.clear();
                    while (cin.get() != '\n');
                }
                else {
                    break;
                }
            }
            //Проверка на значение 0
            if (n == 0) {
                throw 0;
            }
            else {
                bar.set(n);
            }
        }
        catch (...) {
            cout << "Zero entered. Error.";
            break;
        }
    }
    return 0;
}
