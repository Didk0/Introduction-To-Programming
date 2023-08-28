#include <iostream>
using namespace std;

int main()
{
	const int MAX_SIZE = 128;
	int size;
	cin >> size;

	int arr[MAX_SIZE];

	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}

	int len = 1;
	int currLen = 1;

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
		{
			currLen++;
		}
		else
		{			
			currLen = 1;
		}
		if (currLen >= len)
		{
			len = currLen;
		}
	}

	cout << len;

	return 0;
}