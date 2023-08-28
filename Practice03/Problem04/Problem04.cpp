#include <iostream>
using namespace std;

int main()
{
	int n1, m1, n2, m2;

	cin >> n1 >> m1 >> n2 >> m2;

	if (abs(n1 - n2) == abs(m1 - m2))
		cout << "Yes";
	else
		cout << "No";

		return 0;
}