#include <iostream>
#include <iomanip>
using namespace std;

//******************************************************************************************************

void getData(long int *, const int);
void displayForward(const long int *, const int);
int getAverage(const long int *, const int);
int getMax(const long int *, const int);
void displayBackward(const long int *, const int);

//******************************************************************************************************

int main()
{
	const int SIZE = 16;
	long int data[SIZE],
		*ptr = nullptr,
		average,
		max;

	ptr = data;

	getData(ptr, SIZE);
	cout << "The array displayed forwards:" << endl;
	displayForward(ptr, SIZE);
	cout << "The array displayed backwards:" << endl;
	displayBackward(ptr, SIZE);
	average = getAverage(ptr, SIZE);

	cout << "The average is: " << left << setw(10) << average << endl;
	max = getMax(ptr, SIZE);

	cout << "The max is: " << left << setw(10) << max << endl;
	return 0;
}

//******************************************************************************************************

void getData(long int * ptr, const int size)
{
	cout << "Please input the population of 16 cities: " << endl;

	for (int i = 0; i < size; i++)
	{
		cin >> *(ptr + i);

		while (*ptr <= 0)
		{
			cout << "Invalid input! Please enter a number greater than 0: " << endl;
			cin >> *ptr;
		}
	}

}
//******************************************************************************************************

int getAverage(const long int * ptr, const int size)
{
	int sum = 0,
		average;

	for (int i = 0; i < size; i++)
	{
		sum += *(ptr + i);
	}

	average = sum / size;
	return average;
}
//******************************************************************************************************

void displayForward(const long int * ptr, const int size)
{
	int space = 0;

	for (int i = 0; i < size; i++)
	{
		cout << left << setw(10) << *(ptr + i) << " ";
		space++;
		if (space % 4 == 0)
		{
			cout << endl;
		}
	}
}

//******************************************************************************************************

int getMax(const long int * ptr, const int size)
{
	int max = * ptr;

	for (int i = 0; i < size; i++)
	{
		if (max <= ptr[i])
		{
		max = ptr[i];
		}
	}
	return max;
}

//******************************************************************************************************

void displayBackward(const long int * ptr, const int size)
{
	const int POSITIVE = 0;
	int space = 0;

	for (int i = size - 1; i >= POSITIVE; i--)
	{
		cout << left << setw(10) << *(ptr + i) << " ";
		space++;
		if (space % 4 == 0)
		{
			cout << endl;
		}
	}
}

//******************************************************************************************************

/*
Please input the population of 16 cities:
-1
Invalid input! Please enter a number greater than 0:
2704958 860090 855164 672795 595047 481420 446970 413651
389902 388072 311404 302398 298800 280364 279789 264488
The array displayed forwards:
2704958    860090     855164     672795
595047     481420     446970     413651
389902     388072     311404     302398
298800     280364     279789     264488
The array displayed backwards:
264488     279789     280364     298800
302398     311404     388072     389902
413651     446970     481420     595047
672795     855164     860090     2704958
The average is: 596582
The max is: 2704958
Press any key to continue . . .

*/
