// Porgram 4 Gratuity CaLculator
// Michael Hutton
//#01   Design a Tips class that calculates the gratuity on a restaurant meal.
//#02 	The only Tips class member variable, taxRate, should be set by a one - parameter constructor to whatever rate is passed to it when a Tips object is instantiated.
//#03 	If no argument is passed, a default tax rate of .065 should be used.The tax rate can be changed by the programmer when the object is instantiated.
//#04 	The class should have just one public function, computeTip, which accepts two arguments, the total bill amount(including tax) and the tip rate.
//#05 	It should use this information to compute the cost of the meal before the tax was added.This is known as the meal cost.
//#06 	It should then apply the tip rate to just the meal cost portion of the bill(and not the tax) to compute and return the tip amount.
//#07 	Demonstate the class by creating a program that creates a single Tips object.
//#08 	The program asks the user to enter a total bill amount(including tax) and tip rate.
//#09 	The program outputs : total bill amount(not including tip), meal cost, tip rate, tip amount, total bill including tip.
//#10 	The program asks the user if they have another meal to compute.Program terminates if the user does not enter y / Y to the previous question.
//#11 	Include flowchartXX.svg, screenshots, and programXX.exe in the compressed(.zip file) project directoryand submit to Blackboard.

#include <iostream> // to read inputs and to write outputs
#include <iomanip> // to manipulate the output on c++

using namespace std;

// Prototypes is a declared function without the body right away.

class Tips
{
private:
	double taxrate;		    	//variable to hold the tax rate

public:
	Tips(double rate)    		// Constructor that accepts a tax rate
	{                          	// or uses a default value of 6.5%
		if (rate > 0)
			taxrate = rate;
		else
			taxrate = .065;
	}
	double computeTip(double, double);
};


double Tips::computeTip(double totalbill, double tiprate)
{
	double mealCost = totalbill / (1 + taxrate);
	double tipAmount = mealCost * tiprate;

	return tipAmount;
}



int main()
{
	//variables

	char yn;  			

	double taxrate;			
	double tipAmount;			
	double totalbill;			
	double tippercent;			
	double mealCost{};		
	double tiprate;		
 do 
 {
	//outputs / inputs 
	cout << "Enter the tax rate percenetage else press enter 0 : ";
	cin >> taxrate;
	// taxrate to decimal
	taxrate = taxrate / 100;

	Tips tipHelper(taxrate);

		
		cout << "\n\n\n************* Tip Calculator *********** \n\n";

		
		cout << "Enter the total amount of the meal including tax : ";
		cin >> totalbill;

		
		cout << "Enter the % tip you want to leave : ";
		cin >> tippercent;

		// convert tip rate from percentage to decimal
		tippercent = tippercent / 100;

		// computeTip function to calcutate the tip amount
		tipAmount = tipHelper.computeTip(totalbill, tippercent);

		//The program outputs : total bill amount(not including tip), meal cost, tip rate, tip amount, total bill including tip.
		cout << "The cost of the meal not including tip is $" << setprecision(2) << fixed << totalbill << ".\n";
		cout << "The percentage of tip you wish to give is " << setprecision(2) << fixed << tippercent * 100 << "%.\n";
		cout << "Your tip is $" << setprecision(2) << fixed << tipAmount << ".\n";
		cout << "The cost of the meal including tip is $" << setprecision(2) << fixed << totalbill + tipAmount << ".\n";

		// Place function call to ask if the user wants to calculate another tip?
		cout << "Do you want to compute another tip (Y/N)?\n";
		cin >> yn;
	}

	while (yn == 'y' || yn == 'Y');

	return 0;

}
