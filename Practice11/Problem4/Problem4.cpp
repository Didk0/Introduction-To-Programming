#include <iostream>

const int MAX = 20;

bool hasPath(int mat[][20], int rows, int cols, int currRow, int currCol, int endRow, int endCol)
{
	if (currRow < 0 || currCol < 0 ||
		currRow >= rows || currCol >= cols)
	{
		return false;
	}
	if (mat[currRow][currCol] != 1)
	{
		return false;
	}
	if (currRow == endRow && currCol == endCol)
	{
		return true;
	}

	mat[currRow][currCol] = 0;

	return	hasPath(mat, rows, cols, currRow + 1, currCol, endRow, endCol) ||
		hasPath(mat, rows, cols, currRow - 1, currCol, endRow, endCol) ||
		hasPath(mat, rows, cols, currRow, currCol + 1, endRow, endCol) ||
		hasPath(mat, rows, cols, currRow, currCol - 1, endRow, endCol);
}

int main()
{
	int mat[MAX][MAX];

	int rows, cols;
	std::cin >> cols >> rows;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cin >> mat[i][j];
		}
	}

	int startRow, startCol, endRow, endCol;
	std::cin >> startRow >> startCol >> endRow >> endCol;

	std::cout << std::boolalpha << hasPath(mat, rows, cols, startRow, startCol, endRow, endCol);
}
