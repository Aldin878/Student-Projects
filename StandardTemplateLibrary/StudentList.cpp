#include "Student.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

//*****************************************************************************************************

char getChoice();
void process(vector<Student> & studentList, vector<Student>::iterator it);
void buildList(vector<Student> & studentList);
void addStudent(vector<Student> & studentList, vector<Student>::iterator position);
void displayStudents(vector<Student> & studentList);
void removeLastStudent(vector<Student> & studentList);
void clearList(vector<Student> & studentList);
void eraseStudent(vector<Student> & studentList, vector<Student>::iterator position);
void resizeList(vector<Student> & studentList);
void sizeOperations(vector<Student> & studentList);
void showCaseAlgorithms(vector <Student> & studentList, vector<Student>::iterator position);

//*****************************************************************************************************

int main()
{
	vector<Student> v1;
	vector<Student> ::iterator it;

	buildList(v1);
	process(v1, it);
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "========MENU========\n"
		<< "A:    Add a new student \n"
		<< "D:    Display the student records \n"
		<< "C:    Clear and rebuild \n"
		<< "E:    Erase student \n"
		<< "R:    Remove last student \n"
		<< "B:    Resize list \n"
		<< "S:    Size operations \n"
		<< "Z:    Showcase Algorithms \n"

		<< "Q:    Quit \n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;

		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'B':
		case 'S':
		case 'E':
		case 'D':
		case 'R':
		case 'C':
		case 'Z':
		case 'Q': valid = true;
			break;
		default:
			valid = false;
			cout << "\aInvalid choice!\n" << "Please try again: ";
			break;
		}
	} while (!valid);

	return choice;
}

//*****************************************************************************************************

void process(vector<Student> & studentList, vector<Student>::iterator it)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(studentList, it);
			break;
		case 'D': displayStudents(studentList);
			break;
		case 'B': resizeList(studentList);
			break;
		case 'R': removeLastStudent(studentList);
			break;
		case 'C': clearList(studentList);
			break;
		case 'E': eraseStudent(studentList, it);
			break;
		case 'S': sizeOperations(studentList);
			break;
		case 'Z': showCaseAlgorithms(studentList, it);
			break;
		case 'Q': 
			break;
		}
	} while (choice != 'Q');

}

//*****************************************************************************************************

