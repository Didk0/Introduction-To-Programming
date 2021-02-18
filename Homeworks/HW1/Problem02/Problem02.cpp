#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	unsigned int num1, num2;
	cin >> num1 >> num2;

	if (!cin)
	{
		cout << "Invalid input!";
		return 1;
	}

	unsigned int minuteMask = (1 << 6) - 1;
	unsigned int firstHourMask = ((1 << 4) - 1) << 6;
	unsigned int secondHourMask = ((1 << 2) - 1) << 10;
	unsigned int formatMask = 1 << 12;

	unsigned int firstNumMinutes = num1 & minuteMask;
	unsigned int secondNumMinutes = num2 & minuteMask;
	unsigned int firstNumHours = ((num1 & firstHourMask) >> 6) + 10 * ((num1 & secondHourMask) >> 10);
	unsigned int secondNumHours = ((num2 & firstHourMask) >> 6) + 10 * ((num2 & secondHourMask) >> 10);
	unsigned int firstNumFormat = formatMask & num1;
	unsigned int secondNumFormat = formatMask & num2;

	unsigned int firstNumTime = firstNumMinutes + 60 * firstNumHours;
	unsigned int secondNumTime = secondNumMinutes + 60 * secondNumHours;

	if (firstNumFormat)
	{
		if (firstNumHours > 23 || firstNumHours < 0 || firstNumMinutes > 59 || firstNumMinutes < 0)
		{
			cout << "Invalid time!";
			return 1;
		}
	}
	else
	{
		if (firstNumHours > 12 || firstNumHours < 0 || firstNumMinutes > 59 || firstNumMinutes < 0)
		{
			cout << "Invalid time!";
			return 1;
		}
	}

	if (secondNumFormat)
	{
		if (secondNumHours > 23 || secondNumHours < 0 || secondNumMinutes > 59 || secondNumMinutes < 0)
		{
			cout << "Invalid time!";
			return 1;
		}
	}
	else
	{
		if (secondNumHours > 12 || secondNumHours < 0 || secondNumMinutes > 59 || secondNumMinutes < 0)
		{
			cout << "Invalid time!";
			return 1;
		}
	}

	cout << (firstNumHours < 10 ? "0" : "") << firstNumHours << ":" << (firstNumMinutes < 10 ? "0" : "") << firstNumMinutes << endl;
	cout << (secondNumHours < 10 ? "0" : "") << secondNumHours << ":" << (secondNumMinutes < 10 ? "0" : "") << secondNumMinutes << endl;

	int diff = firstNumTime - secondNumTime;
	diff = diff > 0 ? diff : -diff;

	int diffHours = diff / 60;
	int diffMinutes = diff % 60;
	cout << "diff " << diffHours << ":" << (diffMinutes < 10 ? "0" : "") << diffMinutes;

	return 0;
}