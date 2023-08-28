#include <iostream>
using namespace std;

int main()
{
	unsigned int num, k, l, m, n;
	bool isK = false;
	bool isL = false;
	bool isM = false;
	bool isN = false;

	cin >> num >> k >> l >> m >> n;

	unsigned int mask = 1;
	unsigned int p = 1;

	if ((num & (mask << (k - 1))) != 0)
	{
		isK = true;
		p *= k;
	}
	if ((num & (mask << (l - 1))) != 0)
	{
		isL = true;
		p *= l;
	}
	if ((num & (mask << (m - 1))) != 0)
	{
		isM = true;
		p *= m;
	}
	if ((num & (mask << (n - 1))) != 0)
	{
		isN = true;
		p *= n;
	}

	if (!isK && !isL && !isM && !isN)
	{
		int sum = k + l + m + n;
		double avg = sum / 4.0;
		cout << avg;
	}
	else
		cout << p;


	return 0;
}