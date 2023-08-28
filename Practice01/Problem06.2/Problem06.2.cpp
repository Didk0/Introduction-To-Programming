#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int sum = (m + n) * (m - n + 1) / 2;
    cout << sum;

    return 0;
}