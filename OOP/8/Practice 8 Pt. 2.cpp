#include <iostream>
#include<limits>

using namespace std;

//Класс-исключение "Выход за пределы клетки"
class OffTheField {
private:
    string m_error;
public:
    explicit OffTheField(string error) : m_error(error) {};
    const char* getError() {
        cout << "Going outside the field!!!" << "\n\n";
        return m_error.c_str();
    }
};

//Класс-исключение "Задано неправильное направление"
class IllegalCommand {
private:
    string m_error;
public:
    explicit IllegalCommand(string error) : m_error(error) {};
    const char* getError() {
        cout << "Wrong direction of coordinates set!!!" << "\n\n";
        return m_error.c_str();
    }
};

//Базовый класс "Робот"
class Robot {
private:
    int x;
    int y;
public:
    Robot(int x, int y) {
        this->x = x;
        this->y = y;
    }

    //Изменение координаты Y
    int setY() {
        int y1;
        cout << "Enter number coordinate Y: ";
        //Проверка на ввод
        while (true) {
            cin >> y1;
            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error enter numbers!!!" << endl;
                cout << "Repeat enter numbers: ";
            }
            else {
                break;
            }
        }
        //Проверка на превышенное занчение
        if (y1 > 10) {
            try {
                throw OffTheField("Going outside the field");
            }
            catch (OffTheField& off) {
                off.getError();
                return y;
            }
        }
        this->y += y1;
        //Проверка на какой клетке будет находиться бот
        //Он не должен выходит за пределы 10 и 0
        if (y > 10 || y < 0) {
            try {
                throw OffTheField("Going outside the field");
            }
            catch (OffTheField& off) {
                off.getError();
                this->y -= y1;
                return y;
            }
        }
        return y;
    }

    //Изменение координаты X
    int setX() {
        int x1;
        cout << "Enter number coordinate X: ";
        //Проверка на ввод
        while (true) {
            cin >> x1;
            if (!cin) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Error enter numbers!!!" << endl;
                cout << "Repeat enter numbers: ";
            }
            else {
                break;
            }
        }
        //Проверка на превышенное занчение
        if (x1 > 10) {
            try {
                throw OffTheField("Going outside the field");
            }
            catch (OffTheField& off) {
                off.getError();
                return x;
            }
        }
        this->x += x1;
        //Проверка на какой клетке будет находиться бот
        //Он не должен выходит за пределы 10 и 0
        if (x > 10 || x < 0) {
            try {
                throw OffTheField("Going outside the field");
            }
            catch (OffTheField& off) {
                off.getError();
                this->x -= x1;
                return x;
            }
        }
        return x;
    }

    //Вывод координат XY на экран
    void printcood() const {
        cout << "Coordinate X: " << x << endl << "Coordinate Y: " << y << "\n\n";
    }
};

int main() {
    Robot robot(0, 0);
    while (true){
        char Answer;

        //Запрос пользователю куда он хочет двигаться
        cout << "In which direction of coordinates to direct the robot (X/Y)?" << endl << "Enter: ";
        cin >> Answer;
        //Проверка на ввод
        if (Answer != 'X' && Answer != 'Y' && Answer != 'x' && Answer != 'y') {
            try {
                throw IllegalCommand("Wrong direction of coordinates set");
            }
            catch (IllegalCommand& illegal) {
                illegal.getError();
                cin.clear();
                while (cin.get() != '\n');
            }
        }
            //Изменение координаты X
        else if (Answer == 'X' || Answer == 'x') {
            robot.setX();
            robot.printcood();
        }
            //Изменение координаты Y
        else if (Answer == 'Y' || Answer == 'y') {
            robot.setY();
            robot.printcood();
        }
    }
    return 0;
}
