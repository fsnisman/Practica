#include <iostream>
#include <vector>
#include <optional>
#include <fstream>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Person
{
    string surname;
    string name;
    optional<string> patronymic;

    optional<string> FindPatronymic(optional<string> find_patronymic) {
            if (patronymic == find_patronymic) {
                return nullopt;
            }
            else {
                return patronymic;
            }
    }

    Person(string _surname, string _name, optional<string> _patronymic) :surname(_surname), name(_name), patronymic(_patronymic) {};
};
ostream& operator<< (ostream& out, const Person& person) {
    if (person.patronymic.has_value()) {
        return out << setw(15) << person.surname << setw(15) << person.name << setw(15) << person.patronymic.value();
    }
    else {
        return out << setw(15) << person.surname << setw(15) << person.name << setw(15) << "";
    }
}
bool operator<(const Person& p1, const Person& p2) {
    return tie(p1.surname, p1.name, p1.patronymic) < tie(p2.surname, p2.name, p2.patronymic);
}
bool operator==(const Person& p1, const Person& p2) {
    return tie(p1.surname, p1.name, p1.patronymic) == tie(p2.surname, p2.name, p2.patronymic);
}
bool operator==(const Person& p1, const string& p2) {
    return p1.surname == p2;
}
bool operator!=(const Person& p1, const string& p2) {
    return p1.surname != p2;
}

struct PhoneNumber
{
    int code_country;
    int code_city;
    string phone_number;
    optional<int> phone_number_additional;

    optional<int> FindPhoneNumberAdditional(optional<int>  find_phone_number_additional) {
        if (phone_number_additional == find_phone_number_additional) {
            return  nullopt;
        }
        else {
            return phone_number_additional;
        }
    }

    PhoneNumber(int _code_country, int _code_city, string _phone_number, optional<int> _phone_number_additional) :code_country(_code_country), code_city(_code_city), phone_number(_phone_number), phone_number_additional(_phone_number_additional) {};
};
ostream& operator<< (ostream& out, const PhoneNumber& phonenumber) {
    if (phonenumber.phone_number_additional.has_value()) {
        return out << "+" << phonenumber.code_country << "(" << phonenumber.code_city << ")" << phonenumber.phone_number << "\t" << phonenumber.phone_number_additional.value() << "\r\n";
    }
    else {
        return out << "+" << phonenumber.code_country << "(" << phonenumber.code_city << ")" << phonenumber.phone_number << "\t" << "\r\n";
    }
    
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2) {
    return tie(p1.code_country, p1.code_city, p1.phone_number, p1.phone_number_additional) < tie(p2.code_country, p2.code_city, p2.phone_number, p2.phone_number_additional);
}
auto operator_slogenie(PhoneNumber& p1, const PhoneNumber& p2) {
    return tie(p1.code_country, p1.code_city, p1.phone_number, p1.phone_number_additional) = tie(p2.code_country, p2.code_city, p2.phone_number, p2.phone_number_additional);
};

class PhoneBook {
private:

    string string_check_patronymic;
    string string_code_country;
    string string_code_city;
    string string_phone_number_additional;

    vector<pair<Person, PhoneNumber>> Vector_PhoneBook;
public:
    PhoneBook(ifstream& file) {

        Person person("", "", "");
        PhoneNumber phonenumber(0, 0, "0", nullopt);

        if (file.is_open()) {
            while (!file.eof()) {
                
                file.ignore(1, '\n');

                getline(file, person.surname, ';');
                getline(file, person.name, ';');
                getline(file, string_check_patronymic, ';');
                if (string_check_patronymic == "") {
                    person.patronymic = "";
                    optional<string> check_patronymic = person.FindPatronymic(person.patronymic);
                }
                else {
                    person.patronymic = string_check_patronymic;
                }

                getline(file, string_code_country, ';');
                phonenumber.code_country = stoi(string_code_country);
                
                getline(file, string_code_city, ';');
                phonenumber.code_city = stoi(string_code_city);
                
                getline(file, phonenumber.phone_number, ';');
                
                getline(file, string_phone_number_additional, ';');
                if (string_phone_number_additional != "") {
                    phonenumber.phone_number_additional = stoi(string_phone_number_additional);
                }
                else {
                    optional<int> check_phone_number_additional = phonenumber.FindPhoneNumberAdditional(phonenumber.phone_number_additional);
                }

                Vector_PhoneBook.push_back(make_pair(Person(person.surname, person.name, person.patronymic), PhoneNumber(phonenumber.code_country, phonenumber.code_city, phonenumber.phone_number, phonenumber.phone_number_additional)));
            };
        };
        file.close();
    };

    void SortByName() {
        sort(Vector_PhoneBook.begin(), Vector_PhoneBook.end(), [](const pair<Person, PhoneNumber>& pairA, const pair<Person, PhoneNumber>& pairB) -> bool {
            return pairA.first < pairB.first;});
    };

    void SortByPhone() {
        sort(Vector_PhoneBook.begin(), Vector_PhoneBook.end(), [](const pair<Person, PhoneNumber>& pairA, const pair<Person, PhoneNumber>& pairB) -> bool {
            return pairA.second < pairB.second;});
    };

    tuple<string, PhoneNumber, string> GetPhoneNumber(const string surname) {
        PhoneNumber phonumber(1, 1, "1", 1);
        int check = 0;

        for_each(Vector_PhoneBook.begin(), Vector_PhoneBook.end(), [&, surname](auto const& pairA) -> bool {
            if (pairA.first == surname) {
                check++;
                phonumber = pairA.second;
                return true;
            }
           });

        if (check == 1) {
            return tuple("", phonumber, "");
        }
        if (check > 1) {
            return tuple("", phonumber, "found more than 1");
        }
        if (check < 1) {
            return tuple("not found", phonumber, "");
        }
    };

    void ChangePhoneNumber(const Person person, const PhoneNumber phonenumber) {
        find_if(Vector_PhoneBook.begin(), Vector_PhoneBook.end(), [person, phonenumber](auto& pairA) -> bool { if (pairA.first == person) { operator_slogenie(pairA.second, phonenumber); cout << pairA.first << pairA.second; return true; };});
    };

    ~PhoneBook() {};

    friend ostream& operator<<(ostream& out, const PhoneBook &phonebook);
};
ostream& operator<<(ostream& out, const PhoneBook &phonebook) {
    for (const auto& [Person, PhoneNumber] : phonebook.Vector_PhoneBook) {
        out << Person << PhoneNumber;
    }

    return out;
}

int main()
{

    ifstream file("person.txt");
    PhoneBook book(file);
    
    cout << "------All user-------" << endl;
    cout << setiosflags(ios::left) << book << endl;
    
    cout << "------SortByPhone-------" << endl;
    book.SortByPhone();
    cout << book << endl;

    cout << "------SortByName--------" << endl;
    book.SortByName();
    cout << book << endl;

    cout << "-----GetPhoneNumber-----" << endl;
    auto print_phone_number = [&book](const string& surname) {
        cout << surname << "\t";
        auto answer = book.GetPhoneNumber(surname);
            if (get<0>(answer).empty())
                cout << get<1>(answer);
            else
                cout << get<0>(answer);
        };
    print_phone_number("Ivanov");
    print_phone_number("Petrov");

    cout << endl << endl;

    cout << "----ChangePhoneNumber----" << endl;
    book.ChangePhoneNumber(Person{ "Kotov", "Vasilii", "Eliseevich" }, PhoneNumber{ 7, 123, "15344458", nullopt });
    book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" }, PhoneNumber{ 16, 465, "9155448", 13 });

    return 0;
}
