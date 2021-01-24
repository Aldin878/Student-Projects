#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//*****************************************************************************************************

void displayNum(long long int bigNum, int seg);

//*****************************************************************************************************

int main()
{
	long long int bigNum;
	int seg;
	int divisor;
	ifstream file("bigNums.txt");

	while (file >> bigNum)
	{
		file >> seg;
		divisor = (int)pow(10, seg);
		displayNum(bigNum, divisor);
	}

	file.close();

	return 0;
}

//*****************************************************************************************************

void displayNum(long long int bigNum, int divisor)
{
	if (bigNum > 0)
	{
		displayNum(bigNum / divisor, divisor);
		cout << bigNum % divisor << endl;
	}
	else
		cout << endl;
}

//*****************************************************************************************************
/*


1
2
3
4

123
4567
8912
3456
7891

1234
56789
12345
67891

12
345
678

1
23
45
67


Press any key to close this window . . .
*/
