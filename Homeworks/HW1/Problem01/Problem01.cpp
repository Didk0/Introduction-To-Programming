#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const double EPS = 0.001;
	float x1, y1, width1, hight1, x2, y2, width2, hight2, area;
	cin >> x1 >> y1 >> width1 >> hight1 >> x2 >> y2 >> width2 >> hight2;

	if (!cin || width1 <= 0 || hight1 <= 0 || width2 <= 0 || hight2 <= 0)
	{
		cout << "Invalid input!";
		return 1;
	}

	float rightTopX1 = x1 + width1;
	float rightTopY1 = y1 + hight1;
	float rightTopX2 = x2 + width2;
	float rightTopY2 = y2 + hight2;

	if (x1 > rightTopX2 || abs(x1 - rightTopX2) < EPS 
		|| x2 >= rightTopX1 || abs(x2 - rightTopX1) < EPS
		|| y1 >= rightTopY2 || abs(y1 - rightTopY2) < EPS
		|| y2 >= rightTopY1 || abs(y2 - rightTopY1) < EPS)
	{
		area = 0;
	}
	else
	{
		float areaWidth = (rightTopX1 < rightTopX2 ? rightTopX1 : rightTopX2) - (x1 > x2 ? x1 : x2);
		float areaHight = (rightTopY1 < rightTopY2 ? rightTopY1 : rightTopY2) - (y1 > y2 ? y1 : y2);
		area = areaWidth * areaHight;
	}

	cout << area;

	return 0;
}