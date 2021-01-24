#ifndef STUDENTS_H
#define STUDENTS_H
#include <cstring>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int STR_SIZE = 51;

//*******************************************************************************************************

class Students
{
	private:
		char *studentNumber;
		char *studentName;
		double GPA;
	public:
		Students(char name[STR_SIZE] = "*none*", char number[STR_SIZE] = "00000",
			double defGPA = 0.00)
		{
			studentNumber = new char[STR_SIZE];
			studentName = new char[STR_SIZE];
			strcpy_s(studentName, STR_SIZE, name);
			strcpy_s(studentNumber, STR_SIZE, number);
			GPA = defGPA;
		}

		~Students();

		void setStudentNumber(char *);
		void setStudentName(char *);
		void setGPA(double);

		const char * getStudentName() const;
		const char * getStudentNumber() const;
		
		double getStudentGPA();
		void display() const;
};

#endif

//*******************************************************************************************************
