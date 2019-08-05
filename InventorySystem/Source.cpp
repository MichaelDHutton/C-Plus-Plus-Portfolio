#include <iostream>
#include <fstream>

using namespace std;
const int recordNum = 3;
const int itemDis=45;
void add();
void display();
void change();

struct Inventory
{
	char recNum[recordNum];
	char item[itemDis];
	int qty;
	double wholeCost;
	double retailCost;
	char date[10];
	};

int main()
{

	Inventory record;
	long recNum;
	int options;
	do {

		cout << "Menu\n";
		cout << "1. Add a record\n";
		cout << "2. Display a Record\n";
		cout << "3. Change a Record\n";
		cout << "4. Exit\n";
		cin >> options;

		switch (options)
		{
		case 1:add(); break;

		case 2:display(); break;

		case 3:change(); break;
		
		}
	} while (options <= 3);
	if (options <= 3)
		system("pause");
	else(options ==4);
	exit(0);
	return 0;
}

void add()
{
	fstream fout;
	const int size = 3;
	char ch;
	int i = 0;
	fout.open("inventory.txt", ios::out);
	Inventory inv;
	do
	{
		cout << "Enter Record Number\n";
		cin.ignore();
		cin.getline(inv.recNum, recordNum);
		cout << "Enter the items description\n";
		cin.ignore();
		cin.getline(inv.item, itemDis);
		do
		{
			cout << "Enter Quantity\n";
			cin >> inv.qty;
			if (inv.qty < 0)
				cout << "Enter a positive quantity: \n";
		} while (inv.qty < 0);


		do {
			cout << "Enter in the Wholesale cost\n";

			cin >> inv.wholeCost;
			if (inv.wholeCost < 0)
				cout << "Enter a positive Wholesale Cost: \n";
		}

		while (inv.wholeCost < 0);

		do
		{
			cout << "Enter the retail cost\n";
			cin >> inv.retailCost;
			if (inv.retailCost < 0)
				cout << "Enter a positive Retail Cost: \n";
		} while (inv.retailCost < 0);

		cout << "Enter date ";
		cin.ignore();
		cin.getline(inv.date, 10);
		
		fout.write(reinterpret_cast<char*>(&inv), sizeof(inv));
		cout << "Do you wish to add another record" << endl;
		cin >> ch;
		} 
		while (ch=='Y' &&i< 3);
		fout.close();
}
void display()
{
	fstream fout;
	fout.open("inventory.txt", ios::in);
	Inventory inv;
	fout.read(reinterpret_cast<char*>(&inv), sizeof(inv));

	while (!fout.eof())
	{
		cout << "Record Number :\t";
		cout << inv.recNum;
		cout << "\nDescripition \t";
		cout << inv.item;
		cout << "\nQuantity \t";
		cout << inv.qty;
		cout << "\nWholesale Cost \t";
		cout << inv.wholeCost;
		cout << "\nRetail Cost \t";
		cout << inv.retailCost;
		cout << "\nDate \t";
		cout << inv.date;
		fout.read(reinterpret_cast<char*>(&inv),sizeof(inv));
	}
	fout.close();
}

void change() 
{
	fstream fout;
	fout.open("inventory.txt", ios::in|ios::out);
	Inventory inv;
	int recordNum;

	cout << "Enter the number of the record to change\n";
	cin >> recordNum;

	fout.seekg(recordNum*sizeof(inv), ios::beg);
	fout.read(reinterpret_cast<char*>(&inv), sizeof(inv));
	cout << "\nDescrpition\t";
	cout << inv.item;
	cout << "\nQuantity\t";
	cout << inv.qty;
	cout << "\nWholesale Cost\t";
	cout << inv.wholeCost;
	cout << "\nRetail Cost\t";
	cout << inv.retailCost;
	cout << "Enter the date\n";
	cout << inv.date;

	cout << "Enter new inventory data\n";
	cout << "Enter items description\n";
	cin.ignore();
	cin.getline(inv.item, itemDis);
	cout << "Enter Quantity\n";
	cin >> inv.qty;
	cout << "Enter in the Wholesale cost\n";
	cin >> inv.wholeCost;
	cout << "Enter the retail cost\n";
	cin >> inv.retailCost;
	cout << "Enter date ";
	cin.ignore();
	cin.getline(inv.date, 10);
	fout.seekg(recordNum*sizeof(inv), ios::beg);
	fout.write(reinterpret_cast<char*>(&inv), sizeof(inv));
	fout.close();



}