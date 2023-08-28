#include <iostream>
using namespace std;

bool isDecreasing(int n)
{
	int lastNum = n % 10;
	int currNum = n / 10 % 10;

	if (currNum == 0)
		return true;

	if (lastNum < currNum)
		return isDecreasing(n / 10);
	else
		return false;
}

int main()
{
	int n;
	cin >> n;

	cout << isDecreasing(n);

	return 0;
}