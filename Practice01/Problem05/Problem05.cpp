#include <iostream>
using namespace std;

int main()
{
	double x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	cout << dist;

	return 0;
}