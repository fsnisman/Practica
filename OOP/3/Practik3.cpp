#include <iostream>

using namespace std;

//======================================================================================================================
static double S;
class Figure{
public:
    virtual void area() = 0;
    virtual ~Figure(){};
};
class Circle: public Figure{
private:
    double r;
    double p = 3.14;
public:
    Circle(double r){};
    void area() override{
        S = p * (r * r);
    }
    ~Circle() override{};
};
class Parallelogram: public Figure{
protected:
    double parameter1;
    double parameter2;
public:
    Parallelogram(double a) : parameter1(a) {};
    Parallelogram(double a, double b) : parameter1(a), parameter2(b) {};
    void area() override{
        S = parameter1 * parameter2;
    }
    ~Parallelogram() override{};
};
class Rectangle: public Parallelogram{
public:
    Rectangle(double a, double b) : Parallelogram(a, b){};
    void area() override{
        S = parameter1 * parameter2;
    }
    ~Rectangle() override{};
};
class Square: public Parallelogram{
public:
    Square(double a) : Parallelogram(a){};
    void area() override{
        S = parameter1 * parameter1;
    }
    ~Square() override{};
};
class Rhombus: public Parallelogram{
public:
    Rhombus(double a, double h) : Parallelogram(a, h){};
    void area() override{
        S = parameter1 * parameter2;
    }
    ~Rhombus() override{};
};
//======================================================================================================================
class Car{
protected:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m){};
    ~Car(){
        cout << "~Car" << endl;
    }
};
class PassengerCar: virtual public Car{
public:
    PassengerCar(string company, string model) : Car(company, model){};
    ~PassengerCar(){
        cout << "~PassengerCar" << endl;
    }
};
class Bus: virtual public Car{
public:
    Bus(string company, string model) : Car(company, model){};
    ~Bus(){
        cout << "~Bus" << endl;
    }
};
class Minivan: public PassengerCar, public Bus{
public:
    Minivan(string company, string model): Car(company, model), PassengerCar(company, model), Bus(company, model){};
    ~Minivan(){
        cout << "~Minivan" << endl;
    }
};
/*Если смотреть графически, то пути деструктора строят "алмаз смерти", но делает это постепенно. Сначала два основных
 * наследнных класса, а потом только с помощью наследных классов создается класс Minivan.*/
//======================================================================================================================
class Fraction{
private:
    double m_value;
public:
    Fraction(double value) {m_value = value;};
    Fraction operator/(double d_value) const{
        if (d_value == 0){
            cout << "Cannot divide by zero" << endl;
        }
        return {m_value / d_value};
    }
    Fraction operator+(double d_value) const{
        return {m_value + d_value};
    }
    Fraction operator-(double d_value) const{
        return {m_value - d_value};
    }
    Fraction operator*(double d_value) const{
        return {m_value * d_value};
    }
    Fraction operator-() const{
        return {-m_value};
    }
    friend  bool operator> (const Fraction &v1, const Fraction &v2);
    friend  bool operator>= (const Fraction &v1, const Fraction &v2);
    friend  bool operator< (const Fraction &v1, const Fraction &v2);
    friend  bool operator<= (const Fraction &v1, const Fraction &v2);
    double getValue() const{
        return m_value;
    }
};
bool operator>(const Fraction &v1, const Fraction &v2){
    if (v1.m_value > v2.m_value){
        cout << v1.m_value << endl;
    }
    return true;
}
bool operator<(const Fraction &v1, const Fraction &v2){
    if (v1.m_value < v2.m_value){
        cout << v2.m_value << endl;
    }
    return true;
}
bool operator>=(const Fraction &v1, const Fraction &v2){
    if (v1.m_value >= v2.m_value){
        cout << v1.m_value << endl;
    }
    return true;
}
bool operator<=(const Fraction &v1, const Fraction &v2){
    if (v1.m_value <= v2.m_value){
        cout << v2.m_value << endl;
    }
    return true;
}
//======================================================================================================================

int main(int argc, const char * argv[]) {
    PassengerCar passengerCar("Toyota", "GSV");
    Bus bus("Mercedes", "SLC");
    Minivan minivan("BMW", "MIN8");

    Fraction fraction(6);
    Fraction fraction1 = fraction / 0;
    Fraction fraction2 = fraction / 2;
    cout << fraction2.getValue() << endl;
    Fraction fraction3 = fraction + 2;
    cout << fraction3.getValue() << endl;
    Fraction fraction4 = fraction - 3;
    cout << fraction4.getValue() << endl;
    Fraction fraction5 = fraction * 2;
    cout << fraction5.getValue() << endl;
    Fraction fraction6 = -fraction;
    cout << fraction6.getValue() << endl;
    Fraction fraction7 = fraction > 3;
    Fraction fraction8 = fraction < 10;
    Fraction fraction9 = fraction <= 6;
    Fraction fraction10 = fraction >= 4;

    return 0;
}
