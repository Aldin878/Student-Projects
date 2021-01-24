#include <iostream>
#include <string>
using namespace std;

//****************************************************************************************************

void getInput(string *);
bool checkLength(string);
bool checkCase(string);
bool checkDigit(string);
bool checkAlpha(string);
bool checkSymbol(string);
bool checkWhiteSpace(string);

//****************************************************************************************************

int main()
{
	string password;

	getInput(&password);
	cout << "Password entry successful! " << endl;
	cout << "Your password is: " << password << endl;

	return 0;
}

//****************************************************************************************************

void getInput(string * password)
{
	bool ckLength,
		ckCase,
		ckDigit,
		ckAlpha,
		ckSymbol,
		ckSpace;
	int check = 0;
	string line(50, '*');

	while (check < 6)
	{
		cout << line << endl;
		cout << "Enter your password: ";
		getline(cin, *password);
		ckLength = checkLength(*password);

		ckCase = checkCase(*password);

		ckDigit = checkDigit(*password);

		ckAlpha = checkAlpha(*password);

		ckSymbol = checkSymbol(*password);

		ckSpace = checkWhiteSpace(*password);

		check = ckLength + ckCase + ckDigit + ckAlpha + ckSymbol + ckSpace;

	}

}

//****************************************************************************************************

bool checkLength(string password)
{
	bool valid = true;

	if (password.length() < 8)
	{
		cout << "Your password is too short!" << endl;
		valid = false;
	}

	if (password.length() > 20)
	{
		cout << "Your password is too long!" << endl;
		valid = false;
	}

	return valid;
}

//****************************************************************************************************

bool checkCase(string password)
{
	bool valid = true;
	int upper = 0,
		lower = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] >= 65) && (password[i] <= 90))
		{
			upper++;
		}

		if ((password[i] >= 97) && (password[i] <= 122))
		{
			lower++;
		}

	}

	if (upper == 0)
	{
		cout << "Your password must contain at least one uppercase letter!"
			<< endl;
		valid = false;
	}

	if (lower == 0)
	{
		cout << "Your password must contain at least one lowercase letter!"
			<< endl;
		valid = false;
	}

	return valid;
}

//****************************************************************************************************

bool checkDigit(string password)
{
	bool valid = true;
	int digit = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] >= 48) && (password[i] <= 57))
		{
			digit++;
		}
	}

	if (digit == 0)
	{
		cout << "Your password must contain a digit!" << endl;
		valid = false;
	}

	return valid;
}

//****************************************************************************************************

bool checkAlpha(string password)
{
	bool valid = true;
	int alpha = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] >= 65) && (password[i] <= 90) ||
			(password[i] >= 97) && (password[i] <= 122))
		{
			alpha++;
		}
	}

	if (alpha == 0)
	{
		cout << "Your password must contain a letter!" << endl;
		valid = false;
	}

	return valid;
}

//****************************************************************************************************

bool checkSymbol(string password)
{
	bool valid = true;
	int symbol = 0;

	for (int i = 0; i < password.length(); i++)
	{
		if ((password[i] >= 33) && (password[i] <= 47) ||
			(password[i] >= 58) && (password[i] <= 64))
		{
			symbol++;
		}

		if ((password[i] >= 91) && (password[i] <= 96) ||
			(password[i] >= 123) && (password[i] <= 126))
		{
			symbol++;
		}

	}

	if (symbol == 0)
	{
		cout << "Your password must contain a symbol!" << endl;
		valid = false;
	}

	return valid;
}

//****************************************************************************************************

bool checkWhiteSpace(string password)
{
	bool valid = true;

	for (int i = 0; i < password.length(); i++)
	{
		if (password[i] == 32)
		{
			valid = false;
		}
	}

	if (valid == false)
	{
		cout << "Your password cannot contain a white space!" << endl;
	}

	return valid;
}

//****************************************************************************************************

/*
**************************************************
Enter your password: 123
Your password is too short!
Your password must contain at least one uppercase letter!
Your password must contain at least one lowercase letter!
Your password must contain a letter!
Your password must contain a symbol!
**************************************************
Enter your password: pass
Your password is too short!
Your password must contain at least one uppercase letter!
Your password must contain a digit!
Your password must contain a symbol!
**************************************************
Enter your password: Pas s
Your password is too short!
Your password must contain a digit!
Your password must contain a symbol!
Your password cannot contain a white space!
**************************************************
Enter your password: Pass123
Your password is too short!
Your password must contain a symbol!
**************************************************
Enter your password: Pass123123123123123123123
Your password is too long!
Your password must contain a symbol!
**************************************************
Enter your password: Pass123!
Password entry sucessful!
Your password is: Pass123!
Press any key to continue . . .
*/
