#include <iostream>
using namespace std;

void clearMat(int** tasks, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] tasks[i];
	}
	delete[] tasks;
}

void sortTasksByPointsForMin(int**& tasks, int count)
{
	for (int i = 0; i < count - 1; i++)
	{
		int maxIndex = i;
		for (int j = i; j < count; j++)
		{
			if (((double)tasks[j][1] / tasks[j][2]) < ((double)tasks[maxIndex][1] / tasks[maxIndex][2]))
				maxIndex = j;
			else if (((double)tasks[j][1] / tasks[j][2]) == ((double)tasks[maxIndex][1] / tasks[maxIndex][2]))
			{
				if (tasks[j][1] < tasks[maxIndex][1])
				{
					maxIndex = j;
				}
			}
		}
		if (maxIndex != i)
			swap(tasks[i], tasks[maxIndex]);
	}
}

void print(const int *const *const tasks, int maxInd, int allTime, int tasksCount)
{
	cout << tasks[maxInd][0];
	allTime -= tasks[maxInd][1];
	for (int i = maxInd + 1; i < tasksCount; i++)
	{
		if (allTime - tasks[i][1] >= 0)
		{
			allTime -= tasks[i][1];
			cout << ", " << tasks[i][0];
		}
	}
	cout << endl;

	int allTimeMins = allTime / 60;
	int allTimeSecs = allTime % 60;
	cout << "Time remaining: " << allTimeMins << ":" << allTimeSecs;
}

int main()
{
	const int TASK_SIZE = 3;
	int tasksCount;
	cin >> tasksCount;

	if (!cin || tasksCount < 1)
	{
		cout << "Wrong input!" << endl;
		return 1;
	}

	int** tasks = new (nothrow) int* [tasksCount];
	if (!tasks)
	{
		cout << "Not enough memory!" << endl;
		return 1;
	}

	for (int i = 0; i < tasksCount; i++)
	{
		tasks[i] = new (nothrow) int[TASK_SIZE];
		if (!tasks[i])
		{
			cout << "Not enough memory!" << endl;
			clearMat(tasks, i);
			return 1;
		}
		for (int j = 0; j < TASK_SIZE; j++)
		{
			cin >> tasks[i][j];
			if (!cin)
			{
				clearMat(tasks, i);
				cout << "Wrong input!" << endl;
				return 1;
			}
		}
		if (tasks[i][0] < 0 || tasks[i][1] < 1 || tasks[i][2] < 1)
		{
			clearMat(tasks, i);
			cout << "Wrong input!" << endl;
			return 1;
		}
	}

	int daysLeft;
	cin >> daysLeft;

	if (!cin || daysLeft < 1)
	{
		clearMat(tasks, tasksCount);
		cout << "Wrong input!";
		return 1;
	}

	int allTime = 0;

	int* minutes = new (nothrow) int[daysLeft];
	if (!minutes)
	{
		cout << "Not enought memory!";
		clearMat(tasks, tasksCount);
		return 1;
	}
	for (int i = 0; i < daysLeft; i++)
	{
		cin >> minutes[i];
		if (!cin || minutes[i] <= 0)
		{
			clearMat(tasks, tasksCount);
			delete[] minutes;
			cout << "Wrong input!";
			return 1;
		}
		allTime += minutes[i];
	}

	sortTasksByPointsForMin(tasks, tasksCount);

	// Ќамираме началото на "най-добрата" поредица
	int maxTasks = 0;
	int maxInd = 0;
	int maxPoints = 0;
	for (int i = 0; i < tasksCount; i++)
	{
		int currInd = i;
		int currTasks = 0;
		int currPoints = 0;
		int tempTime = allTime;
		for (int j = i; j < tasksCount; j++)
		{
			if (tempTime - tasks[j][1] >= 0)
			{
				tempTime -= tasks[j][1];
				currTasks++;
				currPoints += tasks[j][2];
			}
		}
		if (maxTasks < currTasks && maxPoints < currPoints)
		{
			maxTasks = currTasks;
			maxInd = currInd;
			maxPoints = currPoints;
		}
	}

	print(tasks, maxInd, allTime, tasksCount);	

	clearMat(tasks, tasksCount);
	delete[] minutes;

	return 0;
}
