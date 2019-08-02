#include <iostream>     
 #include <windows.h>      // Needed to set cursor positions
 #include <string>
 using namespace std;
 
 struct MonthlyBudget
 {
	 double housing,
		 utilities,
		 householdExpenses,
		 transportation,
		 food,
		 medical,
		 insurance,
		 entertainment,
		 clothing,
		 miscellaneous;
	 MonthlyBudget(double h = 0, double u = 0, double he = 0, double t = 0, double f = 0, double m = 0, double i = 0, double e = 0, double c = 0, double misc = 0)
	 {
		 housing = h;
		 utilities = u;
		 householdExpenses = he;
		 transportation = t;
		 food = f;
		 medical = m;
		 insurance = i;
		 entertainment = e;
		 clothing = c;
		 miscellaneous = misc;
	 }
 };

 void getAmount(MonthlyBudget&);
void displayAmount(MonthlyBudget&, MonthlyBudget&);
 void placeCursor(HANDLE, int, int);   // Function prototypes
 void displayPrompts(HANDLE);
 void getUserInput(HANDLE, MonthlyBudget&);
 

 int main()
 {
	 MonthlyBudget utlty(500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 150.00, 75.00, 50.00);
	 MonthlyBudget user;
    
	 MonthlyBudget input;          
	
	    // Get the handle to standard output device (the console)
	    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	
	    displayPrompts(screen);
	    getUserInput(screen, user);
		
		displayAmount(user, utlty);
		system("pause");
	    return 0;
	 }

 /******************************************************
 *                    placeCursor                     *
 ******************************************************/
 void placeCursor(HANDLE screen, int row, int col)
 {                      // COORD is a defined C++ structure that
    COORD position;     // holds a pair of X and Y coordinates
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);
 }

 /******************************************************
 *                   displayPrompts                   *
 ******************************************************/
 void displayPrompts(HANDLE screen)
 {
    placeCursor(screen, 3, 25);
    cout << "*******Actual Spent*******" << endl;
    placeCursor(screen, 5, 25);
    cout << "Housing: " << endl;
    placeCursor(screen, 7, 25);
    cout << "Utilities: " << endl;
	placeCursor(screen, 9, 25);
	cout << "House Expences: "<< endl;
	placeCursor(screen, 11, 25);
	cout << "Transportation: " << endl;
	placeCursor(screen, 13, 25);
	cout << "Food : " << endl;
	placeCursor(screen, 15, 25);
	cout << "Medical :" << endl;
	placeCursor(screen, 17, 25);
	cout << "Insurance: " << endl;
	placeCursor(screen, 19, 25);
	cout << "Enterainment: " << endl;
	placeCursor(screen, 21, 25);
	cout << "Clothing: " << endl;
	placeCursor(screen, 23, 25);
	cout << "Miscellaneous :" << endl;

 }

 /******************************************************
 *                    getUserInput                    *
 ******************************************************/
 void getUserInput(HANDLE screen, MonthlyBudget& user)
 {
    placeCursor(screen, 5, 45);
	cin >> user.housing;
    placeCursor(screen, 7, 45);
    cin >> user.utilities;
    placeCursor(screen, 9, 45);
    cin >> user.householdExpenses;
	placeCursor(screen, 11, 45);
	cin >> user.transportation;
	placeCursor(screen, 13, 45);
	cin >> user.food;
	placeCursor(screen, 15, 45);
	cin >> user.medical;
	placeCursor(screen, 17, 45);
	cin >> user.insurance;
	placeCursor(screen, 19, 45);
	cin >> user.entertainment;
	placeCursor(screen, 21, 45);
	cin >> user.clothing;
	placeCursor(screen, 23, 45);
	cin >> user.miscellaneous;

 }void displayAmount(MonthlyBudget& user, MonthlyBudget& utlty)
 {
	 cout << endl << "   Here are your individual totals for the month:\n";
	 cout << endl << "   Housing: " << "$ " << user.housing << endl;

	 if (user.housing > utlty.housing)
	 {
		 cout << "   Your housing expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your housing expenses was under the budget\n";
	 }

	 cout << endl << "   Utilities: " << "$ " << user.utilities << endl;
	 if (user.utilities > utlty.utilities)
	 {
		 cout << "   Your utilities expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your utilities expenses was under the budget\n";
	 }

	 cout << endl << "   Household Expenses: " << "$ " << user.householdExpenses << endl;
	 if (user.householdExpenses > utlty.householdExpenses)
	 {
		 cout << "   Your household expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your household expenses was under the budget\n";
	 }

	 cout << endl << "   Transportation: " << "$ " << user.transportation << endl;
	 if (user.transportation > utlty.transportation)
	 {
		 cout << "   Your transportation expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your transportation expenses was under the budget\n";
	 }

	 cout << endl << "   Food: " << "$ " << user.food << endl;
	 if (user.food > utlty.food)
	 {
		 cout << "   Your food expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your food expenses was under the budget\n";
	 }

	 cout << endl << "   Medical:: " << "$ " << user.medical << endl;
	 if (user.medical > utlty.medical)
	 {
		 cout << "   Your medical expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your medical expenses was under the budget\n";
	 }

	 cout << endl << "   Insurance: " << "$ " << user.insurance << endl;
	 if (user.insurance > utlty.insurance)
	 {
		 cout << "   Your insurance expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your insurance expenses was under the budget\n";
	 }


	 cout << endl << "   Entertainment: " << "$ " << user.entertainment << endl;
	 if (user.entertainment > utlty.entertainment)
	 {
		 cout << "   Your entertainment expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your entertainment expenses was under the budget\n";

	 }
	 cout << endl << "   Clothing: " << "$ " << user.clothing << endl;
	 if (user.clothing > utlty.clothing)
	 {
		 cout << "   Your clothing expenses was over the budget\n";
	 }
	 else
	 {
		 cout << "   Your clothing expenses was under the budget\n";
	 }

	 cout << endl << "   Miscellaneous: " << "$ " << user.miscellaneous << endl;
	 if (user.miscellaneous > utlty.miscellaneous)
	 {
		 cout << "   Your miscellaneous expensees was over the budget\n";
	 }
	 else

	 {

		 cout << "   Your miscellaneous expenses was under the budget\n";

	 }

	 double userBudget = user.housing + user.utilities + user.householdExpenses + user.transportation + user.food + user.medical + user.insurance + user.entertainment + user.clothing + user.miscellaneous;

	 double utltyBudget = utlty.housing + utlty.utilities + utlty.householdExpenses + utlty.transportation + utlty.food + utlty.medical + utlty.insurance + utlty.entertainment + utlty.clothing + utlty.miscellaneous;

	 cout << endl << "   Total expenses for the month: $ " << userBudget;

	 if (userBudget > utltyBudget)
	 {
		 cout << endl << "   Your expenses are over your monthly average budget by $ " << userBudget - utltyBudget << endl;
	 }
	 else
	 {
		 cout << endl << "   Your expenses are under your monthly average budget by $ " << userBudget - utltyBudget << endl;
	 }
 }