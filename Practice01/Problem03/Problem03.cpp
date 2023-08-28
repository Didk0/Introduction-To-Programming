#include <iostream>
using namespace std;

int main()
{
    const double COUNT = 3;
    unsigned int a, b, c;
    cin >> a >> b >> c;

    unsigned int sum = a + b + c;
    double avg = sum / COUNT;
    cout << avg;

    return 0;
}
