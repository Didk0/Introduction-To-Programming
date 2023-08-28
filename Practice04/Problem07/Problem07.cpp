#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int temp = num;
	int mask = 1;
	int bin = 0;
	int value = 1;

	while (temp != 0)
	{
		bin += ((num & mask) == 0 ? 0 : 1) * value;
		value *= 10;
		mask <<= 1;
		temp /= 2;
	}

	cout << bin;

	return 0;
}
