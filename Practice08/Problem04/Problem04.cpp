#include <iostream>
using namespace std;

int main()
{
	const int MAX_SIZE = 100;
	double arr[MAX_SIZE];

	int n;
	cin >> n;

	double budget;
	cin >> budget;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	//sorting
	for (int i = 0; i < n - 1; i++)
	{
		int minIndex = i;
		for (int j = i; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		if (minIndex != i)
			swap(arr[i], arr[minIndex]);
	}

	double sum = 0;
	int i = 0;
	while (sum <= budget)
	{
		if (arr[i] <= (budget - sum))
		{
			cout << arr[i] << ' ';
			sum += arr[i];
		}
		else
		{
			break;
		}
		i++;
	}

	return 0;
}
