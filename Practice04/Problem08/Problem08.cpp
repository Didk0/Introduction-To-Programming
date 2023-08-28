#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int temp = num;
   
    int mask = 1;

    while (temp != 0)
    {
        if ((num & mask) != 0)
        {
            cout << (num & mask) << ' ';
        }
        mask <<= 1;
        temp /= 2;
    }

    return 0;
}