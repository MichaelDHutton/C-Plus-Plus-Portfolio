#include<iostream>

using namespace std;

void askForInput(int&, int&, double& shippingAndHandlingCharges);

void countAndDisplay(int, int, double shippingAndHandlingCharges = 10.0);

int main()
{
	int numOfOrder = 0, numOfStock = 0;
	double shippingAndHandlingCharges = 0.0;
	askForInput(numOfOrder, numOfStock, shippingAndHandlingCharges);
	countAndDisplay(numOfOrder, numOfStock, shippingAndHandlingCharges);


	return 0;
}

void askForInput(int& order, int& stock, double& shippingAndHandlingCharges)
{
	cout << "\n Number of spools ordered? ";
	cin >> order;
	while (order < 1)
	{
		cout << "\nError.Please enter a number greater than 0.Enter the number of spools ordered ";
		cin >> order;
	}

	cout << "Number of spools in stock? ";
	cin >> stock;
	while (stock < 0)
	{
		cout << "\nError.Please enter a positive number.Number of spools in stock? ";
		cin >> stock;
	}

	char sepcialCharge;

	cout << "\n Any special shipping and handling charges ? Enter Y or N ";
	cin >> sepcialCharge;

	while (sepcialCharge != 'y' && sepcialCharge != 'n')
	{
		cout << "\nError.Please enter Y or N. Y for there are special shipping and handling charges."
			<< "\n N for there are not special shipping and handling charges";
		cin >> sepcialCharge;
	}

	if (sepcialCharge == 'y')
	{

		cout << "\nEnter the special charges per spool ";
		cin >> shippingAndHandlingCharges;
		while (shippingAndHandlingCharges < 0)
		{
			cout << "\nError.Please enter a positive number.Enter the special charges per spool";
			cin >> shippingAndHandlingCharges;
		}
	}
	else shippingAndHandlingCharges = 10.0;
}
void countAndDisplay(int oder, int stock, double shippingAndHandlingCharges)
{
	int readyToShip, backorder = 0, subtotalForReady;
	double totalSnHChargesForReady, totalOfOderReady;

	if (oder <= stock)
	{
		readyToShip = oder;

	}
	else
	{
		readyToShip = stock;
		backorder = oder - stock;
	}

	subtotalForReady = readyToShip * 100;
	totalSnHChargesForReady = readyToShip * shippingAndHandlingCharges;
	totalOfOderReady = subtotalForReady + totalSnHChargesForReady;

	cout << "\n Number of spools ready to ship from currently in stock : " << readyToShip;
	cout << "\n Number of spools on backorder " << backorder;
	cout << "\n Subtotal of ready to ship " << subtotalForReady;
	cout << "\n Total shipping and handling charges on ready to ship spools" << totalSnHChargesForReady;
	cout << "\n Total for order ready to ship " << totalOfOderReady << endl;

}