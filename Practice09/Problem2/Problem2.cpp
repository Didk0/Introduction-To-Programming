#include <iostream>
using namespace std;

int main()
{
    const int MAX = 128;
    int arr[MAX];
    
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << ' ';
    } 
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << *(arr + i) << ' ';
    } 
    cout << endl;

    int* pArr = arr;
    for (int i = 0; i < 5; i++)
    {
        cout << *(pArr + i) << ' ';
    }
    cout << endl;

    return 0;
}
