#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	const int MAX_ROWS = 50;
	const int MAX_COLS = 50;

	int n = 3, m = 3;
	int mat[MAX_ROWS][MAX_COLS];

	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> mat[i][j];
		}
	}

	int firstCount = 0, secondCount = 0;

	for (int i = 1; i < n - 1; i++)
	{
		for (int j = 1; j < m - 1; j++)
		{
			if ((mat[i-1][j] + mat[i+1][j] + mat[i][j + 1] + mat[i][j-1]) <= mat[i][j])
			{
				firstCount++;
			}
			if (mat[i - 1][j + 1] + mat[i + 1][j] + mat[i - 1][j + 1] + mat[i - 1][j - 1] <= mat[i][j])
			{
				secondCount++;
			}
		}
	}

	cout << firstCount << ' ' << secondCount;

	return 0;
}