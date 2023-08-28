#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;

	double p = a + b + c;
	cout << p << ' ';

	double halfP = p / 2;

	double s = sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
	cout << s;

	return 0;
}