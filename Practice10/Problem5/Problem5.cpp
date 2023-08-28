#include <iostream>
using namespace std;

bool isPalindrome(const char* word)
{
	int len = strlen(word);
	for (int i = 0; i < len / 2; i++)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

int cyclicalPalindrome(const char* str)
{
	int pos = 0;
	
	char palSentence[100];

	const char* strStart = str;
	const char* strEnd = str + strlen(str);

	const char* currPtr = str;
	const char* helperPtr = str;

	while (*str)
	{
		pos++;
		int ind = 0;

		while (currPtr < strEnd)
			palSentence[ind++] = *currPtr++;

		while (helperPtr < str)
			palSentence[ind++] = *helperPtr++;

		palSentence[ind] = '\0';

		if (isPalindrome(palSentence))
		{
			return pos - 1;
		}

		currPtr = ++str;
		helperPtr = strStart;
	}

	return -1;
}

int main()
{
	cout << cyclicalPalindrome("obi4amma4ibozaaz");

	return 0;
}
