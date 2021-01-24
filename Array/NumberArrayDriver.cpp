#include "NumberArray.h"
#include <string>
#include <iostream>
using namespace std;

//*******************************************************************************************************

int getNumberOfValues();
int getIndex(int);
void getInput(NumberArray &, int);
void display(NumberArray &, int);
void changeIndex(NumberArray &, int);

//*******************************************************************************************************

int main()
{
	int userInput = getNumberOfValues();

	NumberArray objArr(userInput);
	
	getInput(objArr, userInput);
	display(objArr, userInput);
	changeIndex(objArr, userInput);
	display(objArr, userInput);

	return 0;
}

//*******************************************************************************************************

int getNumberOfValues()
{
	const int MIN_INPUT = 1,
	          MAX_INPUT = 10;
	int size = 0;

	cout << "Enter how many numbers you wish to store (1-10): " << endl;
	cin >> size;

	while (size <= MIN_INPUT || size > MAX_INPUT)
	{
		cout << "Make sure your input is between 2 and 10!" << endl;
		cin >> size;
	}

	return size;
}

//*******************************************************************************************************

int getIndex(int size)
{
	const int MIN_INDEX = 0;
	int userIndex = 0;

	cout << "Enter the index number you wish to change: " << endl;
	cin >> userIndex; 

	while (userIndex < MIN_INDEX || userIndex > size - 1)
	{
		cout << "Error! Your index must be between " << MIN_INDEX << " and " << size - 1 << "!" << endl;
		cin >> userIndex;
	}

	return userIndex;
}

//*******************************************************************************************************

void getInput(NumberArray & objArr, int size)
{
	double num = 0.0;

	cout << "Please enter " << size << " number(s)." << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "Number #" << i + 1 << ": ";
		cin >> num;
		objArr.setCell(i, num);
	}

}

//*******************************************************************************************************

void display(NumberArray & objArr, int size)
{
	string line(60, '-');
	
	cout << line << endl;
	cout << "Here are the numbers you input: " << endl;
	objArr.display();

	objArr.sort();

	cout << "Here are the numbers sorted: " << endl;
	objArr.display();
	
	cout << "The average is: " << objArr.getAverage() << endl;
	cout << "The highest number is: " << objArr.getHighest() << endl;
	cout << line << endl;
}

//*******************************************************************************************************

void changeIndex(NumberArray & objArr, int size)
{
	int input = getIndex(size);
	double newInput = 0.0;

	cout << "The current number on index #" << input << " is: ";
	cout << objArr.getCell(input) << endl;
	cout << "Enter the new number: ";
	cin >> newInput;

	objArr.setCell(input, newInput);

}

//*******************************************************************************************************

/*
Enter how many numbers you wish to store (1-10):
1
Make sure your input is between 2 and 10!
5
Please enter 5 number(s).
Number #1: 56
Number #2: 79
Number #3: 40
Number #4: 152
Number #5: 459
------------------------------------------------------------
Here are the numbers you input:
56.00 79.00 40.00 152.00 459.00
Here are the numbers sorted:
40.00 56.00 79.00 152.00 459.00
The average is: 157.20
The highest number is: 459.00
------------------------------------------------------------
Enter the index number you wish to change:
60
Error! Your index must be between 0 and 4!
2
The current number on index #2 is: 79.00
Enter the new number: 652
------------------------------------------------------------
Here are the numbers you input:
40.00 56.00 652.00 152.00 459.00
Here are the numbers sorted:
40.00 56.00 152.00 459.00 652.00
The average is: 271.80
The highest number is: 652.00
------------------------------------------------------------
Press any key to continue . . .
*/
