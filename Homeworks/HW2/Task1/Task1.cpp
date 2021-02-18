#include <iostream>
using namespace std;

const int MAX_ROWS = 40;
const int MAX_COLS = 40;

void init(char arr[][MAX_COLS])
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			arr[i][j] = ' ';
		}
	}
}

void print(const char board[][MAX_COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		cout << "|";
		for (int j = 0; j < cols; j++)
		{
			cout << board[i][j] << "|";
		}
		cout << endl;
	}
}

bool isFilled(const char board[][MAX_COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (board[i][j] == ' ')
			{
				return false;
			}
		}
	}
	return true;
}

bool checkForWinner(const char board[][MAX_COLS], int rows, int cols)
{
	const int toWin = 3; // броят на еднаквите X/O необходими за победа без текущото

	// проверка по редове
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - toWin; j++)
		{
			if (board[i][j] != ' ' &&
				board[i][j] == board[i][j + 1] &&
				board[i][j] == board[i][j + 2] &&
				board[i][j] == board[i][j + 3])
			{
				return true;
			}
		}
	}

	// проверка по колони
	for (int i = 0; i < cols; i++)
	{
		for (int j = 0; j < rows - toWin; j++)
		{
			if (board[j][i] != ' ' &&
				board[j][i] == board[j + 1][i] &&
				board[j][i] == board[j + 2][i] &&
				board[j][i] == board[j + 3][i])
			{
				return true;
			}
		}
	}

	int min = rows < cols ? rows : cols;

	// проверка по главни диагонали
	for (int i = 0; i < rows - toWin; i++)
	{
		for (int j = 0; j < cols - toWin; j++)
		{
			if (board[i][j] != ' ' &&
				board[i][j] == board[i + 1][j + 1] &&
				board[i][j] == board[i + 2][j + 2] &&
				board[i][j] == board[i + 3][j + 3])
			{
				return true;
			}
		}
	}

	// проверка по второстепенни диагонали
	for (int i = 0; i < rows - toWin; i++)
	{
		for (int j = cols - 1; j >= toWin; j--)
		{
			if (board[i][j] != ' ' &&
				board[i][j] == board[i + 1][j - 1] &&
				board[i][j] == board[i + 2][j - 2] &&
				board[i][j] == board[i + 3][j - 3])
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	int rows, cols;

	cin >> rows >> cols;

	if (rows < 4 || cols < 4 || rows > 20 || cols > 40 || !cin)
	{
		cout << "Wrong input!" << endl;
		return 1;
	}

	char board[MAX_ROWS][MAX_COLS];

	init(board);

	int turn = 1;
	char firstPlayer = 'O';
	char secondPlayer = 'X';

	print(board, rows, cols);

	do
	{
		int col;
		cin >> col;

		if (!cin || col < 1 || col > cols)
		{
			cout << "Wrong input!" << endl;
			return 1;
		}

		col--;

		bool isFull = false;

		for (int i = rows - 1; i >= 0; i--)
		{
			if (board[i][col] == ' ')
			{
				if (turn % 2 == 0)
				{
					board[i][col] = 'X';
					break;
				}
				else
				{
					board[i][col] = 'O';
					break;
				}
			}
			else
			{
				if (i == 0)
				{
					isFull = true;
				}
			}
		}

		if (isFull)
		{
			continue;
		}

		if (checkForWinner(board, rows, cols))
		{
			print(board, rows, cols);
			cout << "Player " << (turn % 2 != 0 ? 1 : 2) << " wins!" << endl;
			break;
		}

		print(board, rows, cols);

		turn++;
	} while (!isFilled(board, rows, cols));


	return 0;
}