#include <iostream>
#include <memory>

using namespace std;

class Date {
private:
    int m_day = 0;
    int m_month = 0;
    int m_year = 0;
public:
    Date(int day, int month, int year) {
        m_day = day;
        m_month = month;
        m_year = year;
    };
    void setDay(int day) {
        m_day = day;
    }
    void setMonth(int month) {
        m_month = month;
    }
    void setYear(int year) {
        m_year = year;
    }
    int getDay() {
        return m_day;
    }
    int getMonth() {
        return m_month;
    }
    int getYear() {
        return m_year;
    }
    ~Date() {}
    friend ostream& operator<< (ostream& os, const Date& a_date);
};
ostream& operator<<(ostream& os, const Date& a_date) {
    os << a_date.m_day << "." << a_date.m_month << "." << a_date.m_year << endl;
    return os;
}

unique_ptr<Date>& sravnenie(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
    if (date1->getYear() > date2->getYear()) {
        cout << *date1 << endl;
        return date1;
    }
    else if (date1->getYear() < date2->getYear()) {
        cout << *date2 << endl;
        return date2;
    }
    else {
        if (date1->getMonth() > date2->getMonth()) {
            cout << *date1 << endl;
            return date1;
        }
        else if (date1->getMonth() < date2->getMonth()) {
            cout << *date2 << endl;
            return date2;
        }
        else {
            if (date1->getDay() > date2->getDay()) {
                cout << *date1 << endl;
                return date1;
            }
            else if (date1->getDay() < date2->getDay()) {
                cout << *date2 << endl;
                return date2;
            }
            else {
                cout << "the dates match" << " " << *date1 << endl;
                return date2;
            }
        }
    }
};
void swaps(unique_ptr<Date>& date1, unique_ptr<Date>& date2) {
    unique_ptr<Date> temp = make_unique<Date>(date1->getDay(), date1->getMonth(), date1->getYear());
    date1 = make_unique<Date>(date2->getDay(), date2->getMonth(), date2->getYear());
    date2 = make_unique<Date>(temp->getDay(), temp->getMonth(), temp->getYear());
}

int main() {
    unique_ptr<Date> today = make_unique<Date>(0, 0, 0);
    today->setDay(8);
    today->setMonth(4);
    today->setYear(2021);
    cout << *today;
    unique_ptr<Date> date = move(today);
    if (today) {
        cout << "ptr today not null" << endl;
    }
    else {
        cout << "ptr today null" << endl;
    }
    if (date) {
        cout << "ptr date not null" << endl;
    }
    else {
        cout << "ptr date null" << endl;
    }

    unique_ptr<Date> date1 = make_unique<Date>(12, 1, 2020);
    unique_ptr<Date> date2 = make_unique<Date>(1, 4, 2021);
    sravnenie(date1, date2);
    swaps(date1, date2);
    cout << *date1;
    cout << *date2;

    return 0;
}
