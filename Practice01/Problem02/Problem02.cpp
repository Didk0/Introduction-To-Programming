#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    // á)
    /*a += b;
    b = a - b;
    a -= b;*/

    // à)
    int temp = a;
    a = b;
    b = temp;

    cout << a << ' ' << b;

    return 0;
}