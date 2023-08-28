#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cin >> n >> i;

    for (i; i <= n; i++)
    {
        cout << (i * i + 3 * i) << ' ';
    }

    return 0;
}