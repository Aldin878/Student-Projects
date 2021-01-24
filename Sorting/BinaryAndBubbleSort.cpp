#include <iostream>
using namespace std;

//******************************************************************************************************

int getInput();
int linearSearch(const int[], const int, const int);
void bubbleSort(int[], const int);
void displayArray(const int[], const int);
int binarySearch(const int[], const int, const int);


int main()
{
	const int SIZE = 18;
	int numbers[SIZE] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
					   8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
					   1005231, 6545231, 3852085, 7576651, 7881200, 4581002 },
		input;
	input = getInput();
	cout << "-----------Linear Search-----------" << endl;
	linearSearch(numbers, SIZE, input);
	bubbleSort(numbers, SIZE);
	displayArray(numbers, SIZE);
	cout << "-----------Binary Search-----------" << endl;
	binarySearch(numbers, SIZE, input);
	
	return 0;
}

//******************************************************************************************************

int getInput()
{
	int input;

	cout << "Enter the number you would like to search for: ";
	cin >> input;
	return input;
}

//******************************************************************************************************

int linearSearch(const int numbers[], const int size, const int value)
{
	int position = -1;

	for (int i = 0; i < size; i++)
	{
		if (value == numbers[i])
		{
			cout << "The value was found at index number: " << i << "!" << endl;
			position = i;
		}
	}	
		if (position == -1)
	{
			cout << "Sorry! The number you input cannot be found!" << endl;
	}
	return position;
}

//******************************************************************************************************

void bubbleSort(int numbers[], const int size)
{
	bool swap;
	int temp;

	do {
		swap = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (numbers[i] > numbers[i + 1])
			{
				temp = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = temp;
				swap = true;
			}
		}
	
	} 
	while (swap);
}

//******************************************************************************************************

void displayArray(const int numbers[], const int SIZE)
{
	cout << "Here is the array after being sorted by bubble sort: " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << numbers[i] << endl;
	}
}
//******************************************************************************************************

int binarySearch(const int numbers[], const int size, const int value)
{
	int first = 0,
		middle,
		position = -1,
		last = size - 1;
	bool found = false;

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (numbers[middle] == value)
		{
			position = middle;
			cout << "The value was found at index number: " << position << "!" << endl;
			found = true;
		}
		else if (numbers[middle] > value)
		{
			last = middle - 1;
		}
		else
			first = middle + 1;
	}
	if (position == -1)
	{
		cout << "Sorry! The number you input cannot be found!" << endl;
	}
	return position;
}

//******************************************************************************************************
/*
* Output:
Outcome #1:
Enter the number you would like to search for: 4562555
-----------Linear Search-----------
The value was found at index number: 7!
Here is the array after being sorted by bubble sort:
1005231
1250255
1302850
3852085
4520125
4562555
4581002
5050552
5552012
5658845
6545231
7576651
7825877
7881200
7895122
8080152
8451277
8777541
-----------Binary Search-----------
The value was found at index number: 5!
Press any key to continue . . .


Outcome #2:
Enter the number you would like to search for: 1
-----------Linear Search-----------
Sorry! The number you input cannot be found!
Here is the array after being sorted by bubble sort:
1005231
1250255
1302850
3852085
4520125
4562555
4581002
5050552
5552012
5658845
6545231
7576651
7825877
7881200
7895122
8080152
8451277
8777541
-----------Binary Search-----------
Sorry! The number you input cannot be found!
Press any key to continue . . .
*/
