#include "Students.h"

//*******************************************************************************************************

void Students::setStudentNumber(char * s)
{
	strcpy_s(studentNumber, STR_SIZE, s);
}

//*******************************************************************************************************

void Students::setStudentName(char * s)
{
	strcpy_s(studentName, STR_SIZE, s);
}

//*******************************************************************************************************

void Students::setGPA(double grade)
{
	GPA = grade;
}

//*******************************************************************************************************

const char * Students::getStudentName() const 
{
	return studentName;
}

//*******************************************************************************************************

const char * Students::getStudentNumber() const
{
	return studentNumber;
}

//*******************************************************************************************************

double Students::getStudentGPA()
{
	return GPA;
}

//*******************************************************************************************************

void Students::display() const
{
	cout << setw(25) << left << studentName << setw(25) << studentNumber
		<< setw(25) << fixed << setprecision(2) << GPA << endl;
}

//*******************************************************************************************************

Students::~Students()
{
	cout << studentName << " removed!" << endl;
	delete[] studentName;
	delete[] studentNumber;
}

//*******************************************************************************************************
