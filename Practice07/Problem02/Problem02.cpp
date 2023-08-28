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

    int belowDiagSum = 0;
    int aboveDiagSum = 0;

    for (int i = 1; i < size; i++)
    {
        for (int j = 0; j < i; j++)
        {
            belowDiagSum += mat[i][j];
        }
    }

    cout << belowDiagSum << endl;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            aboveDiagSum += mat[i][j];
        }
    }

    cout << aboveDiagSum;

    return 0;
}