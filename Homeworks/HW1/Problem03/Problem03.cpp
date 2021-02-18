#include <iostream>
#include <cmath>
using namespace std;

long long DaysTillMonth(long long month, long long year)
{
	long long temp = 1;
	long long res = 0;
	switch (temp)
	{
	case 1:
		if (month == 1)
			break;
		res += 31;
	case 2:
		if (month == 2)
		{
			break;
		}
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			res += 29;
		}
		else
		{
			res += 28;
		}
	case 3:
		if (month == 3)
			break;
		res += 31;
	case 4:
		if (month == 4)
			break;
		res += 30;
	case 5:
		if (month == 5)
			break;
		res += 31;
	case 6:
		if (month == 6)
			break;
		res += 30;
	case 7:
		if (month == 7)
			break;
		res += 31;
	case 8:
		if (month == 8)
			break;
		res += 31;
	case 9:
		if (month == 9)
			break;
		res += 30;
	case 10:
		if (month == 10)
			break;
		res += 31;
	case 11:
		if (month == 11)
			break;
		res += 30;
	case 12:
		if (month == 12)
			break;
		res += 31;
	default:
		break;
	}

	return res;
}

bool CheckInput(long long dd, long long mm, long long yyyy, long long hh, long long m, long long ss)
{
	switch (mm)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (dd > 31 || dd < 1)
			return false;
		break;
	case 4: case 6: case 9: case 11:
		if (dd > 30 || dd < 1)
			return false;
		break;
	case 2:
		if ((yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0)) && dd > 29)
		{
			return false;
		}
		else if (!(yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0)) && dd > 28)
		{
			return false;
		}
		break;
	default:
		return false;
		break;
	}
	if (yyyy < 0 || yyyy > 9999 || hh < 0 || hh > 23
		|| m < 0 || m > 59 || ss < 0 || ss > 59)
	{
		return false;
	}

	return true;
}

int main()
{
	long long dd1, mm1, yyyy1, hh1, m1, ss1,
		dd2, mm2, yyyy2, hh2, m2, ss2;
	char ch;

	cin >> dd1 >> ch >> mm1 >> ch >> yyyy1 >> hh1 >> ch >> m1 >> ch >> ss1;
	cin >> dd2 >> ch >> mm2 >> ch >> yyyy2 >> hh2 >> ch >> m2 >> ch >> ss2;

	if (!cin || !CheckInput(dd1, mm1, yyyy1, hh1, m1, ss1) || !CheckInput(dd2, mm2, yyyy2, hh2, m2, ss2))
	{
		cout << "Wrong input!";
		return 1;
	}

	long long totalDays1 = 0;
	long long totalDays2 = 0;

	totalDays1 += dd1;
	totalDays2 += dd2;
	totalDays1 += DaysTillMonth(mm1, yyyy1);
	totalDays2 += DaysTillMonth(mm2, yyyy2);

	totalDays1 += yyyy1 * 365 + ((yyyy1 - 1) / 4 - (yyyy1 - 1) / 100 + (yyyy1 - 1) / 400);
	totalDays2 += yyyy2 * 365 + ((yyyy2 - 1) / 4 - (yyyy2 - 1) / 100 + (yyyy2 - 1) / 400);

	long long totalSecs1 = ss1 + m1 * 60 + hh1 * 60 * 60;
	long long totalSecs2 = ss2 + m2 * 60 + hh2 * 60 * 60;

	totalSecs1 += (totalDays1 * 24 * 60 * 60);
	totalSecs2 += (totalDays2 * 24 * 60 * 60);

	long long diffSecs = abs(totalSecs1 - totalSecs2);

	long long days = diffSecs / (3600 * 24);
	diffSecs %= (3600 * 24);
	long long hours = diffSecs / 3600;
	diffSecs %= 3600;
	long long minutes = diffSecs / 60;
	diffSecs %= 60;
	long long seconds = diffSecs % 60;

	if (days > 0)
	{
		cout << days << '-';
	}
	cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes << ":" << (seconds < 10 ? "0" : "") << seconds;

	return 0;
}