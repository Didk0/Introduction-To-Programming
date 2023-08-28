#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double EPS = 0.001;
	double x, y, r;
	cin >> r >> x >> y;

	double hypotenuse = sqrt(x * x + y * y);
	cout << (r > hypotenuse || (abs(r - hypotenuse) < EPS) ? "true" : "false");

	return 0;
}