#include <iostream>
using namespace std;

int countOfChocolates(double money, double price, double wrap)
{
    int count = 0;

    if (money <= 0)
    {
        return count;
    }

    if (money >= price)
    {
        count++;
        return count + countOfChocolates(money - price + wrap, price, wrap);
    }

    return count;
}

int main()
{
    double money, price, wrap;
    cin >> money >> price >> wrap;

    cout << countOfChocolates(money, price, wrap);

    return 0;
}
