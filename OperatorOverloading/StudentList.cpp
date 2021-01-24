#include <fstream>
#include "Student.h"
#include "LinkedList.h"

//*******************************************************************************************************

char getChoice();
void buildList(LinkedList<Student> &);
void process(LinkedList<Student> &);
void displayStudents(LinkedList<Student> &);
void countStudents(LinkedList<Student> &);
void removeStudent(LinkedList<Student> &);
void findStudent(LinkedList<Student> &);

//*******************************************************************************************************

int main()
{
	LinkedList<Student> list;

	buildList(list);
	process(list);

	return 0;
}

//*******************************************************************************************************


char getChoice()
{
	char input; 
	
	cout << "Please enter a choice: ";
	cin >> input;

	return input;
}

//*******************************************************************************************************

void buildList(LinkedList<Student> &list)
{
	Student obj;
	fstream obj2;

	obj2.open("studentFile_short.txt", ios::in);

	if (!obj2)
	{
		cout << "File not found!" << endl;
	}

	else
	{
		while (!obj2.eof())
		{
			obj2 >> obj;
			list.insert(obj);
		}

		obj2.close();
	}
}

//*******************************************************************************************************

void process(LinkedList<Student> &list)
{
	bool success = true;
	char input = 0;

	while (success == true)
	{
		cout << "A. Search for a student." << endl;
		cout << "B. Remove a student." << endl;
		cout << "C. Count the number of students." << endl;
		cout << "D. Display the list." << endl;
		cout << "E. Quit" << endl;
		input = getChoice();

		if (input == 'A')
		{
			findStudent(list);
		}

		else if (input == 'B')
		{
			removeStudent(list);
		}

		else if (input == 'C')
		{
			countStudents(list);
		}

		else if (input == 'D')
		{
			displayStudents(list);
		}

		else if (input == 'E')
		{
			cout << "Quitting!" << endl;
			success = false;
		}

		else
		{
			cout << "Please enter a valid choice!" << endl;
			input = getChoice();
		}
		
	}

}

//*******************************************************************************************************

void displayStudents(LinkedList<Student> &list)
{
	list.display();
}

//*******************************************************************************************************


void countStudents(LinkedList<Student> &list)
{

	if (!list.getSize())
	{
		cout << "getSize isnt working!" << endl;
	}

	cout << "The size of the array is: " << list.getSize() << "." << endl;
}

//*******************************************************************************************************

void removeStudent(LinkedList<Student> &list)
{
	Student obj;

	cout << "Please enter the student you'd like to delete: ";
	cin >> obj.id;

	while (!list.remove(obj))
	{
		cout << "Could not find ID! Please try again: " << endl;
		cin >> obj.id;
	}

	cout << "You've deleted: " << obj << endl;
}

//*******************************************************************************************************

void findStudent(LinkedList<Student> &list)
{
	Student obj;

	cout << "Please enter the ID you'd like to search for: ";

	cin >> obj.id;

	while (!list.retrieve(obj))
	{
		cout << "Could not find ID! Please try again: " << endl;
		cin >> obj.id;
	}

	cout << "Found! " << obj;
}

//*******************************************************************************************************
/*
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: D
9743: Johnson, James L ENGR 3.15
 10236: Andrews, Peter J CPSC 2.78
 15755: VandenVander, Vanessa V HIST 3.74
 17424: Nakamura, Toky O SOCI 1.95
 18264: Lucky, Lucy L HIST 2.29
 24237: Euler, Lennie L MATH 3.83
 31631: Aristotle, Alice A PHIL 3.1

A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: A
Please enter the ID you'd like to search for: 10236
Found! 10236: Andrews, Peter J CPSC 2.78
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: B
Please enter the student you'd like to delete: 10236
You've deleted: 10236: Andrews, Peter J CPSC 2.78

A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: D
9743: Johnson, James L ENGR 3.15
 15755: VandenVander, Vanessa V HIST 3.74
 17424: Nakamura, Toky O SOCI 1.95
 18264: Lucky, Lucy L HIST 2.29
 24237: Euler, Lennie L MATH 3.83
 31631: Aristotle, Alice A PHIL 3.1

A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: C
The size of the array is: 6.
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Quit
Please enter a choice: E
Quitting!
Press any key to close this window . . .

*/
