#include <iostream>
using namespace std;

int main()
{
	int num;
	cin >> num;

	int temp = num;

	int res = 0;
	
	while (num != 0)
	{
		res *= 10;
		res += num % 10;
		num /= 10;
	}

	cout << res;

	return 0;
}
