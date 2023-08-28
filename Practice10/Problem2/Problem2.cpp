#include <iostream>
using namespace std;

int atoi(char* str)
{
    int res = 0;
    while (*str >= '0' && *str <= '9')
    {
        res *= 10;
        res += *str - '0';
        str++;
    }

    return res;
}

int main()
{
    std::cout << atoi("123filler") + atoi("-81morefiller") << '\n';

    return 0;
}
