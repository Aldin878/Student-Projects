#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;

//*******************************************************************************************************

class Employee
{
private:
	int empID;
	string empName;
	double salary;
public:
	Employee();
	~Employee();
	void setempID(int);
	void setempName(string);
	void setSalary(double);
	string getempName() const;
	int getempID() const;
	double getSalary() const;
};

#endif

//*******************************************************************************************************
