#include <iostream>
using namespace std;

const int MAX_SIZE = 10;
int arr[MAX_SIZE] = { 1,2,3,4,5 };
const int SIZE = 5;

void Print()
{
	for (unsigned i = 0; i < SIZE; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void Permutations(int k)
{
	if (k == 0)
	{
		Print();
	}
	else
	{
		Permutations(k - 1);
		for (int i = 0; i < k - 1; i++)
		{
			swap(arr[i], arr[k - 1]);
			Permutations(k - 1);
			swap(arr[i], arr[k - 1]);
		}
	}
}

int main()
{

	Permutations(SIZE);

	return 0;
}
