#include <iostream>
using namespace std;

int findFibRec(int n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}

	return findFibRec(n - 1) + findFibRec(n - 2);
}

int main()
{
	int n;
	cin >> n;

	cout << findFibRec(n);

    return 0;
}