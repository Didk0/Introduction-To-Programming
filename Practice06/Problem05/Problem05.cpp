#include <iostream>
using namespace std;

void FillArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

int FindBiggestProduct(const int arr[], int size)
{
	if (size >= 2)
	{
		int maxProduct = arr[0] * arr[1];
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] * arr[j] > maxProduct)
				{
					maxProduct = arr[i] * arr[j];
				}
			}
		}
		return maxProduct;
	}
	return -1;
}

int main()
{
	const int MAX_SIZE = 100;
	int arr[MAX_SIZE];
	int size;
	cin >> size;

	FillArr(arr, size);

	cout << FindBiggestProduct(arr, size);

    return 0;
}