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

    //Person(const string& _surname, const string& _name, const string& _patronymic) :surname(move(_surname)), name(move(_name)), patronymic(move(_patronymic)) {};
};
ostream& operator<< (ostream& out, const Person& person) {
    return out << person.surname << "     " << person.name << "     " << person.patronymic << "     ";
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

    //PhoneNumber(const int& _code_country, const int& _code_city, const string& _phone_number, const int& _phone_number_additional) :code_country(_code_country), code_city(_code_city), phone_number(move(_phone_number)), phone_number_additional(_phone_number_additional) {};
};
ostream& operator<< (ostream& out, const PhoneNumber& phonenumber) {
    return out << "+" << phonenumber.code_country << "(" << phonenumber.code_city << ")" << phonenumber.phone_number << " "  << phonenumber.phone_number_additional;
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) {
    return tie(p1.code_country, p1.code_city, p1.phone_number, p1.phone_number_additional) < tie(p2.code_country, p2.code_city, p2.phone_number, p2.phone_number_additional);
}

class PhoneBook {
private:
    vector<pair<Person, PhoneNumber>> Pair_PhoneBook;
public:
    PhoneBook(ifstream& file) {
        string line_person;
        while (!file.eof()) {
            getline(file, line_person, ';');
            for (const auto& [person, phoneNumber] : Pair_PhoneBook) {
                cout << person.surname;
            }
        };
    };

    void SortByName() {
        sort(Pair_PhoneBook.begin(), Pair_PhoneBook.end(), [](const pair<Person, PhoneNumber>& pairA, const pair<Person, PhoneNumber>& pairB) {
            return pairA.first < pairB.first;});
    };

    void SortByPhone() {
        sort(Pair_PhoneBook.begin(), Pair_PhoneBook.end(), [](const pair<Person, PhoneNumber>& pairA, const pair<Person, PhoneNumber>& pairB) {
            return pairA.second < pairB.second;});
    };

    /*void GetPhoneNumber() {
        for_each(Pair_PhoneBook.begin(), Pair_PhoneBook.end(), [](const pair<Person, PhoneNumber>& pairA, const pair<Person, PhoneNumber>& pairB) {

            });
    };*/

    void ChangePhoneNumber() {

    };

    ~PhoneBook() {};

    friend ostream& operator<<(ostream& out, const PhoneBook &phonebook);
};
ostream& operator<<(ostream& out, const PhoneBook &phonebook) {
    for (const auto& [Person, PhoneNumber] : phonebook.Pair_PhoneBook) {
        out << Person << PhoneNumber;
    }

    return out;
}

int main()
{
    ifstream file("person.txt");
    PhoneBook book(file);
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book;

    return 0;
}
