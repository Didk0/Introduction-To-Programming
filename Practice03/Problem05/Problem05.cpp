#include <iostream>
using namespace std;

int main()
{
    double l1x, l1y, r1x, r1y, l2x, l2y, r2x, r2y;
    cin >> l1x >> l1y >> r1x >> r1y >> l2x >> l2y >> r2x >> r2y;

    if (l1x > r2x || l2x > r1x || l1y < r2y || l2y < r1y)
    {
        cout << "No";
    }
    else
        cout << "Yes";

    return 0;
}
