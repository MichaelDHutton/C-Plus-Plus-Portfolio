#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

bool testPassword(char Pass[]);
const int maxSize = 10;
const int minSize = 6;

int main()
{
	char Pass[maxSize];

	bool needtowork = true;


	while (needtowork == true)
	{
		cout << endl << "Password Rules: " << endl;
		cout << endl << "-------------------------------------------------------------" << endl;
		cout << "Password length minimum " << (minSize) << " characters and Maximum " << maxSize << " characters." << endl;
		cout << "most contains at least one uppercase and at least one lowercase letter, \n";
		cout << "and also contains at least one digit." << endl;
		cout << "PASSWORD: " << endl;
		cout << endl << "------------------" << endl;
		cin.getline(Pass, maxSize);
		cout << endl;


		needtowork = testPassword(Pass);

		if (needtowork == false)
		{
			cout << endl << "-------------------------------------------------------------" << endl;
			cout << "Password you entered has been accepted. " << endl;
			cout << endl << "-------------------------------------------------------------" << endl;
		}
		else
		{
			cout << endl << "-------------------------------------------------------------" << endl;
			cout << "Please try again with the instructions above." << endl;
			cout << endl << "-------------------------------------------------------------" << endl;
		}
	}
	return 0;
}


bool testPassword(char Pass[])
{
	bool Upper = false;
	bool Lower = false;
	bool Digit = false;
	bool needtowork = false;

	int LENGTH = strlen(Pass);


	for (int i = 0; i < LENGTH; i++)
	{
		if (isdigit(Pass[i]))
			Digit = true;
		if (islower(Pass[i]))
			Lower = true;
		if (isupper(Pass[i]))
			Upper = true;
	}


	if (LENGTH < (minSize) || LENGTH >(maxSize))
	{
		cout << endl << "-------------------------------------------------------------" << endl;
		cout << "ERROR! \n";
		cout << "Your password does not meet requirements.. " << endl;
		cout << "Password length should be Minimum " << (minSize) << " characters and Maximum " << maxSize << " characters." << endl << endl;
		cout << endl << "-------------------------------------------------------------" << endl;
		needtowork = true;
	}

	if (Digit == false)
	{
		cout << endl << "-------------------------------------------------------------" << endl;
		cout << "ERROR! \n";
		cout << "Your password does not contain a numerical digit." << endl << endl;
		cout << endl << "-------------------------------------------------------------" << endl;
		needtowork = true;
	}

	
	if (Lower == false)
	{
		cout << endl << "-------------------------------------------------------------" << endl;
		cout << "ERROR! \n";
		cout << "Your password does not contain a lowercase letter." << endl << endl;
		cout << endl << "-------------------------------------------------------------" << endl;
		needtowork = true;
	}

	
	if (Upper == false)
	{
		cout << endl << "-------------------------------------------------------------" << endl;
		cout << "ERROR! \n";
		cout << "Your password does not contain an uppercase letter." << endl << endl;
		cout << endl << "-------------------------------------------------------------" << endl;
		needtowork = true;
	}

	return needtowork;
}