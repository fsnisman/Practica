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
void SortPointers(vector_ptr& vector_ptr_sort){
    sort(vector_ptr_sort.begin(), vector_ptr_sort.end(), [](const int* valueA, const int* valueB) { return *valueA < *valueB; });
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
    

    return 0;
}
