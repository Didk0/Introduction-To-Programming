#include <iostream>
using namespace std;

const int MAX_SIZE = 8196;

char temp[MAX_SIZE];

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

bool validateNums(const char* num1, const char* num2)
{
	while (*num1)
	{
		if (!isDigit(*num1))
		{
			return false;
		}
		num1++;
	}

	while (*num2)
	{
		if (!isDigit(*num2))
		{
			return false;
		}
		num2++;
	}

	return true;
}

int sizeOfNum(const char* num)
{
	int res = 0;

	while (*num)
	{
		num++;
		res++;
	}
	return res;
}

void reverse(char num[], int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(num[i], num[size - 1 - i]);
	}
}

bool areEqual(const char num1[], const char num2[], int size1, int size2)
{
	if (size1 == size2)
	{
		for (int i = 0; i < size1; i++)
		{
			if (num1[i] != num2[i])
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

int compare(const char num1[], const char num2[], int size1, int size2)
{
	if (size1 > size2)
	{
		return 1;
	}
	else if (size1 < size2)
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < size1; i++)
		{
			if (num1[i] > num2[i])
			{
				return 1;
			}
			else if (num1[i] < num2[i])
			{
				return -1;
			}
		}
	}
}

void print(const char num[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (num[i] == '0')
		{
			count++;
		}
	}

	if (count == size)
	{
		cout << '0';
		return;
	}

	for (int i = 0; i < size; i++)
	{
		cout << num[i];
	}
	cout << endl;
}


void sumOfNums(char num1[], char num2[], int size1, int size2)
{
	char result[MAX_SIZE];

	reverse(num1, size1);
	reverse(num2, size2);

	int inMind = 0;

	int resSize = size1;

	for (int i = 0; i < size1; i++)
	{
		if (i < size2)
		{
			int res = (int)(num1[i] - '0') + (int)(num2[i] - '0') + inMind;

			if (res > 9)
			{
				inMind = 1;
			}
			else
			{
				inMind = 0;
			}

			result[i] = (res % 10) + '0';
		}
		else
		{
			int res = (int)(num1[i] - '0') + 0 + inMind;
			inMind = 0;
			result[i] = (res % 10) + '0';
		}
	}

	if (inMind == 1)
	{
		result[resSize] = '1';
		resSize++;
	}

	reverse(result, resSize);
	reverse(num1, size1);
	reverse(num2, size2);

	cout << num1 << " + " << num2 << " = ";
	print(result, resSize);
}

void diffOfNums(char num1[], char num2[], int size1, int size2)
{
	char result[MAX_SIZE];

	for (int i = 0; i < size1; i++)
	{
		temp[i] = num1[i];
	}

	reverse(temp, size1);
	reverse(num2, size2);

	int resSize = 0;

	for (int i = 0; i < size1; i++)
	{
		if (i < size2)
		{
			if (temp[i] >= num2[i])
			{
				result[i] = ((int)(temp[i] - '0') - (int)(num2[i] - '0')) + '0';
			}
			else
			{
				int res = ((int)(temp[i] - '0') + 10) - (int)(num2[i] - '0');
				result[i] = res + '0';

				int ind = i;
				while (temp[ind + 1] == '0')
				{
					temp[ind + 1] = '9';
					++ind;
				}
				temp[ind + 1] = ((int)(temp[ind + 1] - '0') - 1) + '0';
			}
			resSize++;
		}
		else
		{
			if (temp[i] != '0')
			{
				result[i] = temp[i];
				resSize++;
			}
		}
	}

	reverse(result, resSize);
	reverse(num2, size2);

	cout << num1 << " - " << num2 << " = ";
	print(result, resSize);
}

//char* sumForMultiplication(char* result, char num1[], char num2[], int size1, int size2)
//{
//	reverse(num1, size1);
//	reverse(num2, size2);
//
//	int inMind = 0;
//
//	int resSize = size1;
//
//	for (int i = 0; i < size1; i++)
//	{
//		if (i < size2)
//		{
//			int res = (int)(num1[i] - '0') + (int)(num2[i] - '0') + inMind;
//
//			if (res > 9)
//			{
//				inMind = 1;
//			}
//			else
//			{
//				inMind = 0;
//			}
//
//			result[i] = (res % 10) + '0';
//		}
//		else
//		{
//			int res = (int)(num1[i] - '0') + 0 + inMind;
//			inMind = 0;
//			result[i] = (res % 10) + '0';
//		}
//	}
//
//	if (inMind == 1)
//	{
//		result[resSize] = '1';
//		resSize++;
//	}
//
//	reverse(result, resSize);
//	reverse(num1, size1);
//	reverse(num2, size2);
//
//	return result;
//}

char result[MAX_SIZE * 2];
void productOfNums(char num1[], char num2[], int size1, int size2)
{
	int tempInd = 0;
	for (int i = size1 - 1; i >= 0; i--)
	{
		int num1CurrDigit = num1[i] - '0';
		int inMind = 0;
		int j;
		for (j = size2 - 1; j >= 0; j--)
		{
			int num2CurrDigit = num2[j] - '0';
			int product = ((num1CurrDigit * num2CurrDigit) + inMind);
			temp[tempInd++] = product % 10 + '0';
			inMind = product / 10;
		}
		if (inMind > 0)
		{
			temp[tempInd++] = inMind;
		}

		reverse(temp, tempInd);
		for (j = 0; j < size1 - 1 - i; j++)
		{
			temp[tempInd++] = '0';
		}

		
	}
}

char num1[MAX_SIZE];
char num2[MAX_SIZE];

int main()
{
	cin >> num1 >> num2;

	if (!validateNums(num1, num2))
	{
		cout << "Not a number!";
		return 1;
	}

	int num1Size = sizeOfNum(num1);
	int num2Size = sizeOfNum(num2);

	if (num1Size == 0 || num2Size == 0)
	{
		cout << "Wrong input!";
		return 1;
	}

	if ((num1Size > 1 && num1[0] == '0') || (num2Size > 1 && num2[0] == '0'))
	{
		cout << "Wrong input!";
		return 1;
	}

	if (areEqual(num1, num2, num1Size, num2Size))
	{
		cout << num1 << " == " << num2 << endl;
		sumOfNums(num1, num2, num1Size, num2Size);
		diffOfNums(num1, num2, num1Size, num2Size);
	}
	else
	{
		cout << num1 << " != " << num2 << endl;

		if (compare(num1, num2, num1Size, num2Size) == 1)
		{
			cout << num1 << " > " << num2 << endl;

			sumOfNums(num1, num2, num1Size, num2Size);
			diffOfNums(num1, num2, num1Size, num2Size);
		}
		else
		{
			cout << num1 << " < " << num2 << endl;

			sumOfNums(num2, num1, num2Size, num1Size);
			diffOfNums(num2, num1, num2Size, num1Size);
		}
	}

	return 0;
}