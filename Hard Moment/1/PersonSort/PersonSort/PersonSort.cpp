#include <iostream>
#include <vector>
#include <optional>
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

struct Person
{
    string surname;
    string name;
    string patronymic;

    optional<string> FindPatronymic() {
            if (patronymic != "") {
                return patronymic;
            }
            else {
                return nullopt;
            }
    } 
};

ostream& operator<< (ostream& out, const Person& person) {
    return out << person.surname << " " << person.name << " " << person.patronymic << endl;
}

bool operator<(const Person& p1, const Person& p2) {
    return tie(p1.surname, p1.name, p1.patronymic) < tie(p2.surname, p2.name, p2.patronymic);
}

bool operator==(const Person& p1, const Person& p2) {
    return tie(p1.surname, p1.name, p1.patronymic) == tie(p2.surname, p2.name, p2.patronymic);
}

struct PhoneNumber
{
    int code_country;
    int code_city;
    string phone_number;
    int phone_number_additional;

    optional<int> FindPhoneNumberAdditional() {
        if (phone_number_additional != 0) {
            return phone_number_additional;
        }
        else {
            return nullopt;
        }
    }
};

ostream& operator<< (ostream& out, const PhoneNumber& phonenumber) {
    return out << "+" << phonenumber.code_country << "(" << phonenumber.code_city << ")" << phonenumber.phone_number << " "  << phonenumber.phone_number_additional << endl;
}

class PhoneBook {
private:
    vector<pair<string, string>> Pair_Human;
    vector<pair<string, string>> Pair_PhoneNumber;
public:
    
    void SortByName() {

    };

    void SortByPhone() {

    };

    void GerPhoneNumber() {

    };

    void ChangePhoneNumber() {

    };


};
int main()
{
    string line;
    ifstream file;
    file.open("person.txt");
    if (!file.is_open()) {
        cout << "error";
    }
    else
    {
        string line;
        while (file.good()) {
            getline(file, line);
            cout << line << endl;
        }
    }

    return 0;
}
