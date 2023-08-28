#include <iostream>
using namespace std;

int countRepetitions(int n, int num)
{
    int count = 0;

    if (n == 0)
    {
        return count;
    }

    if (n % 10 == num)
        return ++count + countRepetitions(n / 10, num);
    else
        return countRepetitions(n / 10, num);
}

int main()
{
    int n, num;
    cin >> n >> num;

    cout << countRepetitions(n, num);

    return 0;
}
