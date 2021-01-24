#include "NumberArray.h"
#include <iostream>
#include <iomanip>
using namespace std;

//*******************************************************************************************************

NumberArray::NumberArray(int input)
{
	size = input;

	if (arrayPtr != nullptr)
	{
		delete[] arrayPtr;
		arrayPtr = new double[size];
	}

	else
		arrayPtr = new double[size];
	
	for (int i = 0; i < size; i++)
	{
		arrayPtr[i] = 0.0;
	}

}

//*******************************************************************************************************

void NumberArray::setCell(int index, double value)
{
	arrayPtr[index] = value;
}

//*******************************************************************************************************

double NumberArray::getCell(int index) const
{
	return arrayPtr[index];
}

//*******************************************************************************************************

double NumberArray::getAverage() const
{
	double sum = 0,
		average;

	for (int i = 0; i < size; i++)
	{
		sum += arrayPtr[i];
	}
	
	average = sum / size;

	return average;
}

//*******************************************************************************************************

double NumberArray::getHighest() const
{
	double highest = 0;

	for (int i = 0; i < size; i++)
	{
		if (arrayPtr[i] > highest)
		{
			highest = arrayPtr[i];
		}
	}

	return highest;
}

//*******************************************************************************************************

void NumberArray::display() const
{
	cout << fixed << setprecision(2);

	for (int i = 0; i < size; i++)
	{
		cout << arrayPtr[i] << " ";
	}
	
	cout << endl;
}

//*******************************************************************************************************

void NumberArray::sort()
{
	bool swap;
	double temp;

	do
	{
		swap = false;

		for (int i = 0; i < (size - 1); i++)
		{
			if (arrayPtr[i] > arrayPtr[i + 1])
			{
				temp = arrayPtr[i];
				arrayPtr[i] = arrayPtr[i + 1];
				arrayPtr[i + 1] = temp;
				swap = true;
			}
		}
	}
	while(swap);
}

//*******************************************************************************************************

NumberArray::~NumberArray()
{
	delete[] arrayPtr;
}
