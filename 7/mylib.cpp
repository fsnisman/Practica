#include <iostream>

void ARRAY_FLOAT_DINAMIC_PRINT(float element, int& size)
{
	std::cout << element << " ";
}

void ARRAY_FLOAT_DINAMIC_TRUE_FALSE(float a[], int& size)
{
	int quantity_true = 0;
	int quantity_false = 0;

	for (int i = 0; i < size; i++)
	{
		if (a[i] > 0)
		{
			quantity_true++;
		}
		else if (a[i] < 0)
		{
			quantity_false++;
		}
	}

	std::cout << "Количество положительных элементов: " << quantity_true << std::endl;
	std::cout << "Количество отрицательных элементов: " << quantity_false << " ";

}

void ARRAY_FLOAT_DINAMIC(int size)
{
	int f;
	float element = 0;
	float* ptrArr;

	ptrArr = new float[size];

	for (int i = 0; i < size; i++)
	{
		ptrArr[i] = static_cast<float>(rand()) / RAND_MAX;
		if (f = rand() % 2 == 1)
		{
			ptrArr[i] = -ptrArr[i];
		}
		element = ptrArr[i];
		ARRAY_FLOAT_DINAMIC_PRINT(element, size);
	}
	std::cout << std::endl;
	ARRAY_FLOAT_DINAMIC_TRUE_FALSE(ptrArr, size);
	delete[] ptrArr;
}