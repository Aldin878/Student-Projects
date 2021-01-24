#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//****************************************************************************************************

struct Student
{
	string name;
	int ID;
	double grade;
};

//****************************************************************************************************

struct Course
{
	string courseName;
	int numOfStudents;
	Student *ptrStudent;
	double averageGrades;
};

//****************************************************************************************************

void getScores(Course&);
void calculateAverage(Course&); 
void displayInfo(Course&);
void freeMemory(Course&);

//****************************************************************************************************

int main()
{
	Course aCourse;

	getScores(aCourse);
	displayInfo(aCourse);
	freeMemory(aCourse);
	return 0;
}

//****************************************************************************************************

void getScores(Course &aCourse)
{
	cout << "Enter the name of the course: ";
    getline(cin, aCourse.courseName);
	cout << "Enter how many students are in your course: ";
	cin >> aCourse.numOfStudents;

	aCourse.ptrStudent = new Student[aCourse.numOfStudents];

	for (int i = 0; i < aCourse.numOfStudents; i++)
	{
		cout << "Enter student #" << i + 1 << "'s name: ";
		cin.ignore();
		getline(cin, aCourse.ptrStudent[i].name);
		cout << "Enter this student's ID: ";
		cin >> aCourse.ptrStudent[i].ID;
		cout << "Enter this student's grade: ";
		cin >> aCourse.ptrStudent[i].grade;
	}

	calculateAverage(aCourse);
}

//****************************************************************************************************

void calculateAverage(Course &aCourse)
{
	double sum = 0;

	for (int i = 0; i < aCourse.numOfStudents; i++)
	{
		sum += aCourse.ptrStudent[i].grade;
	}

	aCourse.averageGrades = sum / aCourse.numOfStudents;

}

//****************************************************************************************************

void displayInfo(Course &aCourse)
{
	string line(50, '*');

	cout << line << endl;
	cout << aCourse.courseName << endl;

	for (int i = 0; i < aCourse.numOfStudents; i++)
	{
		cout << setw(25) << left << aCourse.ptrStudent[i].name
		     << setw(10) << left << aCourse.ptrStudent[i].ID
		     << setw(10) << left << aCourse.ptrStudent[i].grade << endl;
	}

	cout << line << endl;
	cout << "The average is: " << setprecision(2) << aCourse.averageGrades << endl;
}

//****************************************************************************************************

void freeMemory(Course &aCourse)
{
	delete[] aCourse.ptrStudent;
}
//****************************************************************************************************

/*
Enter the name of the course: Programming II
Enter how many students are in your course: 5
Enter student #1's name: Aldin
Enter this student's ID: 1
Enter this student's grade: 91
Enter student #2's name: Kenshin
Enter this student's ID: 2
Enter this student's grade: 95
Enter student #3's name: Steven
Enter this student's ID: 3
Enter this student's grade: 99
Enter student #4's name: Sanuosuke
Enter this student's ID: 4
Enter this student's grade: 65
Enter student #5's name: Jack
Enter this student's ID: 5
Enter this student's grade: 100
**************************************************
Programming II
Aldin                    1         91
Kenshin                  2         95
Steven                   3         99
Sanuosuke                4         65
Jack                     5         100
**************************************************
The average is: 90
Press any key to continue . . .
*/
