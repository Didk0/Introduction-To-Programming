#include <iostream>
using namespace std;

const int MAX = 100;

void resize(int*& arr, int& size, int newSize)
{
	newSize = size * 2;

	if (newSize <= MAX)
	{
		int* newArr = new (nothrow) int[newSize];
		if (!newArr)
		{
			return;
		}

		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}

		size = newSize;

		delete[] arr;

		arr = newArr;
	}
}

int main()
{
	int size = 5;

	int* arr = new (nothrow) int[size];
	if (!arr)
	{
		cout << "Not enough memory!";
		return 1;
	}

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;

	int newSize = 10;

	resize(arr, size, newSize);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ' ';
	}

	delete[] arr;

	return 0;
}
