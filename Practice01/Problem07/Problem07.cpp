#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double EPS = 0.0001;
	double a, b, c;
	cin >> a >> b >> c;
	double x1, x2;

	if (abs(a) < EPS)
	{
		if (abs(b) < EPS)
		{
			if (abs(c) < EPS)
				cout << "Every x";
			else
				cout << "x = " << c;
		}
		else
		{
			x1 = -c / b;
			cout << "x = " << x1;
		}
	}
	else
	{
		double D = b * b - 4 * a * c;
		if (D > 0)
		{
			x1 = (-b + sqrt(D)) / (2 * a);
			x2 = c / a / x1;
			cout << "x1 = " << x1 << ", x2 = " << x2;
		}
		else if (abs(D) < EPS)
		{
			x1 = -b / 2 * a;
			cout << "x = " << x1;
		}
		else
		{
			cout << "No real answers!";
		}
	}

	return 0;
}