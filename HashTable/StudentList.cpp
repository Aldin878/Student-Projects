#include "Node.h"
#include "HashTable.h"
#include "Student.h"

//*****************************************************************************************************

void process(HashTable <Student> &);
char getChoice();
void buildList(HashTable<Student> &);
void displayStudents(HashTable<Student> &);
void printStudents(HashTable<Student> &);
void addStudent(HashTable<Student> &);
void findStudent(HashTable<Student> &);
void removeStudent(HashTable<Student> &);
void displayStatistics(HashTable<Student> &);

//*****************************************************************************************************

int main()
{
	HashTable<Student> studentList(61);

	buildList(studentList);
	process(studentList);

	return 0;
}

//*****************************************************************************************************

void buildList(HashTable<Student> & studentList)
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

		studentList.insert(student);
	}

	studentData.close();
}

//*****************************************************************************************************

char getChoice()
{
	char choice;
	bool valid;

	cout << "========MENU========\n"
		<< "A:    Add a new student \n"
		<< "D:    Display the student records \n"
		<< "F:    Find a student record \n"
		<< "R:    Remove a student record \n"
		<< "S:    Display statistics \n" 
		<< "P:    Print students\n"

		<< "Q:    Quit \n\n"
		<< "Enter your choice: ";

	do
	{
		cin >> choice;

		choice = toupper(choice);

		switch (choice)
		{
		case 'A':
		case 'D': 
		case 'F':
		case 'R':
		case 'S':
		case 'P':
		case 'Q': valid = true;
				  break;
		default: 
			valid = false;
			cout << "\aInvalid choice!\n" << "Please try again: ";
			break;
		}
	} 
	while (!valid);

	return choice;
}

//*****************************************************************************************************

void process(HashTable <Student> & studentList)
{
	char choice;

	do
	{
		choice = getChoice();

		switch (choice)
		{
		case 'A': addStudent(studentList);
				  break;
		case 'D': displayStudents(studentList);
				  break;
		case 'F': findStudent(studentList);
				  break;
		case 'R': removeStudent(studentList);
			      break;
		case 'S': displayStatistics(studentList);
				  break;
		case 'P': printStudents(studentList);
				  break;
		case 'Q': break;
		}
	} 
	while (choice != 'Q');

}

//*****************************************************************************************************

void addStudent(HashTable <Student> & studentList)
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

	if (studentList.insert(student))
	{
		cout << "Student successfully added!" << endl;
	}
}

//*****************************************************************************************************

void displayStudents(HashTable<Student> & studentList)
{
	studentList._displayTable();
}

//*****************************************************************************************************

void findStudent(HashTable<Student> & studentList)
{
	Student obj;

	cout << "Please enter the ID you'd like to search for: ";

	cin >> obj.id;

	while (!studentList.retrieve(obj))
	{
		cout << "Could not find ID! Please try again: " << endl;
		cin >> obj.id;
	}

	cout << "Found! " << obj << endl;
}

//*****************************************************************************************************

void removeStudent(HashTable<Student> & studentList)
{
	Student obj;

	cout << "Please enter the student you'd like to delete: ";
	cin >> obj.id;

	while (!studentList.remove(obj))
	{
		cout << "Could not find ID! Please try again: " << endl;
		cin >> obj.id;
	}

	cout << "You've deleted: " << obj << endl;
}

//*****************************************************************************************************

void printStudents(HashTable<Student> & studentList)
{
	studentList.writeFile();
}

//*****************************************************************************************************

void displayStatistics(HashTable<Student> & studentList)
{
	studentList.statistics();
}
//*****************************************************************************************************

/*
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: A
Enter the student ID: 400
Enter the student's name:Aldin
Enter the student's city and state: St. Louis, Missouri
Enter the student's phone: 3145551234
Enter the student's gender: M
Enter the student's year: 4
Enter the student's credits: 64
Enter the student's gpa: 3.75
Enter the student's major: COSC
Student successfully added!
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: D
Address Prime Area                            Overflow
[0]
[1]14674/Rockne
[2]32631/Freud,         22447/Zylstra, Zelda A
[3]5430/Nighti         4559/Shyster, Samuel D
[4]17424/Nakamu
[5]7844/Aardva         7107/Shoemaker, Imelda M
[6]16622/Issacs
[7]31631/Aristo
[8]14815/Tchaik
[9]
[10]15755/Vanden         15889/Gazelle, Gwendolyn D
[11]7448/Roosev
[12]
[13]
[14]
[15]5710/Busch,
[16]9463/Hochsc
[17]
[18]
[19]19918/Virus,         20454/Chicita, Juanita A
[20]20991/August         4777/Gauss, Carl F
[21]
[22]
[23]5316/GotoDi         17376/Scrooge, Ebenezer T
[24]11749/Issacs
[25]11951/Mouse,
[26]
[27]23544/Gestal
[28]9743/Johnso
[29]
[30]11688/Kronec         30381/Elba, Able M
[31]
[32]4454/Atanas         23750/Vespucci, Vera D
[33]27503/Fahren         22277/Principal, Pamela P
[34]
[35]
[36]25831/Santam         30655/Angelo, Mike L         32598/Xerxes, Art I         16183/Kuts, Cole         29583/Yewliss, Cal C
[37]
[38]
[39]21144/Pasteu
[40]18264/Lucky,
[41]
[42]
[43]
[44]5873/Psycho         15052/Einstein, Alfred M         13511/Pitt, Stew         3930/Leibniz, Gottfried W
[45]
[46]7885/Fibona
[47]23497/Fault,
[48]
[49]19077/Medes,         28658/Cicero, Marsha
[50]24237/Euler,
[51]25377/Porgy,         30268/Newmann, Alfred E
[52]10236/Andrew         26316/Custer, General G
[53]10304/Deutsc
[54]
[55]
[56]18213/Marx,
[57]15802/Pascal
[58]30878/Lewis,         16540/Weerd, Dewey L
[59]
[60]15671/Rembra
[61]
[62]
[63]30749/Mendel         30280/Dewey, Johanna A
[64]
[65]23314/Macdon         400/Aldin
[66]
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: F
Please enter the ID you'd like to search for: 400
Found! 400/Aldin
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: S
Table Size: 67
Number of Elements: 62
Empty Positions: 28
Num of Chains: 18
Max Chain Length: 4
Num. of Collisions: 23
Avg. Chain Length: 1.3
Percentage Collisions: 37.1%
Load factor: 58.2%
Avg # of Search Steps: 1.1
Table is not empty
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: R
Please enter the student you'd like to delete: 400
You've deleted: 400/Aldin
========MENU========
A:    Add a new student
D:    Display the student records
F:    Find a student record
R:    Remove a student record
S:    Display statistics
P:    Print students
Q:    Quit

Enter your choice: Q
*/
