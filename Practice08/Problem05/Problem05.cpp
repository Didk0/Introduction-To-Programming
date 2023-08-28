#include <iostream>
using namespace std;
const int MAX_ARR_SIZE = 100;

void FillArr(int arr[], int size);
void GuessTheNumber(int lower, int higher, int& money);

int main()
{
	int lower, higher;
	std::cout << "Enter lower limit: ";
	std::cin >> lower;
	std::cout << "Enter higher limit: ";
	std::cin >> higher;

	int money = 0;

	GuessTheNumber(lower, higher, money);

	cout << endl << money << endl;

	return 0;
}

void FillArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
}

void GuessTheNumber(int lower, int higher, int& money)
{
	char answer;

	do
	{
		money++;

		int middle = lower + (higher - lower) / 2;

		if (higher == lower)
		{
			cout << "Your number is: " << middle;
			return;
		}

		cout << "Is your number: " << middle << "?  ( (u)p / (d)own / (y)es )\n";
		do
		{
			cin >> answer;
		} while (answer != 'y' && answer != 'u' && answer != 'd');


		switch (answer)
		{
		case 'u':
			lower = middle + 1;
			break;
		case 'd':
			higher = middle - 1;
			break;
		default:
			break;
		}
	} while (answer != 'y');
}