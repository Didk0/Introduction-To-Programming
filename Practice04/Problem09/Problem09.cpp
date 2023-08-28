#include <iostream>
using namespace std;

int main()
{
	int n, mask = 0;
	cin >> n;

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		mask = mask ^ num;
	}

	cout << mask;

	return 0;
}
