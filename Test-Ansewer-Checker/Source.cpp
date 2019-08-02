#include <iostream>
#include <cctype>

using namespace std;

void checkAnswer(char[], char[], int, int);

int main()
{
	const int QUESTIONS = 20;
	const int MIN2PASS = 15;
	char retest = 'Y';

	while (retest == 'Y' || retest == 'y') {
		char setKey[QUESTIONS] = { 'B','D','A','A','C',
		'A','B','A','C','D',
		'B','C','D','A','D',
		'C','C','B','D','A' };

		char test_setKey[QUESTIONS];



		cout << "====================================================" << endl;
		cout << "= Enter a letter from A, B, C, D for each question =" << endl;
		cout << "====================================================" << endl;

		// Loop for users setKey

		for (int userAnsw = 0; userAnsw < QUESTIONS; userAnsw++)
		{
			cout << "Please enter your answer for question #" << (userAnsw + 1) << ": ";
			cin >> test_setKey[userAnsw];

			// Validation for user setKey
			while (test_setKey[userAnsw] != 'A' && test_setKey[userAnsw] != 'B' && test_setKey[userAnsw] != 'C' && test_setKey[userAnsw] != 'D')
			{
				cout << "Only A, B, C or D are accepted. Please try again...\n";
				cout << "Please enter your answer for question #" << (userAnsw + 1) << ": ";
				cin >> test_setKey[userAnsw];



			}
		}
		checkAnswer(setKey, test_setKey, QUESTIONS, MIN2PASS);
		cout << " Retest again? (y/n) ";
		cin >> retest;


	}
	return 0;
}

void checkAnswer(char setKey1[], char test_setKey1[], int QUESTIONS, int MIN2PASS)
{
	int correctsetKey = 0;
	cout << "\nTo pass the test you need at least 15 correct." << endl;

	//Check the student's replies against the correct setKey
	for (int i = 0; i < QUESTIONS; i++)
	{
		if (setKey1[i] == test_setKey1[i])
			correctsetKey++;
	}

	//Did they pass or fail?
	if (correctsetKey >= MIN2PASS)
	{
		cout << "\nCongratulations! You passed the test!\n";
	}
	else
	{
		cout << "\nSorry. You failed the test. Better luck next time!\n";
	}

	//Display list of questions incorrectly answered
	cout << "\nThese are the questions you missed...\n";

	for (int i = 0; i < QUESTIONS; i++)
	{
		if (setKey1[i] != test_setKey1[i])
			cout << "Question # " << i << " is wrong." << endl;
	}

	//Display the number of correct and incorrect setKey
	cout << "\nYou answered a total of " << correctsetKey << " correctly." << endl;
	cout << "\nYou answered a total of " << QUESTIONS - correctsetKey << " wrong." << endl;
}