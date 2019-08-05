#include <iostream>
#include <iomanip>

using namespace std;

//construct snow record

struct snowRecord 
{
	int date;
	double snow;
};

int main() {

	snowRecord snow[7], temp;
	char month[15];

	int startDate, endDate;

	cout << "Enter the name of the month: " <<endl;
	cin >> month;
	cout << "Snow record for week: " << endl;
	cout << "Enter the starting and ending of date( Only dd): " << endl;
	cin >> startDate >> endDate;
	
	for (int i = 0; i < 7; i++) {
		cout << "Enter the snow depth for date " << startDate + i <<": ";
		snow[i].date = startDate + i;
		cin >> snow[i].snow;
	}

//sort records 

	int min;
	for (int i = 0; i < 7 - 1; i++) {
		min = i;
		for (int j = i + 1; j < 7; j++) {
			if (snow[j].snow < snow[min].snow)
				min = j;
		}
		temp = snow[min];
		snow[min] = snow[i];
		snow[i] = temp;
	}
	cout << "Snow Report  " << month << " " << startDate << " " << endDate << endl;
	cout << "Date " << " Snow " << endl;
	for (int i = 0; i < 7; i++) {
		cout << snow[i].date << "\t" << snow[i].snow << endl;


	}return 0;
}