#include "BullsAndCows.h"
#include <iostream>

bool isValid(int num)
{
	while (num != 0)
	{
		int temp = num;
		int currDigit = num % 10;
		if (currDigit == 0)
		{
			return false;
		}
		temp /= 10;

		while (temp != 0)
		{
			int tempDigit = temp % 10;

			if (currDigit == tempDigit)
				return false;

			temp /= 10;
		}

		num /= 10;
	}

	return true;
}

int* init(int& size)
{
	const int MIN_NUM = 1234;
	const int MAX_NUM = 9876;

	for (int i = MIN_NUM; i <= MAX_NUM; i++)
	{
		if (isValid(i))
		{
			size++;
		}
	}

	int* arr = new (std::nothrow) int[size];
	if (!arr)
	{
		return nullptr;
	}

	int ind = 0;
	for (int i = 1234; i <= 9876; i++)
	{
		if (isValid(i))
		{
			arr[ind++] = i;
		}
	}

	return arr;
}

int* currBullsCowsPair(int next, int num)
{
	int numToGuessInd = 0;
	int bulls = 0, cows = 0;

	while (num != 0)
	{
		int temp = next;
		int tempInd = 0;
		int currDigit = num % 10;

		while (temp != 0)
		{
			int tempDigit = temp % 10;

			if (currDigit == tempDigit)
			{
				if (numToGuessInd == tempInd)
					bulls++;
				else
					cows++;
			}
			tempInd++;
			temp /= 10;
		}
		numToGuessInd++;
		num /= 10;
	}

	int* newPair = new (std::nothrow) int[2];
	if (!newPair)
	{
		return nullptr;
	}

	newPair[0] = bulls;
	newPair[1] = cows;

	return newPair;
}

int getNewSize(const int* arr, int size, int num, const int* bullsCowsPair)
{
	int bulls = bullsCowsPair[0];
	int cows = bullsCowsPair[1];
	int resSize = 0;

	for (int i = 1; i < size; i++)
	{
		int* nextPair = currBullsCowsPair(arr[i], num);
		int nextBulls = nextPair[0];
		int nextCows = nextPair[1];

		if (bulls == nextBulls && cows == nextCows)
		{
			resSize++;
		}
	}
	return resSize;
}

void initNewArr(const int* arr, int& size, int*& newArr, const int* bullsCowsPair, int num, int newSize)
{
	int bulls = bullsCowsPair[0];
	int cows = bullsCowsPair[1];
	int ind = 0;
	for (int i = 1; i < size; i++)
	{
		int* nextPair = currBullsCowsPair(arr[i], num);
		int nextBulls = nextPair[0];
		int nextCows = nextPair[1];

		if (bulls == nextBulls && cows == nextCows)
		{
			newArr[ind++] = arr[i];
		}
	}
	size = newSize;
}

void play()
{
	int size = 0;
	// »нициализираме масив от всички "валидни" числа
	int* arr = init(size);

	const int MAX_TRIES = 7;

	for (int i = 0; i < MAX_TRIES; i++)
	{
		int num = arr[0];
		const int* bullsCowsPair = tryGuess(num);

		if (bullsCowsPair[0] == 4)
		{
			std::cout << "Number found for " << i + 1 << " attempts." << std::endl;
			delete[] arr;
			return;
		}

		// Ќамираме числата с равни бикове и крави на num
		{
			int newSize = getNewSize(arr, size, num, bullsCowsPair);

			int* newArr = new (std::nothrow) int[newSize];
			if (!newArr)
			{
				delete[] arr;
				return;
			}

			initNewArr(arr, size, newArr, bullsCowsPair, num, newSize);

			delete[] arr;
			arr = newArr;
		}
	}

	delete[] arr;
}