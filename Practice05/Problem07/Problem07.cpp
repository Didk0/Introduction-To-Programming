#include <iostream>
using namespace std;

bool isPrime(int n)
{
	if (n == 1)
	{
		return false;
	}
	else if (n == 2)
	{
		return true;
	}

	if (n % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool sumOfDigitsIsPrime(int n)
{
	int temp = n;
	int digitSum = 0;

	while (temp != 0)
	{
		digitSum += temp % 10;
		temp /= 10;
	}

	return isPrime(digitSum);
}

int main()
{
    int n, m;
    cin >> m >> n;

    int count = 0;

    for (int i = m; i <= n; i++)
    {
		if (sumOfDigitsIsPrime(i))
		{
			cout << i << ' ';
		}
    }

    return 0;
}
