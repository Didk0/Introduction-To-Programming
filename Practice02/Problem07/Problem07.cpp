#include <iostream>
using namespace std;

int main()
{
    int x, k;
    cin >> x >> k;
    int mask = 1;

    x *= (mask << k);
    cout << x;

    return 0;
}