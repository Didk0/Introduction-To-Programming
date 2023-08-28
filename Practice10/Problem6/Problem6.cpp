#include <iostream>
using namespace std;

const int MAX_SIZE = 20;
const char visited = 'X';

bool readWordRec(char table[][MAX_SIZE], int size, const char* word, int currentRow, int currentCol)
{
    if (*word == '\0')
    {
        return true;
    }
    if (currentCol < 0 || currentCol >= size)
    {
        return false;
    }
    if (currentRow < 0 || currentRow >= size)
    {
        return false;
    }
    if (table[currentRow][currentCol] == visited)
    {
        return false;
    }
    if (table[currentRow][currentCol] != *word)
    {
        word--;
        return false;
    }

    table[currentRow][currentCol] = visited;

    return readWordRec(table, size, word + 1, currentRow + 1, currentCol - 1) ||
        readWordRec(table, size, word + 1, currentRow - 1, currentCol - 1) ||
        readWordRec(table, size, word + 1, currentRow - 1, currentCol + 1) ||
        readWordRec(table, size, word + 1, currentRow + 1, currentCol + 1);
}

bool canReadWords(char table[MAX_SIZE][MAX_SIZE], int size, const char* word)
{
    char startLetter = '\0';
    bool isPossible = false;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (table[i][j] == *word)
            {
                isPossible = readWordRec(table, size, word, i, j);
                if (isPossible)
                    return true;
            }
        }
    }

    return isPossible;
}

int main()
{
    char table[MAX_SIZE][MAX_SIZE]{
        {'a', 'p', 'p', 'd'},
        {'k', 'a', 'x', 'p'},
        {'c', 'a', 'a', 'p'},
        {'a', 'k', 'e', 'r'},
    };

    cout << std::boolalpha << canReadWords(table, 4, "kappa") << '\n';
}