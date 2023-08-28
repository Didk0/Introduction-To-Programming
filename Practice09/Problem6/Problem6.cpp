#include <iostream>
using namespace std;

const int MAX = 128;

int* concatArr(const int* arr1, const int* arr2, int size1, int size2, int& newSize)
{
	newSize = size1 + size2;

	if (newSize <= MAX * 2)
	{
		int* newArr = new (nothrow) int[newSize];
		if (!newArr)
		{
			return nullptr;
		}

		for (int i = 0; i < size1; i++)
		{
			newArr[i] = arr1[i];
		}

		for (int i = 0; i < size2; i++)
		{
			newArr[size1 + i] = arr2[i];
		}

		return newArr;
	}
	
	return nullptr;
}

void fillArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}
}

int main()
{
	int size1, size2;
	cin >> size1 >> size2;
	int arr1[MAX], arr2[MAX];
	int newSize = 0;
	fillArr(arr1, size1);
	fillArr(arr2, size2);

	int* newArr = concatArr(arr1, arr2, size1, size2, newSize);

	if (!newArr)
	{
		cout << "Not enough memory!";
		return 1;
	}
	else
	{
		for (int i = 0; i < newSize; i++)
		{
			cout << newArr[i] << ' ';
		}
		cout << endl;
	}

	delete[] newArr;

	return 0;
}