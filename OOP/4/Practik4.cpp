#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
//======================================================================================================================
class ArrayInt
{
private:
    int m_length;
    int *m_data;
public:
    ArrayInt(): m_length(0), m_data(nullptr){}
    ArrayInt(int length): m_length(length){
        assert(length >= 0);
        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }
    ~ArrayInt(){
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        m_data = nullptr;
        m_length = 0;
    }

    int getLength() const{
        return m_length;
    }

    int& operator[](int index){
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    void resize(int newLength){
        if (newLength == m_length)
            return;
        if (newLength <= 0)
        {
            erase();
            return;
        }
        int *data = new int[newLength];
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;
            for (int index=0; index < elementsToCopy ; ++index)
                data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index){
        assert(index >= 0 && index <= m_length);
        int *data = new int[m_length+1];
        for (int before=0; before < index; ++before)
            data[before] = m_data[before];
        data [index] = value;
        for (int after=index; after < m_length; ++after)
            data[after+1] = m_data[after];
        delete[] m_data;
        m_data = data;
        ++m_length;
    }

    void push_back(int value){
        insertBefore(value, m_length);
    }

    void pop_back(){
        //создание нового массива
        int *data = new int[m_length];
        //копирование элементов в новый массив с удаленным последним элементом старого массива
        for(int index = 0; index < (m_length - 1); ++index){
            data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
    }

    void pop_front(){
        //создание нового массива
        int *data = new int[m_length];
        //копирование элементов в новый массив с удаленным первым элементом старого массива
        for(int index = 1; index < m_length; ++index){
            data[index] = m_data[index];
        }
        delete[] m_data;
        m_data = data;
    }

    void sort(){
        //создание нового массива
        int *data = new int[m_length];
        //копирование элементов в новый массив
        for(int index = 1; index < m_length; ++index){
            data[index] = m_data[index];
        }
        //сортировка пузырком
        for (int length = 0; length < (m_length - 1); length++){
            for (int index = (m_length - 1); index > length; index--){
                if (data[index - 1] > data[index]){
                    int temp = data[index - 1];
                    data[index - 1] = data[index];
                    data[index] = temp;
                }
            }
        }
        delete[] m_data;
        m_data = data;
    }

    void print(){
        //создание нового массива
        int *data = new int[m_length];
        //копирование элементов в новый массив и вывод массива
        for(int index = 1; index < m_length; ++index){
            data[index] = m_data[index];
            cout << data[index] << " ";
        }
    }
};
//======================================================================================================================
int main() {
    vector<int> array = {1, 2, 3, 2, 4, 4, 3, 2, 6, 6, 8, 8, 9, 9, 2};
    vector<int>::const_iterator it;
    int index = 0;
    int count = 0;
    int repeat_index = 0;
    it = array.begin();
    for (int i = 0; i < array.size(); i++){
        index++;
        count++;
        int value = *it;
        for(int j = index; j < array.size(); j++){
            int repeat_value = array[j];
            if (repeat_value == value) {
                repeat_index++;
                break;
            }
        }
    it++;
    }
    count -= repeat_index;
    cout << count;
    return 0;
}
