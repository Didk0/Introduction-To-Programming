#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;

const int MAX_SIZE = 128;

void drawBar(double currentProgress, char leftEndSymbol, char rightEndSymbol, bool showPercent,
	char fillingSymbol, char emptySymbol, unsigned barLength, char bar[MAX_SIZE])
{
	double symbolsToProgress = currentProgress * barLength;

	for (unsigned i = 1; i < symbolsToProgress; i++)
	{
		bar[i] = fillingSymbol;
	}

	unsigned midInd = barLength / 2;
	int percent = currentProgress * 100;

	if (showPercent)
	{
		if (currentProgress < 1)
		{
			bar[midInd] = (percent / 10 % 10) + '0';
			bar[midInd + 1] = (percent % 10) + '0';
			bar[midInd + 2] = '%';
		}
		else
		{
			bar[midInd] = '1';
			bar[midInd + 1] = '0';
			bar[midInd + 2] = '0';
			bar[midInd + 3] = '%';
			bar[barLength - 1] = rightEndSymbol;
		}
	}
}

void init(char leftEndSymbol, char rightEndSymbol, char emptySymbol,
	unsigned barLength, char bar[MAX_SIZE])
{
	bar[0] = leftEndSymbol;
	bar[barLength - 1] = rightEndSymbol;

	for (unsigned i = 1; i < barLength - 1; i++)
	{
		bar[i] = emptySymbol;
	}
}

void print(char bar[MAX_SIZE], unsigned barLength)
{

	for (unsigned i = 0; i < barLength; i++)
	{
		cout << bar[i];
	}
}

int main()
{
	int seconds;
	cin >> seconds;

	if (seconds <= 0 || !cin)
	{
		cout << "Wrong input!" << endl;
		return 1;
	}

	char bar[MAX_SIZE];

	char leftEndSymbol = '<';
	char rightEndSymbol = '>';
	char fillingSymbol = '-';
	char emptySymbol = '.';

	unsigned barLength = 100;
	double currentProgress = 0;
	bool showPercentage = true;

	const int TIME_RATE = 10;
	const double TO_ADD = 0.2;
	const double MAX_TIME = 1.0;
	const int PAUSE = 100;
	int timeToFinish = seconds * TIME_RATE;
	double progress = MAX_TIME / seconds * TO_ADD;

	init(leftEndSymbol, rightEndSymbol, emptySymbol, barLength, bar);

	for (int i = 0; i < timeToFinish; i++)
	{
		drawBar(currentProgress, leftEndSymbol, rightEndSymbol, showPercentage, fillingSymbol, emptySymbol, barLength, bar);
		print(bar, barLength);
		if (currentProgress >= 1)
		{
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(PAUSE));
		system("CLS");
		currentProgress+= progress;
	}

	return 0;
}