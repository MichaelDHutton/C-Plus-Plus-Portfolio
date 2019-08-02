//Program 5 Chips and Salsa
//Michael Hutton
//#01   Write a program to keep track of salsa sales.
//#02 	Five salsa flavors are : mild, medium, sweet, hot, zesty.
//#03 	Use two parallel five - element arrays : array of strings for salsa names and array of integers for jars sold during last month for each salsa Type.
//#04 	Salsa names should be stored using an initilization list at the time of array creation.
//#05 	Prompt the user to enter number of jars sold of each Type.
//#06 	After the sales data has been entered, the program should produce a report that displays the following :
//#07 	sales for each salsa Type, total sales, and names of the highest and lowest selling flavors.
//#08 	Input validation : Do not accept negative values for number of jars sold.
//#09 	Include flowchartXX.svg, screenshots, and programXX.exe in the compressed(.zip file) project directoryand submit to Blackboard.

#include <iostream>
#include <iomanip>
#include <string>

#include<iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes
int getTotal(int[], int);

int leastJarsSold(int[], int);

int mostJarsSold(int[], int);

int main()
{
	const int salsa_Types = 5;
	int sales[salsa_Types];
	string name[salsa_Types] = { "Mild", "Medium", "Sweet", "Hot", "Zesty" };


	// Create the arrays for the names and sales amounts

	int totalJarsSold,
		mostSold,
		leastSold;

	// Input the number of jars sold

	for (int type = 0; type < salsa_Types; type++)
	{
		cout << "Jars sold last month of " << name[type] << ": ";
		cin >> sales[type];

		while (sales[type] < 0)
		{
			cout << "Jars sold must be 0 or more.  Please re-enter: ";
			cin >> sales[type];
		}
	}


	// Call functions to get total sales and high and low selling products
	totalJarsSold = getTotal(sales, salsa_Types);

	leastSold = leastJarsSold(sales, salsa_Types);

	mostSold = mostJarsSold(sales, salsa_Types);

	// Produce the sales report
	cout << endl << endl;
	cout << "     Salsa Sales Report \n\n";
	cout << "Name              Jars Sold \n";
	cout << "____________________________\n";


	cout << name[0] << "                  " << sales[0] << "\n";
	cout << name[1] << "                " << sales[1] << "\n";
	cout << name[2] << "                 " << sales[2] << "\n";
	cout << name[3] << "                   " << sales[3] << "\n";
	cout << name[4] << "                 " << sales[4] << "\n";

	// insert the code that prints the salsa names and number jars sold

	cout << "\nTotal Sales:" << setw(14) << totalJarsSold << endl;
	cout << "High Seller: " << name[mostSold] << endl;
	cout << "Low Seller : " << name[leastSold] << endl;

	system("pause");
	return 0;
}

/************************************************************
 *                       	getTotal                         *
 ************************************************************/
int getTotal(int array[], int Type)
{
	int total = 0;

	for (int type = 0; type < Type; type++)
		total += array[type];
	return total;
}

/************************************************************
 *                    mostJarsSold                          *
  ************************************************************/
int mostJarsSold(int array[], int Type)
{
	int indexLarge = 0;

	for (int pos = 1; pos < Type; pos++)
	{
		if (array[pos] > array[indexLarge])
			indexLarge = pos;
	}
	return indexLarge;
}

/************************************************************
 *                    leastJarsSold                         *
 ************************************************************/
int leastJarsSold(int array[], int Type)
{
	int indexSmall = 0;

	for (int pos = 1; pos < Type; pos++)
	{
		if (array[pos] < array[indexSmall])
			indexSmall = pos;
	}
	return indexSmall;
}