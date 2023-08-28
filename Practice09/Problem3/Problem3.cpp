#include <iostream>
using namespace std;

void clearMat(int** mat, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
}

int main()
{
	int rows, cols;
	cin >> rows >> cols;

	int** mat = new (nothrow) int* [rows];
	if (!mat)
	{
		cout << "Not enough memory!";
		return 1;
	}

	for (int i = 0; i < rows; i++)
	{
		mat[i] = new (nothrow) int[cols];
		if (!mat[i])
		{
			cout << "Not enough memory!";
			clearMat(mat, i);
			return 1;
		}
		for (int j = 0; j < cols; j++)
		{
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << mat[j][i] << ' ';
		}
		cout << endl;
	}

	clearMat(mat, rows);

	return 0;
}
