#include <iostream>
using namespace std;

//*****************************************************************************************************

int getInput();
void displayRows(int rows);
void displayStars(int stars);

//*****************************************************************************************************

int main()
{
	int n;

	n = getInput();
	displayRows(n);

	return 0;
}

//*****************************************************************************************************

int getInput()
{
	int input;

	cout << "Enter the number of stars you want to display: ";
	cin >> input;

	while (input < 0)
	{
		cout << "Error! Please input a positive integer!" << endl;
		cin >> input;
	}

	return input;
}

//*****************************************************************************************************

void displayRows(int rows)
{
	if (rows > 0)
	{
		displayStars(rows);
		displayRows(rows - 1);
		displayStars(rows);
	}
}

//*****************************************************************************************************

void displayStars(int stars)
{
	if (stars > 0)
	{
		cout << "*";
		displayStars(stars - 1);
	}
	else
		cout << endl;
}

//*****************************************************************************************************
/*
Enter the number of stars you want to display: -5
Error! Please input a positive integer!
-4
Error! Please input a positive integer!
6
******
*****
****
***
**
*
*
**
***
****
*****
******
Press any key to close this window . . .
*/
