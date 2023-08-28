#include <iostream>
using namespace std;

bool equalOneAndZero(int n)
{
	int zeroCount = 0;
	int oneCount = 0;
	int mask = 1;

	while (n != 0)
	{
		if ((n & mask) == 0)
		{
			zeroCount++;
		}
		else
		{
			oneCount++;
		}
		n /= 2;
	}

	return zeroCount == oneCount;
}

int main()
{
	const int NUMBERS = 20;
	int num = 1;
	int count = 1;

	while (count <= NUMBERS)
	{
		if (equalOneAndZero(num))
		{
			cout << num << ' ';
			count++;
		}
		num++;
	}

	return 0;
}