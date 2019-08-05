#include <iostream>
#include <ctime>
#include <string>

using namespace std;

enum MONTH { JAN, FEB, MARCH, JUNE, JULY, AUGUST, SEPT, OCTOBER, NOV, DEC };
const string NAME_OF_MONTH[] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const int DAYS_IN_MONTH[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
void getInput(int& month, int& Y)
{
	cout << "Enter a month (1-12) and a 4-digit year \n"
		<< " or separated by a space ( or enter 0 0 to exit): ";
	cin >> month >> Y;

	while (month < 0 || month > 12) {
		cout << " Please enter month between 1 and 12 ( or 0 to exit) \n"
			<< "Please re-enter month: ";
		cin >> month;
	}

}




bool isLeapYear(int Y) {
	if (Y % 100 == 0)
		return (Y % 400 == 0);
	else
		return (Y % 4 == 0);
}
int numberOfDaysInMonth(int month, int year) {
	int numberOfDays = DAYS_IN_MONTH[month];
	if (month == FEB && isLeapYear(year))
		numberOfDays++;
	return numberOfDays;
}


void getCurrentMonthAndYear(int& month, int& Y) {
	time_t epochSeconds = time(NULL);
	tm* tm_ptr = localtime(&epochSeconds);

	month = tm_ptr->tm_mon;
	Y = tm_ptr->tm_year + 1900;

}

int main() {

	int month, Y;

	getInput(month, Y);

	while (month != 0) {

		month--;

		cout << numberOfDaysInMonth(month, Y) << " days \n\n";

		getInput(month, Y);

	}
	cout << endl;

	getCurrentMonthAndYear(month, Y);
	cout << "The current month of " << NAME_OF_MONTH[month] << " in year " << Y << " has " << numberOfDaysInMonth(month, Y) << " days.\n\n";
	return 0;


}