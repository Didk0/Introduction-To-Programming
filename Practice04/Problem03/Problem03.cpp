#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	if (num == 1)
	{
		cout << "Not prime";
		return 1;
	}
	else if (num == 2)
	{
		cout << "Prime";
		return 1;
	}

	bool isPrime = num % 2 == 1;
	for (int i = 3; isPrime && i * i <= num; i += 2)
	{
		if (num % i == 0)
		{
			isPrime = false;
		}
	}

	cout << (isPrime ? "Prime" : "Not prime");

	return 0;
}