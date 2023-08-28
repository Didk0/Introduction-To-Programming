#include <iostream>
#include <cstring>
using namespace std;

bool isDigit(char ch)
{
	return ch >= '0' && ch <= '9';
}

char* runLengthDecode(char* buffer)
{
	int len = strlen(buffer);

	int ind = 0;
	char* result = buffer;

	for (int i = 0; i < len; i++)
	{
		if (isDigit(buffer[i]))
		{
			int count = 0;
			while (isDigit(buffer[i]))
			{
				count *= 10;
				count += buffer[i] - '0';
				i++;
			}

			for (int j = 0; j < count; j++)
				result[ind++] = buffer[i];
		}
		else
		{
			result[ind++] = buffer[i];
		}
	}

	result[ind] = '\0';

	return result;
}

int main()
{
	char buffer[100];

	cin >> buffer;

	char* result = runLengthDecode(buffer);

	cout << result;

	return 0;
}
