#include <iostream>
using namespace std;

void FillArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int BiggerNums(const int arr[], int size)
{
	int count = 0;
	for (int i = 1; i < size - 1; i++)
	{
		if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size;
	cin >> size;

	FillArr(arr, size);

	cout << BiggerNums(arr, size) << endl;

	return 0;
}
