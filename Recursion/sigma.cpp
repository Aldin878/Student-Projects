#include <iostream>
using namespace std;

//*****************************************************************************************************

int getInput();
int summation(int n);
void display(int input, int sum);

//*****************************************************************************************************

int main()
{
	int input,
		sum;

	input = getInput();
	sum = summation(input);
	display(input, sum);

	return 0;
}

//*****************************************************************************************************

int getInput()
{
	int input;

	cout << "Enter the number you would like to sum: ";
	cin >> input;

	return input;
}

//*****************************************************************************************************

int summation(int n)
{
	int result;

	if (n > 0)
	{
		result = n + summation(n - 1);
	}
	else
		result = 0;

	return result;
}

//*****************************************************************************************************

void display(int input, int sum)
{
	cout << "summation " << input << " = " << sum;
}

//*****************************************************************************************************

/*
Enter the number you would like to sum: 5
summation 5 = 15
Press any key to close this window . . .
Enter the number you would like to sum: 50
summation 50 = 1275
Press any key to close this window . . .
*/
