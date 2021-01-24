#include <iostream>
#include <iomanip>
using namespace std;

//****************************************************************************************************

void getSize(int *);
int * getValues(const int);
void doubleValues(int * const, const int);
void displayForward(const int *, const int);
void displayBackward(int * const, const int);
float getAverage(const int * const, const int);
int getMax(const int *, const int);

//****************************************************************************************************

int main()
{
	int * ptData = nullptr;
	int size,
		max,
		maxDouble;
	float average,
		averageDouble;

	getSize(&size);
	ptData = getValues(size);

	displayForward(ptData, size);
	displayBackward(ptData, size);
	average = getAverage(ptData, size);

	cout << "The average is: " << setprecision(2) << average << endl;
	max = getMax(ptData, size);

	cout << "The max is: " << setprecision(2) << max << endl;
	doubleValues(ptData, size);
	displayForward(ptData, size);
	displayBackward(ptData, size);
	averageDouble = getAverage(ptData, size);

	cout << "The average is: " << setprecision(2) << averageDouble << endl;
	maxDouble = getMax(ptData, size);

	cout << "The max is: " << setprecision(2) << maxDouble << endl;
	delete[] ptData;
	ptData = nullptr;

	return 0;
}

//****************************************************************************************************

void getSize(int * test)
{
	cout << "Please enter a size for the array: ";
	cin >> *test;

	while (*test <= 1)
	{
		cout << "Invalid input! Please enter a value greater than 1: ";
		cin >> *test;
	}
}

//****************************************************************************************************

int * getValues(const int SIZE)
{
	int * arr = nullptr;
	arr = new int[SIZE];

	cout << "Please enter " << SIZE << " numbers:" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Value #" << i + 1 << ": ";
		cin >> *(arr + i);
	}

	return arr;
}

//****************************************************************************************************

void doubleValues(int * const ptr, const int SIZE)
{
	cout << "The array values have been doubled!" << endl;

	for (int i = 0; i < SIZE; i++)
	{
		*(ptr + i) *= 2;
	}
}

//****************************************************************************************************

void displayForward(const int * ptr, const int SIZE)
{
	cout << "Here is the array displayed forwards: " << endl;

	for (int i = 0; i < SIZE; i++)
	{
		cout << *(ptr + i) << " ";
	}

	cout << endl;
}

//****************************************************************************************************

void displayBackward(int * const ptr, const int SIZE)
{
	int * ptr2 = ptr + (SIZE);

	cout << "Here is the array displayed backwards: " << endl;

	while (ptr < ptr2)
	{
		ptr2--;
		cout << *ptr2 << " ";
	}

	cout << endl;

}

//****************************************************************************************************

float getAverage(const int * const ptr, const int SIZE)
{
	float sum = 0,
		average;

	for (int i = 0; i < SIZE; i++)
	{
		sum += *(ptr + i);
	}

	average = sum / SIZE;

	return average;
}

//****************************************************************************************************

int getMax(const int * ptr, const int SIZE)
{
	int max;

	for (int i = 1; i < SIZE; i++)
	{
		if (ptr < ptr + i)
		{
			max = *(ptr + i);
		}
	}

	return max;
}

//****************************************************************************************************

/*
Please enter a size to the array: 1
Invalid input! Please enter a value greater than 1: 5
Please enter 5 numbers:
Value #1: 1
Value #2: 2
Value #3: 3
Value #4: 4
Value #5: 5
Here is the array displayed forwards:
1 2 3 4 5
Here is the array displayed backwards:
5 4 3 2 1
The average is: 3
The max is: 5
The array values have been doubled!
Here is the array displayed forwards:
2 4 6 8 10
Here is the array displayed backwards:
10 8 6 4 2
The average is: 6
The max is: 10
Press any key to continue . . .
*/
