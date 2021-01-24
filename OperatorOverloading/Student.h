#ifndef STUDENT_H
#define STUDENT_H

//*******************************************************************************************************

#include <iostream>
using namespace std;

//*******************************************************************************************************

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

	friend istream &operator >> (istream &, Student &);
	friend ostream &operator << (ostream &, Student &);
	void operator = (const Student &);
	bool operator > (const Student &);
	bool operator < (const Student &);
	bool operator == (const Student &);
	bool operator != (const Student &);
	bool operator <= (const Student &);
	bool operator >= (const Student &);
};

//*******************************************************************************************************

istream &operator >> (istream &strm, Student &obj)
{
	strm >> obj.id;

	strm.ignore();

	strm.getline(obj.name, 50, '\n');

	strm.getline(obj.citystate, 50, '\n');

	strm >> obj.phone;

	strm >> obj.gender;

	strm >> obj.year;

	strm >> obj.credits;

	strm >> obj.gpa;

	strm >> obj.major;

	strm.ignore();

	return strm;
}

//*******************************************************************************************************

ostream &operator << (ostream &strm, Student &obj)
{
	strm << obj.id << ": " << obj.name << " " << obj.major << " " << obj.gpa << endl;

	return strm;
}

//*******************************************************************************************************

void Student::operator = (const Student &right)
{
	id = right.id;

	strcpy_s(name, 50, right.name);

	strcpy_s(citystate, 50, right.citystate);

	strcpy_s(phone, 12, right.phone);

	gender = right.gender;

	year = right.year;

	credits = right.credits;

	gpa = right.gpa;

	strcpy_s(major, 6, right.major);
}

//*******************************************************************************************************

bool Student::operator > (const Student &right)
{
	bool success = false;

	if (id > right.id)
	{
		success = true;
	}

	else if (id == right.id)
	{
		success = false;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

bool Student::operator < (const Student &right)
{
	bool success = false;

	if (id < right.id)
	{
		success = true;
	}

	else if (id == right.id)
	{
		success = false;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

bool Student::operator == (const Student &right)
{
	bool success = false;

	if (id == right.id)
	{
		success = true;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

bool Student::operator != (const Student & right)
{
	bool success = false;

	if (id != right.id)
	{
		success = true;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

bool Student::operator <= (const Student & right)
{
	bool success = false;

	if (id <= right.id)
	{
		success = true;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

bool Student::operator >= (const Student & right)
{
	bool success = false;

	if (id >= right.id)
	{
		success = true;
	}

	else
		success = false;

	return success;
}

//*******************************************************************************************************

#endif
