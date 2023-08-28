#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 128;

bool isLetter(char ch)
{
	return ch != ' ' && ch != '\0';
}

void reverse(char* word)
{
	int len = strlen(word);
	for (int i = 0; i < len / 2; i++)
	{
		swap(word[i], word[len - i - 1]);
	}
}

const char* reverse_words(char* sentence, char reversedSentence[MAX_SIZE])
{
	int j = 0;
	while (*sentence)
	{
		int i = 0;
		char word[MAX_SIZE] = "";

		while (isLetter(*sentence))
		{
			word[i] = *sentence;
			i++;
			sentence++;
			j++;
		}

		reverse(word);
		strcat(reversedSentence, word);

		while (*sentence && !isLetter(*sentence))
		{
			reversedSentence[j] = *sentence;
			i++;
			sentence++;
			j++;
		}
	}

	return reversedSentence;
}

int main()
{
	char sentence[MAX_SIZE];

	cin.getline(sentence, MAX_SIZE);

	char result[MAX_SIZE] = "";

	std::cout << reverse_words(sentence, result);

	return 0;
}
