#include <iostream>
#include <cctype> 
#include <cstring>
using namespace std;

//****************************************************************************************************

void convertToUpper(char *);
void findAndRemove(char *);
void appendAy(char *);
void convertPigLatin(char *);

//****************************************************************************************************

int main()
{
	const int SIZE = 81;
	char cinput[SIZE];
	convertPigLatin(cinput);

	return 0;
}

//****************************************************************************************************

void convertPigLatin(char * str)
{
	const int SIZE = 81;
	char * str2 = nullptr;
	str2 = new char[SIZE];
	*str2 = *str;

	cout << "Input a string or type quit to quit: " << endl;
	cin.getline(str2, SIZE);
	convertToUpper(str2);

	while (strcmp(str2, "QUIT") != 0)
	{

		findAndRemove(str2);
		appendAy(str2);
		cout << str2 << endl;
		cout << "Input a string or type quit to quit: " << endl;
		cin.getline(str2, SIZE);
		convertToUpper(str2);
	}

	cout << "Quit!" << endl;
}

//****************************************************************************************************

void convertToUpper(char * str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		str[i] = toupper(str[i]);
		i++;
	}

}

//****************************************************************************************************

void findAndRemove(char * str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == 'I' && str[i + 1] == 'G')
		{
			str[i] = '\0';
		}

		i++;
	}
}

//****************************************************************************************************

void appendAy(char * str)
{
	int i = 0,
	char str2[] = "ay";
	
	while (str[i] != '\0')
	{
		i++;
	}

	strcat_s(str, 81, str2);
}
//****************************************************************************************************

/*
Input a string or type quit to quit:
testing
TESTINGay
Input a string or type quit to quit:
night
Nay
Input a string or type quit to quit:
quit
Quit!
Press any key to continue . . .
*/
