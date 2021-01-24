#include <iostream>
#include <algorithm>
using namespace std;

//*****************************************************************************************************

int findMax(int list[], int size);
void display(int max);

//*****************************************************************************************************

int main()
{
	int list[] = { 10, 7, 25, 600, 345, 432, 0, 125 };
	int size;
	int max;

	size = sizeof(list) / sizeof(int);
	max = findMax(list, size);
	display(max);

	return 0;
}

//*****************************************************************************************************

int findMax(int list[], int size)
{
	int result;

	if (size > 0)
	{
		result = max(list[size - 1], findMax(list, size - 1));
	}
	else
		result = 0;

	return result;
}

//*****************************************************************************************************

void display(int max)
{
	cout << "The max of the array is: " << max << endl;
}

//*****************************************************************************************************

/*
The max of the array is: 600
Press any key to close this window . . .
*/
