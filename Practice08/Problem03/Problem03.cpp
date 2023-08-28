#include <iostream>
using namespace std;

const int n1 = 2;
const int m1 = 3;
const int n2 = 3;
const int m2 = 1;

void ProductMat(const int mat1[][m1], const int mat2[][m2], int rows1, int cols1, int rows2, int cols2)
{
	int res[n1][m2];

	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			res[i][j] = 0;
			for (int k = 0; k < cols1; k++)
			{
				res[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}

	for (int i = 0; i < rows1; i++)
	{
		for (int j = 0; j < cols2; j++)
		{
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	if (m1 != n2)
	{
		return 1;
	}

	int mat1[n1][m1];
	int mat2[n2][m2];

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			cin >> mat1[i][j];
		}
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < m2; j++)
		{
			cin >> mat2[i][j];
		}
	}

	cout << endl;
	ProductMat(mat1, mat2, n1, m1, n2, m2);

	return 0;
}