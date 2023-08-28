#include <iostream>
using namespace std;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int s = n * m;

	if (s - n == k || s - m == k)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}