void buildList(vector<Student> & studentList)
{
	Student student;
	ifstream studentData;
	studentData.open("smallStudentFile.txt");

	while (studentData >> student.id)
	{
		studentData.ignore();
		studentData.getline(student.name, 50);
		studentData.getline(student.citystate, 50);
		studentData >> student.phone
			>> student.gender
			>> student.year
			>> student.credits
			>> student.gpa
			>> student.major;

		studentList.push_back(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void displayStudents(vector<Student> & studentList)
{
	int size;

	size = studentList.size();

	cout << "Forwards: " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << studentList.at(i) << endl;
	}
	
	cout << "Backwards: " << endl;
	
	for (int i = size - 1; i > -1; i--)
	{
		cout << studentList[i] << endl;
	}

	cout << "The front of the array is: " << studentList.front() << endl
		<< "The back of the array is: " << studentList.back() << endl;
}

//*****************************************************************************************************

void addStudent(vector <Student> & studentList, vector<Student>::iterator position_end)
{
	Student student;
	position_end = studentList.end();

	cout << "Enter the student ID: ";

	cin >> student.id;
	cout << "Enter the student's name:";
	cin.ignore();

	cin.getline(student.name, 50);
	cout << "Enter the student's city and state: ";

	cin.getline(student.citystate, 50);
	cout << "Enter the student's phone: ";

	cin >> student.phone;
	cout << "Enter the student's gender: ";

	cin >> student.gender;
	cout << "Enter the student's year: ";

	cin >> student.year;
	cout << "Enter the student's credits: ";

	cin >> student.credits;
	cout << "Enter the student's gpa: ";

	cin >> student.gpa;
	cin.ignore();
	cout << "Enter the student's major: ";

	cin >> student.major;

	studentList.insert(position_end, student);
	
	cout << "Student successfully added!" << endl;
}

//*****************************************************************************************************

void removeLastStudent(vector<Student> & studentList)
{
	studentList.pop_back();

	cout << "Last student removed!" << endl;
}

//*****************************************************************************************************

void clearList(vector<Student> & studentList)
{
	studentList.clear();

	cout << "List cleared!" << endl
		 << "Now rebuilding the list...." << endl;

	buildList(studentList);
}

//*****************************************************************************************************

void eraseStudent(vector<Student> & studentList, vector<Student>::iterator position_beg)
{
	vector<Student>::iterator position_end;

	position_beg = studentList.begin();

	cout << "Erasing student at index 0... " << endl;

	studentList.erase(position_beg);

	cout << "Gone!" << endl;

	displayStudents(studentList);

	position_beg = studentList.begin();

	position_end = studentList.begin();

	position_end += 3;

	cout << "Now erasing from index 0 and 2..." << endl;

	studentList.erase(position_beg, position_end);

	displayStudents(studentList);

}

//*****************************************************************************************************

void resizeList(vector<Student> & studentList)
{
	int num = 10;

	cout << "Resizing list!" << endl;

	studentList.resize(num);

	displayStudents(studentList);

	cout << "Shrinking the list to fit... " << endl;

	studentList.shrink_to_fit();
}

//*****************************************************************************************************

void sizeOperations(vector<Student> & studentList)
{
	cout << "The capacity is: " << studentList.capacity() << endl
		<< "The size is: " << studentList.size() << endl
		<< "The max size is: " << studentList.max_size() << endl;

	if (studentList.empty())
	{
		cout << "The array is empty!" << endl;
	}
	else
		cout << "The array is not empty!" << endl;

}

//*****************************************************************************************************

void showCaseAlgorithms(vector<Student> & studentList, vector<Student>::iterator pos_beg)
{
	int id;
	vector<Student> ::iterator position;
	vector<Student> ::iterator pos_end;
	
	pos_beg = studentList.begin();
	pos_end = studentList.end();

	cout << "Enter the ID to find: "; 
	cin >> id;

	position = find(pos_beg, pos_end, id);

	if (position != studentList.end())
	{
		cout << *position << " was found!" << endl;
	}
	else
		cout << "Failure! The ID was not found!" << endl;

	position = min_element(pos_beg, pos_end);

	if (position != studentList.end())
	{
		cout << *position << " is the minimum element!" << endl;
	}
	else
		cout << "Failure!" << endl;

	position = max_element(pos_beg, pos_end);

	if (position != studentList.end())
	{
		cout << *position << " is the maximum element!" << endl;
	}
	else
		cout << "Failure!" << endl;

	cout << "Sorting the list.. " << endl;
	sort(pos_beg, pos_end);

	cout << "Using stable sort.. " << endl;
	stable_sort(pos_beg, pos_end);

	displayStudents(studentList);

	cout << "Reversing the list!" << endl;
	reverse(pos_beg, pos_end);
	
	displayStudents(studentList);
}

//*****************************************************************************************************

/*
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: A
Enter the student ID: 1000
Enter the student's name:Aldin Topalbegovic
Enter the student's city and state: St. Louis Missouri
Enter the student's phone: 3145551234
Enter the student's gender: M
Enter the student's year: 4
Enter the student's credits: 37
Enter the student's gpa: 3.75
Enter the student's major: COSC
Student successfully added!
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: D
Forwards:
9743
31631
18264
24237
17424
1000
Backwards:
1000
17424
24237
18264
31631
9743
The front of the array is: 9743
The back of the array is: 1000
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: C
List cleared!
Now rebuilding the list....
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: E
Erasing student at index 0...
Gone!
Forwards:
31631
18264
24237
17424
Backwards:
17424
24237
18264
31631
The front of the array is: 31631
The back of the array is: 17424
Now erasing from index 0 and 2...
Forwards:
17424
Backwards:
17424
The front of the array is: 17424
The back of the array is: 17424
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: S
The capacity is: 6
The size is: 1
The max size is: 30678337
The array is not empty!
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: Z
Enter the ID to find: 9734
Failure! The ID was not found!
17424 is the minimum element!
17424 is the maximum element!
Sorting the list..
Forwards:
17424
Backwards:
17424
The front of the array is: 17424
The back of the array is: 17424
Reversing the list!
Forwards:
17424
Backwards:
17424
The front of the array is: 17424
The back of the array is: 17424
========MENU========
A:    Add a new student
D:    Display the student records
C:    Clear and rebuild
E:    Erase student
F:    Find a student record
R:    Remove last student
B:    Resize list
S:    Size operations
Z:    Showcase Algorithms
Q:    Quit

Enter your choice: Q

Press any key to close this window . . .
*/
