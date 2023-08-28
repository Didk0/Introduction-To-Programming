#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void FillArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

double findAverage(const int arr[MAX_SIZE], int size)
{
	int sum = 0;
	int count = 0;

	for (int i = 0; i < size/2; i++)
	{
		sum += arr[i] * arr[size - i - 1];
		count++;
	}

	double avg = (double)sum / count;

	return avg;
}

int main()
{
	int arr[MAX_SIZE];
	int size;
	cin >> size;

	FillArr(arr, size);

	double avg = findAverage(arr, size);
	cout << avg;

	return 0;
}