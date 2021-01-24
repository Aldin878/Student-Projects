char * getID();
double getGPA();
char * getName();
void getInput(Students *, const int);
void displayAllStudentsInfo(const Students *, const int);

//*******************************************************************************************************

int main()
{
	string line(60, '*');
	const int SIZE = 3;
	Students * ptrStu = new Students[SIZE];

	cout << line << endl;
	cout << "Before user input: " << endl;
	displayAllStudentsInfo(ptrStu, SIZE);

	getInput(ptrStu, SIZE);

	cout << line << endl;
	cout << "After user input: " << endl;
	
	displayAllStudentsInfo(ptrStu, SIZE);

	delete[] ptrStu;
	return 0;
}

//*******************************************************************************************************

void getInput(Students * ptrStu, const int SIZE)
{
	char * stuID = nullptr;
	char * stuName = nullptr;
	double stuGPA;

	for (int i = 0; i < SIZE; i++)
	{
		cout << "Please enter the information for student #" << i + 1 << endl;
		stuID = getID();

		ptrStu[i].setStudentNumber(stuID);

		stuName = getName();

		ptrStu[i].setStudentName(stuName);

		stuGPA = getGPA();

		ptrStu[i].setGPA(stuGPA);
	}

}

//*******************************************************************************************************

char * getID()
{
	const int ID_LENGTH = 5;
	char * stuID = nullptr;
	stuID = new char[STR_SIZE];

	cout << "Please enter a 5 digit ID for the student: ";
	cin >> stuID;

	while (strlen(stuID) != ID_LENGTH)
	{
		cout << "Invalid input! Please enter an ID of exactly 5 characters!" << endl;
		cin >> stuID;
	}

	return stuID;
}

//*******************************************************************************************************

char * getName()
{
	char * stuName = nullptr;
	stuName = new char[STR_SIZE];

	cout << "Please enter a name for the student: ";
	cin >> stuName;

	return stuName;
}

//*******************************************************************************************************

double getGPA()
{
	const double LOWEST_GPA = 0.0;
	const double HIGHEST_GPA = 4.0;
	double stuGPA;

	cout << "Please enter the student's GPA: ";
	cin >> stuGPA;

	while (stuGPA < LOWEST_GPA || stuGPA > HIGHEST_GPA)
	{
		cout << "Error! Make sure the GPA is between " << LOWEST_GPA <<  " and " << HIGHEST_GPA << "!" << endl;
		cin >> stuGPA;
	}

	return stuGPA;
}

//*******************************************************************************************************

void displayAllStudentsInfo(const Students * ptrStu, const int SIZE)
{
	string line(60, '*');

	cout << setw(25) << left << "Name" << setw(25) << "ID" << setw(25) << "GPA" << endl;
	cout << line << endl;
	
	for (int i = 0; i < SIZE; i++)
	{
		ptrStu[i].display();
	}

}

//*******************************************************************************************************

/*
************************************************************
Before user input:
Name                     ID                       GPA
************************************************************
*none*                   00000                    0.00
*none*                   00000                    0.00
*none*                   00000                    0.00
Please enter the information for student #1
Please enter a 5 digit ID for the student: 0001
Invalid input! Please enter an ID of exactly 5 characters!
00001
Please enter a name for the student: Hinata
Please enter the student's GPA: 2.4
Please enter the information for student #2
Please enter a 5 digit ID for the student: 00002
Please enter a name for the student: Kageyama
Please enter the student's GPA: -1
Error! Make sure the GPA is between 0.00 and 4.00!
3.1
Please enter the information for student #3
Please enter a 5 digit ID for the student: 00003
Please enter a name for the student: Daichi
Please enter the student's GPA: 3.6
************************************************************
After user input:
Name                     ID                       GPA
************************************************************
Hinata                   00001                    2.40
Kageyama                 00002                    3.10
Daichi                   00003                    3.60
Daichi removed!
Kageyama removed!
Hinata removed!
Press any key to continue . . .
*/
