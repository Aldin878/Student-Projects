#include "BST.h"
#include <fstream>
using namespace std;

//*****************************************************************************************************

char getChoice();
void buildTree(BST<Student> & studentTree);
void process(BST<Student> & studentTree);
void addStudent(BST<Student> & studentTree);
void retrieveStudent(BST<Student> & studentTree);
void updateStudent(BST<Student> & studentTree);
void removeStudent(BST<Student> & studentTree);
void displayStudent(Student & obj);
void printStudent(Student & obj);
void treeInformation(BST<Student> & studentTree);

//*****************************************************************************************************

int main()
{
	BST<Student> studentTree;

	buildTree(studentTree);
	process(studentTree);

	return 0;
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "========MENU========\n"
		<< "A:    Add a new student\n"
		<< "D:    Display the student records\n"
		<< "P:    Print the student records\n"
		<< "R:    Retrieve a student\n"
		<< "U:    Update a student\n"
		<< "B:    Remove a student\n" 
		<< "X:    Tree information\n"
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
		case 'D':
		case 'P':
		case 'R':
		case 'U':
		case 'X':
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

void process(BST<Student> & studentTree)
{
	char choice;
	Student obj;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(studentTree);
			break;
		case 'D': studentTree.inOrderTraverse(displayStudent);
			break;	
		case 'R': retrieveStudent(studentTree);
			break;
		case 'U': updateStudent(studentTree);
			break;
		case 'B': removeStudent(studentTree);
			break;
		case 'P': studentTree.inOrderTraverse(printStudent);
			break;
		case 'X': treeInformation(studentTree);
			break;
		case 'Q':
			break;
		}
	} while (choice != 'Q');

}

//*****************************************************************************************************

