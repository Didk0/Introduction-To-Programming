#include <iostream>
using namespace std;

int main()
{
	unsigned long long n;
	double k;
	cin >> n >> k;

	k = pow(10, --k);

	cout << ((n / (int)k) % 10);

	return 0;
}
