#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    double bitcoins, percent;
    cin >> bitcoins >> percent;

    double diff = (percent / 100) * bitcoins;
    
    cout << (bitcoins + diff) << ' ' << diff << endl;    

    return 0;
}
