#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int SIZE = 6;

int FindSecondMax(const int arr[])
{
	int max = arr[0];
	int secondMax = arr[0];

	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] > secondMax)
		{
			if (arr[i] > max)
			{
				secondMax = max;
				max = arr[i];
				continue;
			}
			secondMax = arr[i];
		}
	}

	return secondMax;
}

int main()
{
	int arr[MAX_SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		cin >> arr[i];
	}

	int secondMax = FindSecondMax(arr);

	cout << secondMax;

	return 0;
}