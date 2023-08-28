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
        for (int j = 0; j < size; j++)
        {
            if (i != j && j != size - i - 1)
            {
                mat[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
           cout << mat[i][j] << ' ';
        }
        cout << endl;
    }

	return 0;
}