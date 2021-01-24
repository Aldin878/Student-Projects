#include <iostream>
#include <iomanip>
using namespace std;

const int COL_SIZE = 4;
void getData(int[][COL_SIZE], const int);
void displayData(const int[][COL_SIZE], const int);
double getAllAverage(const int[][COL_SIZE], const int);
int getAllHighest(const int[][COL_SIZE], const int);
int getRowSum(const int[][COL_SIZE], const int);
int getColSum(const int[][COL_SIZE], const int, const int);
int getColLowest(const int[][COL_SIZE], const int, const int);
int getColSumRequest();
int getColLowestRequest();
int getRowRequested();

int main()
{
	const int ROW_SIZE = 4;
	int data[ROW_SIZE][COL_SIZE],
		row_request,
		col_request1,
		col_request2,
		col_lowest,
		col_sum;

	getData(data, ROW_SIZE);
	displayData(data, ROW_SIZE);
	cout << "The average of all the data is: " << setprecision(5) << getAllAverage(data, ROW_SIZE) << endl;
	cout << "The highest number is: " << getAllHighest(data, ROW_SIZE) << endl;
	row_request = getRowRequested();
	getRowSum(data, row_request);
	col_request1 = getColSumRequest();
	col_sum = getColSum(data, ROW_SIZE, col_request1);
	cout << "The sum for column " << col_request1 + 1 << " is: " << col_sum << endl;
	col_request2 = getColLowestRequest();
	col_lowest = getColLowest(data, ROW_SIZE, col_request2);
	cout << "The lowest number in column " << col_request2 + 1 << " is: " << col_lowest << endl;

	return 0;
}

//***************************************************************************

void getData(int data[][COL_SIZE], const int ROW)
{
	for (int r = 0; r < ROW; r++)
	{
		cout << "Please enter row #" << r + 1 << ": ";
		for (int c = 0; c < COL_SIZE; c++)
		{
			cin >> data[r][c];
			while (data[r][c] < 0 || data[r][c] > 500)
			{
				cout << "Invalid input! Keep the values between 0 and 500!" << endl;
				cin >> data[r][c];
			}
		}
	}
}

//***************************************************************************

void displayData(const int data[][COL_SIZE], const int ROW)
{
	cout << "You have entered:" << endl;
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			cout << left << setw(5) << data[r][c] << " ";
		}
		cout << endl;
	}
}

//***************************************************************************

double getAllAverage(const int data[][COL_SIZE], const int ROW_SIZE)
{
	double total = 0.0,
		average = 0.0;
	for (int r = 0; r < ROW_SIZE; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			total += data[r][c];
		}
	}
	average = total / (COL_SIZE * ROW_SIZE);

	return average;
}

//***************************************************************************

int getAllHighest(const int data[][COL_SIZE], const int ROW_SIZE)
{
	int highest = 0;
	for (int r = 0; r < ROW_SIZE; r++)
	{
		for (int c = 0; c < COL_SIZE; c++)
		{
			if (data[r][c] > highest)
			{
				highest = data[r][c];
			}
		}
	}
	return highest;
}

//***************************************************************************

int getRowRequested()
{
	int row;
	cout << "Please enter the row you would like to sum: ";
	cin >> row;
	row--;
	return row;
}

//***************************************************************************

int getRowSum(const int data[][COL_SIZE], const int ROW_REQUESTED)
{
	int total = 0;

	for (int c = 0; c < COL_SIZE; c++)
	{
		total = total + data[ROW_REQUESTED][c];
	}

	return total;
}

//***************************************************************************

int getColSumRequest()
{
	int column;

	cout << "Please enter the column you would like to sum: ";
	cin >> column;
	column--;

	return column;
}
//***************************************************************************

int getColSum(const int data[][COL_SIZE], const int ROW_SIZE, const int COL_REQUESTED)
{
	int total = 0;

	for (int r = 0; r < ROW_SIZE; r++)
	{
		total = total + data[r][COL_REQUESTED];
	}

	return total;
}

//***************************************************************************

int getColLowestRequest()
{
	int column;

	cout << "Please enter the column you wish to see the lowest number in: ";
	cin >> column;
	column--;

	return column;
}

//***************************************************************************

int getColLowest(const int data[][COL_SIZE], const int ROW_SIZE, const int COL_REQUESTED)
{
	int lowestNum;

	lowestNum = data[0][COL_REQUESTED];
	for (int r = 0; r < ROW_SIZE; r++)
	{
		if (lowestNum >= data[r][COL_REQUESTED])
		{
			lowestNum = data[r][COL_REQUESTED];
		}
	}

	return lowestNum;
}

//***************************************************************************	
