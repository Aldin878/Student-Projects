#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
using namespace std;

//*****************************************************************************************************

struct Student
{
	int id;
	char name[50];
	char citystate[50];
	char phone[12];
	char gender;
	int year;
	int credits;
	float gpa;
	char major[6];

	Student();
	friend ostream & operator << (ostream & out, const Student & data);
	bool operator == (const Student & rhs) const;
	bool operator == (int value) const;
	Student & operator = (int value);
	bool operator != (const Student & rhs) const;
	bool operator != (int value) const;
	bool operator < (const Student & rhs) const;
	bool operator < (int value) const;
	bool operator > (const Student & rhs) const;
	bool operator > (int value) const;
	bool operator <= (const Student & rhs) const;
	bool operator <= (int value) const;
	bool operator >= (const Student & rhs) const;
	bool operator >= (int value) const;
	int operator % (int value) const;
};

//*****************************************************************************************************

Student::Student()
{
	id = 0;
}

//*****************************************************************************************************

ostream & operator << (ostream & out, const Student & data)
{
	out << data.id;

	return out;
}

//*****************************************************************************************************

bool Student :: operator == (const Student & rhs) const
{
	return (this->id == rhs.id);
}

//*****************************************************************************************************

bool Student :: operator == (int value) const
{
	return (this->id == value);
}

//*****************************************************************************************************

Student & Student :: operator = (int value)
{
	this->id = value;
	return *this;
}

//*****************************************************************************************************

bool Student :: operator != (const Student & rhs) const
{
	return (this->id != rhs.id);
}

//*****************************************************************************************************

int Student :: operator % (int value) const
{
	return (this->id % value);
}

//*****************************************************************************************************

bool Student :: operator != (int value) const
{
	return (this->id != value);
}

//*****************************************************************************************************

bool Student :: operator < (const Student & rhs) const
{
	return (this->id < rhs.id);
}

//*****************************************************************************************************

bool Student :: operator < (int value) const
{
	return (this->id < value);
}

//*****************************************************************************************************

bool Student :: operator > (const Student & rhs) const
{
	return (this->id > rhs.id);
}

//*****************************************************************************************************

bool Student :: operator > (int value) const
{
	return (this->id > value);
}

//*****************************************************************************************************

bool Student :: operator <= (const Student & rhs) const
{
	return (this->id <= rhs.id);
}

//*****************************************************************************************************

bool Student :: operator <= (int value) const
{
	return (this->id <= value);
}

//*****************************************************************************************************

bool Student :: operator >= (const Student & rhs) const
{
	return (this->id >= rhs.id);
}

//*****************************************************************************************************

bool Student :: operator >= (int value) const
{
	return (this->id >= value);
}

//*****************************************************************************************************

#endif
