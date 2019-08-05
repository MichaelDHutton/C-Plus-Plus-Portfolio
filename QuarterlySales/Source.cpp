#include <iostream>

using namespace std;

class DivSales
{
private:
	static int yearSales;
	int quaterSales[4];

public:
	void AddSales(int, int, int, int);
	int Sales(int);
	int getvalue() { return yearSales; }
};


void DivSales::AddSales(int sale1, int sale2, int sale3, int sale4)
{
	quaterSales[0] = sale1;
	quaterSales[1] = sale2;
	quaterSales[2] = sale3;
	quaterSales[3] = sale4;

	yearSales = yearSales + sale1 + sale2 + sale3 + sale4;
}

int DivSales::Sales(int n)
{

	int value = quaterSales[n];
	return value;

}

void error()
{
	system("cls");
	cout << "You have entered a negative slaes. Restart program and try again";
	cout << "Press any key to restart program\n";
	system("pause");
	exit(0);
}



int DivSales::yearSales;

int main()
{
	const int DS = 6;
	DivSales DivisionSale[DS];
	int quarter, division;

	for (division = 0; division < 6; division++)
	{
		int Qrt1, Qrt2, Qrt3, Qrt4;

		int Q;

		cout << "Enter Sales of Division: " << division + 1 << endl;


		cout << "Enter Q1 Sales: ";
		cin >> Qrt1;
		Q = Qrt1;
		if (Q < 0)
			error();

		cout << "Enter Q2 Sales: ";
		cin >> Qrt2;
		Q = Qrt2;
		if (Q < 0)
			error();

		cout << "Enter Q3 Sales: ";
		cin >> Qrt3;
		Q = Qrt3;
		if (Q < 0)
			error();

		cout << "Enter Q4 Sales: ";
		cin >> Qrt4;
		Q = Qrt4;
		if (Q < 0)
			error();


		DivisionSale[division].AddSales(Qrt1, Qrt2, Qrt3, Qrt4);

	}

	cout << "\n----------------------------------------\n";
	cout << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;

	// table for quarterly sales of each division
	for (division = 0; division < 6; division++)

	{

		cout << "Div " << division + 1;
		for (quarter = 0; quarter < 4; quarter++)

		{

			// calling function Sales 6 times
			cout << "\t$" << DivisionSale[division].Sales(quarter);

		}

		cout << endl;

	}

	cout << "----------------------------------------\n";
	cout << "\nTotal corporate sales for the year: ";
	cout << "$" << DivisionSale[0].getvalue() << endl;

	system("pause");
	return 0;

}