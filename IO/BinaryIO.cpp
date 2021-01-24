#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//****************************************************************************************************

struct Customer
{
	char name[51];
	char address[51];
	double accountBalance;
	int id;
};

//****************************************************************************************************

int getChoice();
void handleMenu();
void addRecord();
void displayOneCustomer();
int countRecord();
void displayAllCustomer();
void customerInfo(Customer);
void checkRecord();

//****************************************************************************************************

int main()
{
	fstream file("record.dat", ios::binary | ios::in);

	if (!file.fail())
	{
		handleMenu();
		file.close();
	}

	else
	{
		cout << "File not found!" << endl;
	}

	return 0;
}

//****************************************************************************************************

void handleMenu()
{
	const int MENU_CHOICE_ONE = 1,
		MENU_CHOICE_TWO = 2,
		MENU_CHOICE_THREE = 3,
		MENU_CHOICE_FOUR = 4,
		MENU_CHOICE_FIVE = 5;
	int choice = 0;
	string line(50, '*');

	while (choice != MENU_CHOICE_FIVE)
	{
		int count = countRecord();

		cout << line << endl;
		cout << "1) Enter a new record" << endl;
		cout << "2) Search for a record" << endl;
		cout << "3) Count the number of records" << endl;
		cout << "4) Display all records" << endl;
		cout << "5) Quit" << endl;
		cout << line << endl;

		choice = getChoice();

		if (choice == MENU_CHOICE_ONE)
		{
			addRecord();
		}

		else if (choice == MENU_CHOICE_TWO)
		{
			checkRecord();
			displayOneCustomer();
		}

		else if (choice == MENU_CHOICE_THREE)
		{
			checkRecord();
			cout << "There are " << count << " records in the file." << endl;
		}

		else if (choice == MENU_CHOICE_FOUR)
		{
			checkRecord();
			displayAllCustomer();
		}

		else if (choice == MENU_CHOICE_FIVE)
		{
			cout << "Terminating!" << endl;
		}

	}
}

//****************************************************************************************************

int getChoice()
{
	int choice;

	cout << "Enter your choice: ";
	cin >> choice;

	return choice;
}

//****************************************************************************************************

void addRecord()
{
	const int LENGTH = 50;
	Customer info;
	fstream file("record.dat", ios::out | ios::app | ios::binary);

	cin.ignore();
	cout << "Enter a name: ";
	cin.getline(info.name, LENGTH);

	cout << "Enter an address: ";
	cin.getline(info.address, LENGTH);

	cout << "Enter the account balance: ";
	cin >> info.accountBalance;

	cout << "Enter the ID: ";
	cin >> info.id;

	file.write(reinterpret_cast<char *>(&info), sizeof(info));

	file.close();
}

//****************************************************************************************************

int countRecord()
{
	Customer info;
	fstream file("record.dat", ios::in | ios::binary);
	int size = 0;

	file.seekg(0L, ios::end);
	size = file.tellg();

	file.close();

	return size / sizeof(info);
}

//****************************************************************************************************

void displayOneCustomer()
{
	Customer info;
	fstream file("record.dat", ios::in | ios::binary);
	int input = 0,
		byte = 0,
		count = countRecord() - 1;

	cout << "Enter the record number you wish to see: ";
	cin >> input;

	while (input > count)
	{
		cout << "No records exist beyond: " << count << "! Reenter an appropriate number: " << endl;
		cin >> input;
	}

	byte = input * sizeof(info);

	file.seekg(byte, ios::beg);

	file.read(reinterpret_cast<char *>(&info), sizeof(info));

	customerInfo(info);

	file.close();
}

//****************************************************************************************************

void displayAllCustomer()
{
	Customer info;
	fstream file("record.dat", ios::in | ios::binary);

	file.read(reinterpret_cast<char *>(&info), sizeof(info));

	while (!file.eof())
	{
		customerInfo(info);
		file.read(reinterpret_cast<char *>(&info), sizeof(info));
	}

	file.close();
}

//****************************************************************************************************

void customerInfo(Customer info)
{
	cout << "Name: ";
	cout << info.name << endl;
	cout << "Address: ";
	cout << info.address << endl;
	cout << "Account Balance: ";
	cout << info.accountBalance << endl;
	cout << "ID: ";
	cout << info.id << endl;
}

void checkRecord()
{
	while (countRecord() == 0)
	{
		cout << "No records found! Please enter a record before proceeding." << endl;
		addRecord();
	}
}

//****************************************************************************************************

/*
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 2
No records found! Please enter a record before proceeding.
Enter a name: Carlos Carne
Enter an address: 123 Webster Street
Enter the account balance: 4079
Enter the ID: 1
Enter the record number you wish to see: 1
No records exist beyond: 0! Reenter an appropriate number:
0
Name: Carlos Carne
Address: 123 Webster Street
Account Balance: 4079
ID: 1
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 1
Enter a name: Shizuo Heiwajima
Enter an address: 4056 Ikebukuro Drive
Enter the account balance: 15023
Enter the ID: 2
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 3
There are 2 records in the file.
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 4
Name: Carlos Carne
Address: 123 Webster Street
Account Balance: 4079
ID: 1
Name: Shizuo Heiwajima
Address: 4056 Ikebukuro Drive
Account Balance: 15023
ID: 2
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 1
Enter a name: Kari Whalgreen
Enter an address: 750 Whalb Street
Enter the account balance: 1000
Enter the ID: 3
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 3
There are 3 records in the file.
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 4
Name: Carlos Carne
Address: 123 Webster Street
Account Balance: 4079
ID: 1
Name: Shizuo Heiwajima
Address: 4056 Ikebukuro Drive
Account Balance: 15023
ID: 2
Name: Kari Whalgreen
Address: 750 Whalb Street
Account Balance: 1000
ID: 3
**************************************************
1) Enter a new record
2) Search for a record
3) Count the number of records
4) Display all records
5) Quit
**************************************************
Enter your choice: 5
Terminating!
Press any key to continue . . .
*/
