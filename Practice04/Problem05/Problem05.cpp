#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int bin = 0;

	while (num != 0)
	{
		bin *= 10;
		if (num % 2 == 1)
		{
			bin += 1;
		}
		num /= 2;
	}

	cout << bin;

	return 0;
}