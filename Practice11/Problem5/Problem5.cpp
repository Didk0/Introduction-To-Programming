#include <iostream>
using namespace std;

void towerOfHanoi(int n, char first,
    char second, char third)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << first <<
            " to " << second << endl;
        return;
    }
    towerOfHanoi(n - 1, first, third, second);
    cout << "Move disk " << n << " from " << first <<
        " to " << second << endl;
    towerOfHanoi(n - 1, third, second, first);
}

int main()
{
    int n;
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}