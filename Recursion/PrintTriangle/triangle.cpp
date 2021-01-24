#include <iostream>
using namespace std;

//*****************************************************************************************************

int getInput();
void displayTriangle(int min, int max);
void displayRowStars(int numStars);

//*****************************************************************************************************

int main()
{
	int max,
		min = 1;

	max = getInput();
	displayTriangle(min, max);
}

//*****************************************************************************************************

int getInput()
{
	int max;

	cout << "Please enter your input: " << endl;
	cin >> max;

	while (max < 0)
	{
		cout << "This is not a valid input! Please try again: "; 
		cin >> max;
	}

	return max;
}

//*****************************************************************************************************

void displayTriangle(int min, int max)
{
	if (min <= max)
	{
		displayRowStars(min);
		displayTriangle(min + 1, max);
		displayRowStars(min - 1);
	}
}

//*****************************************************************************************************

void displayRowStars(int numStars)
{
	if (numStars > 0)
	{
		cout << "*" << " ";
		displayRowStars(numStars - 1);
	}
	else
		cout << endl;
}

//*****************************************************************************************************
/*
Please enter your input:
-1
This is not a valid input! Please try again: -3
This is not a valid input! Please try again: 5
*
* *
* * *
* * * *
* * * * *
* * * *
* * *
* *
*


Press any key to close this window . . .
*/
