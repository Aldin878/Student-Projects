#include <fstream>
#include "Student.h"
#include "DoublyLinkedList.h"

//*******************************************************************************************************

char getChoice();
void buildList(DoublyLL<Student> &);
void process(DoublyLL<Student> &);
void displayStudents(DoublyLL<Student> &);
void countStudents(DoublyLL<Student> &);
void removeStudent(DoublyLL<Student> &);
void findStudent(DoublyLL<Student> &);
void reverseList(DoublyLL<Student> &);

//*******************************************************************************************************

int main()
{
	DoublyLL<Student> list;

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

void buildList(DoublyLL<Student> &list)
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

void process(DoublyLL<Student> &list)
{
	bool success = true;
	char input = 0;

	while (success == true)
	{
		cout << "A. Search for a student." << endl;
		cout << "B. Remove a student." << endl;
		cout << "C. Count the number of students." << endl;
		cout << "D. Display the list." << endl;
		cout << "E. Display the list backwards." << endl;
		cout << "F. Quit" << endl;
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
			reverseList(list);
		}

		else if (input == 'F')
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

void displayStudents(DoublyLL<Student> &list)
{
	list.display();
}

//*******************************************************************************************************


void countStudents(DoublyLL<Student> &list)
{
	cout << "The size of the array is: " << list.getSize() << "." << endl;
}

//*******************************************************************************************************

void removeStudent(DoublyLL<Student> &list)
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

void findStudent(DoublyLL<Student> &list)
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

void reverseList(DoublyLL<Student> &list)
{
	list.displayReverse();
}

//*******************************************************************************************************

/*
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
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
E. Display the list backwards.
F. Quit
Please enter a choice: A
Please enter the ID you'd like to search for: 15755
Found! 15755: VandenVander, Vanessa V HIST 3.74
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
Please enter a choice: B
Please enter the student you'd like to delete: 15755
You've deleted: 15755: VandenVander, Vanessa V HIST 3.74

A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
Please enter a choice: D
9743: Johnson, James L ENGR 3.15
10236: Andrews, Peter J CPSC 2.78
17424: Nakamura, Toky O SOCI 1.95
18264: Lucky, Lucy L HIST 2.29
24237: Euler, Lennie L MATH 3.83
31631: Aristotle, Alice A PHIL 3.1

A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
Please enter a choice: C
The size of the array is: 6.
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
Please enter a choice: E
31631: Aristotle, Alice A PHIL 3.1
24237: Euler, Lennie L MATH 3.83
18264: Lucky, Lucy L HIST 2.29
17424: Nakamura, Toky O SOCI 1.95
10236: Andrews, Peter J CPSC 2.78
9743: Johnson, James L ENGR 3.15
A. Search for a student.
B. Remove a student.
C. Count the number of students.
D. Display the list.
E. Display the list backwards.
F. Quit
Please enter a choice: F
Quitting!
Press any key to continue . . .
*/