void buildTree(BST<Student> & studentTree)
{
	Student student;
	ifstream studentData;

	studentData.open("studentFile.txt");

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

		studentTree.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

void addStudent(BST<Student> & studentTree)
{
	Student student;

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

	studentTree.insert(student);

	cout << "Student successfully added!" << endl;
}

//*****************************************************************************************************

void retrieveStudent(BST<Student> & studentTree)
{
	Student student; 

	cout << "Enter the ID of the student you wish to search for: ";
	cin >> student.id;

	if (studentTree.retrieve(student))
	{
		cout << "Found! " << endl;
		cout << student << endl;
	}
	else
		cout << "Not found. " << endl;
}

//*****************************************************************************************************

void updateStudent(BST<Student> & studentTree)
{
	Student student;

	cout << "Enter the ID of the student you wish to update: ";
	cin >> student.id;

	cout << "Enter the student's new name: ";
	cin >> student.name;

	cout << "Enter the student's new gender: ";
	cin >> student.gender;

	cout << "Enter the student's new major: ";
	cin >> student.major;

	if (studentTree.update(student))
	{
		cout << "Found and updated!" << endl;
	}
	else
		cout << "Failure! Student not found!" << endl;
}

//*****************************************************************************************************

void removeStudent(BST<Student> & studentTree)
{
	Student student;

	cout << "Enter the ID of the student you wish to remove: ";
	cin >> student.id;

	if (studentTree.remove(student))
	{
		cout << "Student " << student.name << " removed!" << endl;
	}
}

//*****************************************************************************************************

void treeInformation(BST<Student> & studentTree)
{
	cout << "Height of tree: " << studentTree.getHt() << endl;
	cout << "Number of nodes: " << studentTree.getCount() << endl;
	cout << "Is the tree empty? " << studentTree.isEmpty() << endl;
	cout << "Is the tree full? " << studentTree.isFull() << endl;
	cout << "Is the tree complete?" << studentTree.isComplete() << endl;
	cout << "Is the tree balanced?" << studentTree.isBalanced() << endl;
}

//*****************************************************************************************************

void displayStudent(Student & obj)
{
	cout << obj;
}

//*****************************************************************************************************

void printStudent(Student & obj)
{
	ofstream file;

	file.open("studentTable.txt", ios::app);

	file << obj;

	file.close();
}

//*****************************************************************************************************
/*
ID:11688 |Name: Kronecker, Leo P |Gender: M |Major: MATH
ID:11749 |Name: Issacson, Jacob A |Gender: M |Major: RELI
ID:11951 |Name: Mouse, Michael E |Gender: M |Major: EDUC
ID:13511 |Name: Pitt, Stew |Gender: M |Major: GNED
ID:14674 |Name: Rockne, Newton K |Gender: M |Major: PE
ID:14815 |Name: Tchaikovsky, Wolfgang A |Gender: M |Major: MUSC
ID:15052 |Name: Einstein, Alfred M |Gender: M |Major: ENGR
ID:15671 |Name: Rembrandt, Roberta E |Gender: F |Major: ART
ID:15755 |Name: VandenVander, Vanessa V |Gender: F |Major: HIST
ID:15802 |Name: Pascal, Blaze R |Gender: M |Major: CPSC
ID:15889 |Name: Gazelle, Gwendolyn D |Gender: F |Major: PE
ID:16183 |Name: Kuts, Cole |Gender: M |Major: FOOD
ID:16540 |Name: Weerd, Dewey L |Gender: M |Major: PHIL
ID:16622 |Name: Issacson, Esau B |Gender: M |Major: RELI
ID:17376 |Name: Scrooge, Ebenezer T |Gender: M |Major: SOCI
ID:17424 |Name: Nakamura, Toky O |Gender: F |Major: SOCI
ID:18213 |Name: Marx, Karl Z |Gender: M |Major: ECON
ID:18264 |Name: Lucky, Lucy L |Gender: F |Major: HIST
ID:19077 |Name: Medes, Archie L |Gender: M |Major: ENGR
ID:19918 |Name: Virus, Vera W |Gender: F |Major: CPSC
ID:20454 |Name: Chicita, Juanita A |Gender: F |Major: BIOL
ID:20991 |Name: Augusta, Ada B |Gender: F |Major: CPSC
ID:21144 |Name: Pasteur, Louise A |Gender: F |Major: BIOL
ID:22277 |Name: Principal, Pamela P |Gender: F |Major: EDUC
ID:22447 |Name: Zylstra, Zelda A |Gender: F |Major: ENGL
ID:23314 |Name: Macdonald, Ronald B |Gender: M |Major: CPSC
ID:23497 |Name: Fault, Paige D |Gender: F |Major: CPSC
ID:23544 |Name: Gestalt, Gloria G |Gender: F |Major: PSYC
ID:23750 |Name: Vespucci, Vera D |Gender: F |Major: GEOG
ID:24237 |Name: Euler, Lennie L |Gender: M |Major: MATH
ID:25377 |Name: Porgy, Bess N |Gender: F |Major: MUSI
ID:25831 |Name: Santamaria, Nina P |Gender: F |Major: HIST
ID:26316 |Name: Custer, General G |Gender: M |Major: HIST
ID:27503 |Name: Fahrenheit, Felicia O |Gender: F |Major: CHEM
ID:28658 |Name: Cicero, Marsha |Gender: F |Major: LATI
ID:29583 |Name: Yewliss, Cal C |Gender: M |Major: MATH
ID:30268 |Name: Newmann, Alfred E |Gender: M |Major: EDUC
ID:30280 |Name: Dewey, Johanna A |Gender: F |Major: EDUC
ID:30381 |Name: Elba, Able M |Gender: M |Major: SPEE
ID:30655 |Name: Angelo, Mike L |Gender: M |Major: ART
ID:30749 |Name: Mendelssohn, Mozart W |Gender: M |Major: MUSC
ID:30878 |Name: Lewis, Clark N |Gender: M |Major: GEOG
ID:31631 |Name: Aristotle, Alice A |Gender: F |Major: PHIL
ID:32598 |Name: Xerxes, Art I |Gender: M |Major: GREE
ID:32631 |Name: Freud, JR, Fred E |Gender: M |Major: PSYC
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: a
Enter the student ID: 32632
Enter the student's name:Aldin
Enter the student's city and state: St. Louis Missouri
Enter the student's phone: 3145551234
Enter the student's gender: M
Enter the student's year: 4
Enter the student's credits: 37
Enter the student's gpa: 3.1
Enter the student's major: COSC
Student successfully added!
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: D
ID:3930 |Name: Leibniz, Gottfried W |Gender: M |Major: MATH
ID:4454 |Name: Atanasoff, Eniac C |Gender: F |Major: CPSC
ID:4559 |Name: Shyster, Samuel D |Gender: M |Major: SOCI
ID:4777 |Name: Gauss, Carl F |Gender: M |Major: MATH
ID:5316 |Name: GotoDijkstra, Edgar G |Gender: M |Major: CPSC
ID:5430 |Name: Nightingale, Florence K |Gender: F |Major: NURS
ID:5710 |Name: Busch, Arch E |Gender: M |Major: ENGR
ID:5873 |Name: Psycho, II,  Prunella E |Gender: F |Major: PSYC
ID:7107 |Name: Shoemaker, Imelda M |Gender: F |Major: POLS
ID:7448 |Name: Roosevelt, Rose Y |Gender: F |Major: POLS
ID:7844 |Name: Aardvark, Anthony A |Gender: M |Major: ENGR
ID:7885 |Name: Fibonacci, Leonard O |Gender: M |Major: MATH
ID:9463 |Name: Hochschule, Hortense C |Gender: F |Major: EDUC
ID:9743 |Name: Johnson, James L |Gender: M |Major: ENGR
ID:10236 |Name: Andrews, Peter J |Gender: M |Major: CPSC
ID:10304 |Name: Deutsch, Sprechen Z |Gender: F |Major: GERM
ID:11688 |Name: Kronecker, Leo P |Gender: M |Major: MATH
ID:11749 |Name: Issacson, Jacob A |Gender: M |Major: RELI
ID:11951 |Name: Mouse, Michael E |Gender: M |Major: EDUC
ID:13511 |Name: Pitt, Stew |Gender: M |Major: GNED
ID:14674 |Name: Rockne, Newton K |Gender: M |Major: PE
ID:14815 |Name: Tchaikovsky, Wolfgang A |Gender: M |Major: MUSC
ID:15052 |Name: Einstein, Alfred M |Gender: M |Major: ENGR
ID:15671 |Name: Rembrandt, Roberta E |Gender: F |Major: ART
ID:15755 |Name: VandenVander, Vanessa V |Gender: F |Major: HIST
ID:15802 |Name: Pascal, Blaze R |Gender: M |Major: CPSC
ID:15889 |Name: Gazelle, Gwendolyn D |Gender: F |Major: PE
ID:16183 |Name: Kuts, Cole |Gender: M |Major: FOOD
ID:16540 |Name: Weerd, Dewey L |Gender: M |Major: PHIL
ID:16622 |Name: Issacson, Esau B |Gender: M |Major: RELI
ID:17376 |Name: Scrooge, Ebenezer T |Gender: M |Major: SOCI
ID:17424 |Name: Nakamura, Toky O |Gender: F |Major: SOCI
ID:18213 |Name: Marx, Karl Z |Gender: M |Major: ECON
ID:18264 |Name: Lucky, Lucy L |Gender: F |Major: HIST
ID:19077 |Name: Medes, Archie L |Gender: M |Major: ENGR
ID:19918 |Name: Virus, Vera W |Gender: F |Major: CPSC
ID:20454 |Name: Chicita, Juanita A |Gender: F |Major: BIOL
ID:20991 |Name: Augusta, Ada B |Gender: F |Major: CPSC
ID:21144 |Name: Pasteur, Louise A |Gender: F |Major: BIOL
ID:22277 |Name: Principal, Pamela P |Gender: F |Major: EDUC
ID:22447 |Name: Zylstra, Zelda A |Gender: F |Major: ENGL
ID:23314 |Name: Macdonald, Ronald B |Gender: M |Major: CPSC
ID:23497 |Name: Fault, Paige D |Gender: F |Major: CPSC
ID:23544 |Name: Gestalt, Gloria G |Gender: F |Major: PSYC
ID:23750 |Name: Vespucci, Vera D |Gender: F |Major: GEOG
ID:24237 |Name: Euler, Lennie L |Gender: M |Major: MATH
ID:25377 |Name: Porgy, Bess N |Gender: F |Major: MUSI
ID:25831 |Name: Santamaria, Nina P |Gender: F |Major: HIST
ID:26316 |Name: Custer, General G |Gender: M |Major: HIST
ID:27503 |Name: Fahrenheit, Felicia O |Gender: F |Major: CHEM
ID:28658 |Name: Cicero, Marsha |Gender: F |Major: LATI
ID:29583 |Name: Yewliss, Cal C |Gender: M |Major: MATH
ID:30268 |Name: Newmann, Alfred E |Gender: M |Major: EDUC
ID:30280 |Name: Dewey, Johanna A |Gender: F |Major: EDUC
ID:30381 |Name: Elba, Able M |Gender: M |Major: SPEE
ID:30655 |Name: Angelo, Mike L |Gender: M |Major: ART
ID:30749 |Name: Mendelssohn, Mozart W |Gender: M |Major: MUSC
ID:30878 |Name: Lewis, Clark N |Gender: M |Major: GEOG
ID:31631 |Name: Aristotle, Alice A |Gender: F |Major: PHIL
ID:32598 |Name: Xerxes, Art I |Gender: M |Major: GREE
ID:32631 |Name: Freud, JR, Fred E |Gender: M |Major: PSYC
ID:32632 |Name: Aldin |Gender: M |Major: COSC
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: P
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: r
Enter the ID of the student you wish to search for: 32632
Found!
ID:32632 |Name: Aldin |Gender: M |Major: COSC

========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: U
Enter the ID of the student you wish to update: 32632
Enter the student's new name: Aldin T
Enter the student's new gender: F
Enter the student's new major: COSC
Found and updated!
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: D
ID:3930 |Name: Leibniz, Gottfried W |Gender: M |Major: MATH
ID:4454 |Name: Atanasoff, Eniac C |Gender: F |Major: CPSC
ID:4559 |Name: Shyster, Samuel D |Gender: M |Major: SOCI
ID:4777 |Name: Gauss, Carl F |Gender: M |Major: MATH
ID:5316 |Name: GotoDijkstra, Edgar G |Gender: M |Major: CPSC
ID:5430 |Name: Nightingale, Florence K |Gender: F |Major: NURS
ID:5710 |Name: Busch, Arch E |Gender: M |Major: ENGR
ID:5873 |Name: Psycho, II,  Prunella E |Gender: F |Major: PSYC
ID:7107 |Name: Shoemaker, Imelda M |Gender: F |Major: POLS
ID:7448 |Name: Roosevelt, Rose Y |Gender: F |Major: POLS
ID:7844 |Name: Aardvark, Anthony A |Gender: M |Major: ENGR
ID:7885 |Name: Fibonacci, Leonard O |Gender: M |Major: MATH
ID:9463 |Name: Hochschule, Hortense C |Gender: F |Major: EDUC
ID:9743 |Name: Johnson, James L |Gender: M |Major: ENGR
ID:10236 |Name: Andrews, Peter J |Gender: M |Major: CPSC
ID:10304 |Name: Deutsch, Sprechen Z |Gender: F |Major: GERM
ID:11688 |Name: Kronecker, Leo P |Gender: M |Major: MATH
ID:11749 |Name: Issacson, Jacob A |Gender: M |Major: RELI
ID:11951 |Name: Mouse, Michael E |Gender: M |Major: EDUC
ID:13511 |Name: Pitt, Stew |Gender: M |Major: GNED
ID:14674 |Name: Rockne, Newton K |Gender: M |Major: PE
ID:14815 |Name: Tchaikovsky, Wolfgang A |Gender: M |Major: MUSC
ID:15052 |Name: Einstein, Alfred M |Gender: M |Major: ENGR
ID:15671 |Name: Rembrandt, Roberta E |Gender: F |Major: ART
ID:15755 |Name: VandenVander, Vanessa V |Gender: F |Major: HIST
ID:15802 |Name: Pascal, Blaze R |Gender: M |Major: CPSC
ID:15889 |Name: Gazelle, Gwendolyn D |Gender: F |Major: PE
ID:16183 |Name: Kuts, Cole |Gender: M |Major: FOOD
ID:16540 |Name: Weerd, Dewey L |Gender: M |Major: PHIL
ID:16622 |Name: Issacson, Esau B |Gender: M |Major: RELI
ID:17376 |Name: Scrooge, Ebenezer T |Gender: M |Major: SOCI
ID:17424 |Name: Nakamura, Toky O |Gender: F |Major: SOCI
ID:18213 |Name: Marx, Karl Z |Gender: M |Major: ECON
ID:18264 |Name: Lucky, Lucy L |Gender: F |Major: HIST
ID:19077 |Name: Medes, Archie L |Gender: M |Major: ENGR
ID:19918 |Name: Virus, Vera W |Gender: F |Major: CPSC
ID:20454 |Name: Chicita, Juanita A |Gender: F |Major: BIOL
ID:20991 |Name: Augusta, Ada B |Gender: F |Major: CPSC
ID:21144 |Name: Pasteur, Louise A |Gender: F |Major: BIOL
ID:22277 |Name: Principal, Pamela P |Gender: F |Major: EDUC
ID:22447 |Name: Zylstra, Zelda A |Gender: F |Major: ENGL
ID:23314 |Name: Macdonald, Ronald B |Gender: M |Major: CPSC
ID:23497 |Name: Fault, Paige D |Gender: F |Major: CPSC
ID:23544 |Name: Gestalt, Gloria G |Gender: F |Major: PSYC
ID:23750 |Name: Vespucci, Vera D |Gender: F |Major: GEOG
ID:24237 |Name: Euler, Lennie L |Gender: M |Major: MATH
ID:25377 |Name: Porgy, Bess N |Gender: F |Major: MUSI
ID:25831 |Name: Santamaria, Nina P |Gender: F |Major: HIST
ID:26316 |Name: Custer, General G |Gender: M |Major: HIST
ID:27503 |Name: Fahrenheit, Felicia O |Gender: F |Major: CHEM
ID:28658 |Name: Cicero, Marsha |Gender: F |Major: LATI
ID:29583 |Name: Yewliss, Cal C |Gender: M |Major: MATH
ID:30268 |Name: Newmann, Alfred E |Gender: M |Major: EDUC
ID:30280 |Name: Dewey, Johanna A |Gender: F |Major: EDUC
ID:30381 |Name: Elba, Able M |Gender: M |Major: SPEE
ID:30655 |Name: Angelo, Mike L |Gender: M |Major: ART
ID:30749 |Name: Mendelssohn, Mozart W |Gender: M |Major: MUSC
ID:30878 |Name: Lewis, Clark N |Gender: M |Major: GEOG
ID:31631 |Name: Aristotle, Alice A |Gender: F |Major: PHIL
ID:32598 |Name: Xerxes, Art I |Gender: M |Major: GREE
ID:32631 |Name: Freud, JR, Fred E |Gender: M |Major: PSYC
ID:32632 |Name: Aldin |Gender: F |Major: COSC
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice:
b
Enter the ID of the student you wish to remove: 32632
Student Aldin removed!
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: x
Height of tree: 13
Number of nodes: 61
Is the tree empty? 0
Is the tree full? 0
Is the tree complete?0
Is the tree balanced?0
========MENU========
A:    Add a new student
D:    Display the student records
P:    Print the student records
R:    Retrieve a student
U:    Update a student
B:    Remove a student
X:    Tree information
Q:    Quit

Enter your choice: q

C:\Users\Aldin\Documents\Visual Studio 2017\Projects\Project149\Debug\Project149.exe (process 25656) exited with code 0.
Press any key to close this window . . .

*/

