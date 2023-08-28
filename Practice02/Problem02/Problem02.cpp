#include <iostream>
using namespace std;

int main()
{
    int years;
    cin >> years;

    unsigned int days = years * 365;
    unsigned int weeks = days / 7;
    unsigned int hours = days * 24;
    unsigned int seconds = hours * 60;

    cout << years << ' ' << weeks << ' ' << days << ' ' << hours << ' ' << seconds;

    return 0;
}