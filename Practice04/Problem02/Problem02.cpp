#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

	int res = 0;
	int temp = num;

	while (temp != 0)
	{
		res *= 10;
		res += temp % 10;
		temp /= 10;
	}

	cout << (num == res ? "Yes" : "No");

    return 0;
}
