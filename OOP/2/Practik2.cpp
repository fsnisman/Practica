#include <iostream>

using namespace std;
//======================================================================================================================
class Person{
private:
    static int count_person;
protected:
    string name;
    int age;
    string gender;
    float weight;
public:
    Person(string n, int a, string g, float w): name(n), age(a), gender(g), weight(w){
        count_person++;
    };
    void set_name(string n){
        name = n;
    };
    void set_age(int a){
        age = a;
    }
    void set_weight(float w){
        weight = w;
    }
    ~Person(){
    };
};
int Person::count_person = 0;
class Student: public Person{
private:
    static int count_student;
    int year_study;
public:
    Student(string n, int a, string g, float w, int ys): Person(n, a, g, w), year_study(ys){
        count_student++;
    };
    void set_year_study(int ys){
        year_study = ys;
    }
    int get_year_study(int ys){
        year_study = ys;
        ys++;
        return ys;
    }
    int get_count_student(){
        cout << "Name: " <<  name << "; " << "age: " << age << "; " << "gender: " << gender << "; " << "weight: " << weight << "; " << "year study: " << year_study << endl;
        return count_student;
    }
    ~Student(){};
};
int Student::count_student = 0;
//======================================================================================================================
class Fruit{
protected:
    string name;
    string color;
};
class Apple: public Fruit{
public:
    virtual string get_name(){
        name = "apple";
        return name;
    }

    virtual string get_color(){
        color = "red";
        return color;
    }
};
class Banana: public Fruit{
public:
    string get_name(){
        name = "banana";
        return name;
    }
    string get_color(){
        color = "yellow";
        return color;
    }
};
class GrannySmith: public Apple{
public:
    string get_name(){
        name = "GrannySmith apple";
        return name;
    }
    string get_color(){
        color = "green";
        return color;
    }
};
//======================================================================================================================


int main(int argc, const char * argv[]) {
    Student student1("Pavel", 18, "man", 69.9, 1);
    Student student2("Alexander", 19, "man", 76.3, 1);
    Student student3("Maxim", 19, "man", 70.2, 1);
    Student student4("Arina", 18, "woman", 59.3, 1);
    Student student5("Julia", 20, "woman", 56.3, 2);
    Student student6("Polina", 21, "woman", 55.6, 3);
    student1.get_count_student();
    student3.get_count_student();
    student5.get_count_student();
    cout << endl;


    Apple a;
    Banana b;
    GrannySmith c;
    cout << "My " << a.get_name() << " is " << a.get_color() << endl;
    cout << "My " << b.get_name() << " is " << b.get_color() << endl;
    cout << "My " << c.get_name() << " is " << c.get_color() << endl;

    return 0;
}
