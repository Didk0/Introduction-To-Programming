#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double EPS = 0.001;
	double x, y;
	cin >> x >> y;

	bool firstQuadrant = x > 0 && y > 0;
	bool secondQuadrant = x < 0 && y > 0;
	bool thirdQuadrant = x < 0 && y < 0;
	bool fourthQuadrant = x > 0 && y < 0;
	bool onAbscissa = abs(x) < EPS;
	bool onOrdinate = abs(y) < EPS;

	if (firstQuadrant)
		cout << "First quadrant";
	else if (secondQuadrant)
		cout << "Second quadrant";
	else if (thirdQuadrant)
		cout << "Third quadrant";
	else if (fourthQuadrant)
		cout << "Fourth quadrant";
	else if (onAbscissa)
		cout << "X axis";
	else
		cout << "Y axis";

	return 0;
}
