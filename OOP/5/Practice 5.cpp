#include <iostream>
#include <string>
using namespace  std;

//======================================================================================================================
template <class T_Class>
class Pair1{
private:
    T_Class m_count;
    T_Class m_count2;
public:
    Pair1(T_Class count, T_Class count2){
        m_count = count;
        m_count2 = count2;
    }
    T_Class first() const{
        return  m_count;
    }
    const T_Class second() const{
        return m_count2;
    }
    ~Pair1(){}
};
//======================================================================================================================
template <class T_Class, class S_Class>
class Pair{
private:
    T_Class m_count;
    S_Class m_count2;
public:
    Pair(T_Class count, S_Class count2){
        m_count = count;
        m_count2 = count2;
    }
    T_Class first() const{
        return m_count;
    }
    S_Class second() const{
        return m_count2;
    }
    ~Pair(){}
};
//======================================================================================================================
template <class S_Class>
class StringValuePair: public Pair<string, S_Class>{
public:
    StringValuePair(string str, S_Class count): Pair<string, S_Class>(str, count){}
    ~StringValuePair(){}
};
//======================================================================================================================

int main() {

    Pair1<int> p1(6, 9);
    cout << p1.first() << " " << p1.second() << endl;
    const Pair1<double> p2(3.4, 7.8);
    cout << p2.first() << " " << p2.second() << endl;

    Pair<int, double> ps1(6, 3.34);
    cout << ps1.first() << " " << ps1.second() << endl;
    const Pair<double, int> ps2(3.23, 5);
    cout << ps2.first() << " " << ps2.second() << endl;

    StringValuePair<int> svp("Amazing", 7);
    cout << svp.first() << " " << svp.second() << endl;

    return 0;
}
