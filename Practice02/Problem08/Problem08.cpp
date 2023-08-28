#include <iostream>
using namespace std;

int main()
{
	const unsigned int BITS_TO_MOVE = 8;
	unsigned int num;
	cin >> num;

	unsigned int mask = 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;
	mask = mask << 1 | 1;

	cout << (mask & num) << ' ';

	num >>= BITS_TO_MOVE;
	cout << (mask & num) << ' ';

	num >>= BITS_TO_MOVE;
	cout << (mask & num) << ' ';

	num >>= BITS_TO_MOVE;
	cout << (mask & num) << ' ';

	return 0;
}