#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;

//*****************************************************************************************************

struct Customer
{
	char fname[15];
	char lname[15];
	int mileage;
	int years;
	int arrivalNum;
	int priority;

	Customer();

	friend ostream & operator << (ostream & out, const Customer & data);
	bool operator == (const Customer & rhs) const;
	bool operator == (int value) const;
	Customer & operator = (int value);
	bool operator != (const Customer & rhs) const;
	bool operator != (int value) const;
	bool operator < (const Customer & rhs) const;
	bool operator < (int value) const;
	bool operator > (const Customer & rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Customer & rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Customer & rhs) const;
	bool operator >= (int value) const;
};

//*****************************************************************************************************

Customer::Customer()
{
	priority = 0;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Customer & data)
{
	out << "Name: " << data.fname << " " << data.lname << endl;
	out << "Mileage: " << data.mileage << endl;
	out << "Frequent flier years: " << data.years << endl;
	out << "Arrival number: " << data.arrivalNum << endl;
	out << "Calculated priority: " << data.priority;


	return out;
}

//*****************************************************************************************************

bool Customer :: operator == (const Customer & rhs) const
{
	return (this->priority == rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator == (int value) const
{
	return (this->priority == value);
}

//*****************************************************************************************************

Customer & Customer :: operator = (int value)
{
	this->priority = value;
	return *this;
}

//*****************************************************************************************************

bool Customer :: operator != (const Customer & rhs) const
{
	return (this->priority != rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator != (int value) const
{
	return (this->priority != value);
}

//*****************************************************************************************************

bool Customer :: operator < (const Customer & rhs) const
{
	return (this->priority < rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator < (int value) const
{
	return (this->priority < value);
}

//*****************************************************************************************************

bool Customer :: operator > (const Customer & rhs) const
{
	return (this->priority > rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator > (int value) const
{
	return (this->priority > value);
}

//*****************************************************************************************************

bool Customer :: operator <= (const Customer & rhs) const
{
	return (this->priority <= rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator <= (int value) const
{
	return (this->priority <= value);
}

//*****************************************************************************************************

bool Customer :: operator >= (const Customer & rhs) const
{
	return (this->priority >= rhs.priority);
}

//*****************************************************************************************************

bool Customer :: operator >= (int value) const
{
	return (this->priority >= value);
}

//*****************************************************************************************************

#endif
