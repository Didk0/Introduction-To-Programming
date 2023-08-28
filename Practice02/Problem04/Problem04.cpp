#include <iostream>
using namespace std;

int main()
{
	int year;
	cin >> year;

	bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

	cout << (isLeap ? "yes" : "no");

	return 0;
}
