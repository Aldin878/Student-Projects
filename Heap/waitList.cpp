#include "heap.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
using namespace std;

//*****************************************************************************************************

void getData(Heap<Customer> & waitList);
void printWaitList(Heap<Customer> & waitList);

//*****************************************************************************************************

int main()
{
	Heap<Customer> waitlist;
	getData(waitlist);
	printWaitList(waitlist);

	return 0;
}

//*****************************************************************************************************

void getData(Heap<Customer> & waitList)
{
	Customer cust;
	ifstream(inFile);
	inFile.open("overbooked.bin", ios::binary);

	while (inFile.read((char *)& cust, sizeof(cust)))
	{
		cust.priority = ((cust.mileage / 1000) + (cust.years - cust.arrivalNum));
		waitList.insert(cust);
	}

	inFile.close();
}

//*****************************************************************************************************

void printWaitList(Heap<Customer> & waitList)
{
	Customer customer;
	ofstream outFile("waitlist.txt");


	outFile << "The higher the priority the better!" 
			<< " Seat customers in order of their priority number. " << endl;

	while (waitList.remove(customer))
	{
		outFile << customer << endl << endl;
	}
}

//*****************************************************************************************************

/*
The higher the priority the better! Seat customers in order of their priority number.
Name: Baclan Nguyen
Mileage: 93000
Frequent flier years: 3
Arrival number: 3
Calculated priority: 93

Name: Amanda Trapp
Mileage: 89000
Frequent flier years: 3
Arrival number: 2
Calculated priority: 90

Name: Warren Rexroad
Mileage: 72000
Frequent flier years: 7
Arrival number: 5
Calculated priority: 74

Name: Jorge Gonzales
Mileage: 65000
Frequent flier years: 2
Arrival number: 6
Calculated priority: 61

Name: Bryan Devaux
Mileage: 53000
Frequent flier years: 5
Arrival number: 1
Calculated priority: 57

Name: Dave Lightfoot
Mileage: 63000
Frequent flier years: 3
Arrival number: 10
Calculated priority: 56

Name: Steve Chu
Mileage: 42000
Frequent flier years: 4
Arrival number: 9
Calculated priority: 37

Name: Paula Hung
Mileage: 34000
Frequent flier years: 3
Arrival number: 7
Calculated priority: 30

Name: Joanne Brown
Mileage: 33000
Frequent flier years: 2
Arrival number: 11
Calculated priority: 24

Name: Lou Mason
Mileage: 21000
Frequent flier years: 6
Arrival number: 8
Calculated priority: 19

Name: Sarah Gilley
Mileage: 17000
Frequent flier years: 1
Arrival number: 4
Calculated priority: 14
*/
