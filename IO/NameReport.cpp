#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//****************************************************************************************************

void handleMenu(ifstream &);
int getChoice();
void displayFirstFive(ifstream &);
void displayLastFive(ifstream &);
int count(ifstream &);
void addNewNames();

//****************************************************************************************************

int main()
{
	ifstream fin("names.txt");

	if (!fin)
	{
		cout << "Error! File not found!" << endl;
	}
	else
	{
		handleMenu(fin);
	}
	
	return 0;
}

//****************************************************************************************************

void handleMenu(ifstream & fin)
{
	string line(50, '*');
	const int ONE = 1,
		TWO = 2,
		THREE = 3,
		FOUR = 4,
		FIVE = 5;
	int choice = 0;

	while (choice != FIVE)
	{
		cout << line << endl;
		cout << "1. Display the first five names." << endl;
		cout << "2. Display the last five names." << endl;
		cout << "3. Count the number of names." << endl;
		cout << "4. Add a new name." << endl;
		cout << "5. Quit" << endl;
		cout << line << endl;
		choice = getChoice();

		if (choice == ONE)
		{
			displayFirstFive(fin);
		}

		else if (choice == TWO)
		{
			displayLastFive(fin);
		}

		else if (choice == THREE)
		{
			cout << "There are " << count(fin) << " names." << endl;
		}

		else if (choice == FOUR)
		{
			addNewNames();
		}

		else if (choice == FIVE)
		{
			cout << "Terminating!" << endl;
		}

	}

}

//****************************************************************************************************

int getChoice()
{
	const int ONE = 1;
	const int FIVE = 5;
	int choice;

	cout << "Choose between 1 and 5: ";
	cin >> choice;

	while (choice < ONE || choice > FIVE)
	{
		cout << "Invalid input! Choose between 1 and 5." << endl;
		cin >> choice;
	}

	return choice;
}

//****************************************************************************************************

void displayFirstFive(ifstream & fin)
{
	const int FIVE = 5;
	string line;

	fin.clear();
	fin.seekg(0, ios::beg);

	for (int i = 0; i < FIVE; i++)
	{
		getline(fin, line);
		cout << i + 1 << "." << line << endl;
	}

}

//****************************************************************************************************

void displayLastFive(ifstream & fin)
{
	const int FIVE = 5;
	string line;
	int ctr = 0;
	int length = count(fin);

	fin.clear();
	fin.seekg(0, ios::beg);

	while (getline(fin, line))
	{
		ctr++;

		if (ctr > length - FIVE)
		{
			cout << ctr  << ". " << line << endl;
		}
	}
}

//****************************************************************************************************

int count(ifstream & fin)
{
	string line;
	int count = 0;

	fin.clear();
	fin.seekg(0, ios::beg);

	while (getline(fin, line))
	{
		count++;
	}

	return count;
}

//****************************************************************************************************

void addNewNames()
{
	string name;

	fstream fin("names.txt", ios::out | ios::app);
	cout << "Please input a name: ";
	cin.ignore();
	getline(cin, name);

	fin << "\n" << name;
	fin.close();
	cout << "Done! " << name << " has been entered in." << endl;
}

//****************************************************************************************************

/*
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 1
1.Adriana C. Ocampo Uria
2.Albert Einstein
3.Anna K. Behrensmeyer
4.Blaise Pascal
5.Caroline Herschel
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 2
46. Sir Isaac Newton
47. Stephen Hawking
48. Werner Karl Heisenberg
49. Wilhelm Conrad Roentgen
50. Wolfgang Ernst Pauli
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 3
There are 50 names.
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 4
Please input a name: Shouya Ishida
Done! Shouya Ishida has been entered in.
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 1
1.Adriana C. Ocampo Uria
2.Albert Einstein
3.Anna K. Behrensmeyer
4.Blaise Pascal
5.Caroline Herschel
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 2
47. Stephen Hawking
48. Werner Karl Heisenberg
49. Wilhelm Conrad Roentgen
50. Wolfgang Ernst Pauli
51. Shouya Ishida
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 3
There are 51 names.
**************************************************
1. Display the first five names.
2. Display the last five names.
3. Count the number of names.
4. Add a new name.
5. Quit
**************************************************
Choose between 1 and 5: 5
Terminating!
Press any key to continue . . .
*/
