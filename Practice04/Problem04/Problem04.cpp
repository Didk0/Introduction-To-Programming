#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int div = 2;

	while (num != 1)
	{
		if (num % div == 0)
		{
			cout << div << ' ';
		}

		while (num % div == 0)
		{
			num /= div;
		}

		div++;
	}

	return 0;
}
