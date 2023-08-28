#include <iostream>
using namespace std;

int main()
{
	char ch;
	cin >> ch;

	if (ch >= '0' && ch <= '9')
		cout << (ch - '0') * (ch - '0');
	else if (ch >= 'a' && ch <= 'z')
	{
		ch -= 'a' - 'A';
		cout << ch;
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		ch += 'a' - 'A';
		cout << ch;
	}
	else
		cout << ch;

	return 0;
}