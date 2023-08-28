#include <iostream>
using namespace std;

const int* findFirstOf(const int* fBegin, const int* fEnd, const int* sBegin, const int* sEnd)
{
    for (fBegin; fBegin <= fEnd; fBegin++)
    {
        const int* temp = sBegin;
        for (temp; temp <= sEnd; temp++)
        {
            if (*fBegin == *temp)
            {
                return fBegin;
            }
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
    int arr1[MAX], arr2[MAX];

    fillArr(arr1, size);
    fillArr(arr2, size);

    const int* res = findFirstOf(arr1, &arr1[size - 1], arr2, &arr2[size - 1]);

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