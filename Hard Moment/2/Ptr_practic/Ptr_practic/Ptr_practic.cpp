#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include "Timer.h"

using namespace std;

template <typename ptr_1>
void Swap(ptr_1& ptr_first, ptr_1& ptr_second) {
    swap(ptr_first, ptr_second);
}

template <typename vector_ptr>
void SortPointers(vector_ptr& vector_ptr_sort) {
    sort(vector_ptr_sort.begin(), vector_ptr_sort.end(), [](const int* valueA, const int* valueB) { return *valueA < *valueB; });
}

void Vowel_Letters_count_if_find(string vector_count_if_find, const vector<char> vowels) {
    Timer timer("count_if и find");
    auto count_vowel = count_if(vector_count_if_find.begin(), vector_count_if_find.end(), [&](char book) {auto res = find(vowels.begin(), vowels.end(), book); return res != vowels.end(); });
    timer.print();
    cout << "Vowels counts: " << count_vowel << endl << endl;
}

void Vowel_Letters_count_if_for(string vector_count_if_for, const vector<char> vowels) {
    auto count_vowel{ 0u };
    Timer timer("count_if и for");
    count_if(vector_count_if_for.begin(), vector_count_if_for.end(), [&](char book) {
        for (size_t n{ 0u }; n < vowels.size(); ++n) {
            if (book == vowels.at(n)) {
                ++count_vowel;
            }
        }
        return count_vowel;
        });
    timer.print();
    cout << "Vowels counts: " << count_vowel << endl << endl;
}


void Vowel_Letters_for_find(string vector_for_find, const vector<char> vowels) {
    auto count_vowel{ 0u };
    Timer timer("for и find");
    for (const auto& book : vector_for_find) {
        auto res = find(vowels.begin(), vowels.end(), book);
        if (res != vowels.end()) {
            ++count_vowel;
        }
    }
    timer.print();
    cout << "Vowels counts: " << count_vowel << endl << endl;
}


void Vowel_Letters_2_for(string vector_2_for, const vector<char> vowels) {
    auto count_vowel = 0;
    Timer timer("2 for");
    for (const auto& book : vector_2_for) {
        for (size_t n{ 0u }; n < vowels.size(); ++n) {
            if (book == vowels.at(n)) {
                ++count_vowel;
                break;
            }
        }
    }
    timer.print();
    cout << "Vowels counts: " << count_vowel << endl << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "---------------Mission One---------------" << "\n";

    int value_1 = 1;
    int value_2 = 2;
    int* ptr_1 = &value_1;
    int* ptr_2 = &value_2;

    cout << *ptr_1 << " " << *ptr_2 << "\n";

    Swap<>(*ptr_1, *ptr_2);

    cout << *ptr_1 << " " << *ptr_2 << "\n";



    cout << "---------------Mission Two---------------" << "\n";

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int f = 0;

    cout << "enter 5 any number: ";
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> f;

    vector<int*> Arr;
    Arr.push_back(&a);
    Arr.push_back(&b);
    Arr.push_back(&c);
    Arr.push_back(&d);
    Arr.push_back(&f);

    cout << "\n";
    cout << "Disable sort: \n";
    for (int i = 0; i < Arr.size(); i++) {
        int count = 0;
        count = *Arr[i];
        cout << count << ' ';
    }

    SortPointers<>(Arr);

    cout << "\n\n";
    cout << "Enable sort: \n";
    for (int i = 0; i < Arr.size(); i++) {
        int count = 0;
        count = *Arr[i];
        cout << count << ' ';
    }


    cout << "\n";
    cout << "---------------Mission Three---------------" << "\n";

    const vector<char> vowels{ 'а', 'о', 'и', 'е', 'ё', 'э', 'ы', 'у', 'ю', 'я', 'А', 'О', 'И', 'Е', 'Ё', 'Э', 'Ы', 'У', 'Ю', 'Я' };
    ifstream file("Толстой Лев. Война и мир. Книга 1.txt");
    string text;
    if (file.is_open()) {
        file.seekg(0u, ios::end);
        text.reserve(file.tellg());
        file.seekg(0u, ios::beg);
        text.assign(istreambuf_iterator<char>{file}, istreambuf_iterator<char>{});
    }

    file.close();

    Vowel_Letters_count_if_find(text, vowels);
    Vowel_Letters_count_if_for(text, vowels);
    Vowel_Letters_for_find(text, vowels);
    Vowel_Letters_2_for(text, vowels);

    return 0;
}
