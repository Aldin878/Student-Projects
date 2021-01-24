#include <iostream>
#include <fstream>
#include <iomanip>
#include "Results.h"
using namespace std;

//*****************************************************************************************************

void getData(const char filename[], int list[], int size);
bool unOrdSearch(int list[], int size, int searchKey, int & numCompares);
bool ordSearch(int list[], int size, int searchKey, int & numCompares);
bool binSearch(int list[], int size, int searchKey, int & numCompares);
void process(int list[], int size, int searchNums[], Results & result, 
bool (*search)(int list[], int size, int searchKey, int & numCompares));
void updateStats(Results & result);
void displayResults(Results & unOrdResult, Results & ordResult, Results & binResult);

//*****************************************************************************************************

int main()
{
	Results unOrdResult;
	Results ordResult;
	Results binResult;
	int unOrdList[1000];
	int ordList[1000];
	int searchNums[500];

	getData("unordered.txt", unOrdList, 1000);
	getData("ordered.txt", ordList, 1000);
	getData("searchnums.txt", searchNums, 500);
	process(unOrdList, 1000, searchNums, unOrdResult, unOrdSearch);
	process(ordList, 1000, searchNums, ordResult, ordSearch);
	process(ordList, 1000, searchNums, binResult, binSearch);
	updateStats(unOrdResult);
	updateStats(ordResult);
	updateStats(binResult);
	displayResults(unOrdResult, ordResult, binResult);

	return 0;
}

//*****************************************************************************************************

void getData(const char filename[], int list[], int size)
{
	int num;
	int i = 0;
	ifstream file;

	file.open(filename);

	while (file >> num)
	{
		if (i < size)
		{
			list[i] = num;
			i++;
		}
	}

	file.close();
}

//*****************************************************************************************************

bool unOrdSearch(int list[], int size, int searchKey, int & numCompares)
{
	bool found = false;
	int index = 0;
	numCompares = 0;

	while ((index < size) && (++numCompares) && (list[index] != searchKey))
	{
		index++;
	}

	if ((index < size) && (++numCompares) && (list[index] == searchKey))
	{
		found = true;
	}

	return found;
}

//*****************************************************************************************************

bool ordSearch(int list[], int size, int searchKey, int & numCompares)
{
	bool found = false;
	int index = 0;
	numCompares = 0;

	while ((index < size) && (++numCompares) && (list[index] < searchKey))
	{
		index++;
	}

	if ((index < size) && (++numCompares) && (list[index] == searchKey))
	{
		found = true;
	}

	return found;
}

//*****************************************************************************************************

bool binSearch(int list[], int size, int searchKey, int & numCompares)
{
	bool found = false;
	int first = 0,
		last = size - 1,
		middle;
	numCompares = 0;
	
	while (!found && (first <= last))
	{
		middle = (first + last) / 2;

		if (list[middle] < searchKey)
		{
			first = middle + 1;
			numCompares++;
		}

		else if (list[middle] > searchKey)
		{
			last = middle - 1;
			numCompares += 2;
		}

		else
		{
			found = true;
			numCompares += 2;
		}
		
	}

	return found;
}

//*****************************************************************************************************

void process(int list[], int size, int searchNums[], Results & result, 
bool(*search)(int list[], int size, int searchKey, int & numCompares))
{
	int found = false;
	int numCompares;

	for (int i = 0; i < 500; i++)
	{
		found = search(list, size, searchNums[i], numCompares);
		result.numSuccesses += found;
		result.totalCompares += numCompares;
	}
}

//*****************************************************************************************************

void updateStats(Results & result)
{
	result.percSuccesses = (result.numSuccesses / 500.0) * 100;
	result.avgNumCompares = result.totalCompares / 500;
}

//*****************************************************************************************************

void displayResults(Results & unOrdResult, Results & ordResult, Results & binResult)
{
	cout << setw(40) << "Unordered" << setw(40) << "Ordered" << setw(40) << "Binary" << endl;
	cout << setw(41) << "Sequential" << setw(42) << "Sequential" << setw(37) << "Search" << endl;
	cout << setw(37) << "Search" << setw(42) << "Search" << endl;
	cout << "# of Successful Searches" << setw(10) << unOrdResult.numSuccesses << setw(42) 
		 << ordResult.numSuccesses << setw(41) << binResult.numSuccesses << endl;
	cout << setprecision(2) << fixed;
	cout << "% of Searches Successful" << setw(12) << unOrdResult.percSuccesses << "%" << setw(41) 
		 << ordResult.percSuccesses << "%" << setw(40) << binResult.percSuccesses <<  "%" << endl;
	cout << setprecision(0) << fixed;
	cout << "Average Compares / Search" << setw(9) << unOrdResult.avgNumCompares << setw(42) 
		 << ordResult.avgNumCompares << setw(40) << binResult.avgNumCompares << endl;
}

//*****************************************************************************************************

/*
							   Unordered                                 Ordered                                  Binary
							   Sequential                                Sequential                               Search
							   Search                                    Search
# of Successful Searches       242                                       242                                      242
% of Searches Successful       48.40%                                    48.40%                                   48.40%
Average Compares / Search      946                                       227                                      15

Press any key to close this window . . .
*/
