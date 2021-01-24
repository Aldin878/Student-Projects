#include "Employee.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//*******************************************************************************************************

void displayAllEmployeeRecord(const Employee *, const int);
void getInput(Employee *, const int);

//*******************************************************************************************************

int main()
{
	const int SIZE = 5;
	Employee * ptrEmp = new Employee[SIZE];

	getInput(ptrEmp, SIZE);
	displayAllEmployeeRecord(ptrEmp, SIZE);

	delete[] ptrEmp;
}

//*******************************************************************************************************

void getInput(Employee * ptrEmp, const int SIZE)
{
	string name;
	int id;
	double salary;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Enter the information for Employee #" << i + 1 << ": " << endl;
		cout << "ID: ";
		cin >> id;

		while (id < 1000 || id > 2000)
		{
			cout << "Invalid input! Make sure your range is between 1000 and 2000." << endl;
			cin >> id;
		}

		ptrEmp[i].setempID(id);

		cout << "Name: ";
		cin.ignore();

		getline(cin, name);

		ptrEmp[i].setempName(name);

		cout << "Salary: ";
		cin >> salary;

		while (salary <= 0)
		{
			cout << "Invalid input! Enter a number greater than 0!" << endl;
			cin >> salary;
		}

		ptrEmp[i].setSalary(salary);

	}

}

//*******************************************************************************************************

void displayAllEmployeeRecord(const Employee * ptrEmp, const int SIZE)
{
	string line(60, '*');
	
	cout << setw(25) << left << "Name" << setw(25) << "Number" << setw(25) << "Salary" << endl;
	cout << line << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(25) << left << ptrEmp[i].getempName() << setw(25) << ptrEmp[i].getempID()
			 << ptrEmp[i].getSalary() << endl;
	}
}

//*******************************************************************************************************

/*
Enter the information for Employee #1:
ID: 999
Invalid input! Make sure your range is between 1000 and 2000.
1000
Name: Celty
Salary: 1500
Enter the information for Employee #2:
ID: 1001
Name: Anri
Salary: 2500
Enter the information for Employee #3:
ID: 1002
Name: Kida
Salary: 3500
Enter the information for Employee #4:
ID: 1003
Name: Simon
Salary: 4500
Enter the information for Employee #5:
ID: 1004
Name: Izaya
Salary: 0
Invalid input! Enter a number greater than 0!
5500
Name                     Number                   Salary
************************************************************
Celty                    1000                     1500
Anri                     1001                     2500
Kida                     1002                     3500
Simon                    1003                     4500
Izaya                    1004                     5500
1004, Izaya has been removed!
1003, Simon has been removed!
1002, Kida has been removed!
1001, Anri has been removed!
1000, Celty has been removed!
Press any key to continue . . .



*/
