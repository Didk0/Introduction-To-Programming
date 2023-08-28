#include <iostream>
using namespace std;

int main()
{
    const int MAX_SIZE = 50;

    int size;
    cin >> size;

    int mat[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < size; i++)
    {
        cout << mat[i][i] << ' ';
    }

    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << mat[i][size - i - 1] << ' ';
    }

    return 0;
}