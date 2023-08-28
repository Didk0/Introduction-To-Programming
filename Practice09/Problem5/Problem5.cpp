#include <iostream>
using namespace std;

const int* adjacent_find(const int* begin, const int* end)
{
    for (begin; begin < end; begin++)
    {
        if (*begin == *(begin + 1))
        {
            return begin;
        }
    }

    return nullptr;
}

void fillArr(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    const int MAX = 128;
    int size;
    cin >> size;
    int arr[MAX];

    fillArr(arr, size);

    const int* res = adjacent_find(arr, &arr[size - 1]);

    if (!res)
    {
        cout << "There is no such element!" << endl;
    }
    else
    {
        cout << *res;
    }

    return 0;
}