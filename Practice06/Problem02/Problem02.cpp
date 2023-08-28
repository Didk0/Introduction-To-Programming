#include <iostream>
using namespace std;

int FindPosition(const int arr[], int size, int elem)
{
    int pos = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
        {
            pos = i + 1;
            break;
        }
    }

    return pos;
}

int main()
{
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size, element;
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cin >> element;

    int position = FindPosition(arr, size, element);
    cout << position;

    return 0;
}
