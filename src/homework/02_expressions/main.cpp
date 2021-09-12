//write include statements
#include <iostream>
#include <iomanip>
#include <math.h>
#include "hwexpressions.h"

//write namespace using statement for cout
using std::cin; using std::cout; using std::setw; using std::setprecision; using std::fixed;

/*
Get the tax, tip, and total cost of a given meal
*/
int main()
{
	// variables
	double meal_amount;
	double tip_rate;
	double tip_amount;
	double tax_amount;
	double total;

	// explain purpose of program
	cout << "This program calculates tax and tip for a given meal and displays an itemized receipt for the user.\n";

	// get the price of the meal and the tip rate from user input
	cout << "Enter the cost of the meal: ";
	cin >> meal_amount;
	cout << "Enter the percentage you will tip without a %.  Example: 15 for 15%: ";
	cin >> tip_rate;

	// get tax rate on meal 
	tax_amount = get_sales_tax_amount(meal_amount);

	// get tip rate for meal
	tip_amount = get_tip_amount(meal_amount, tip_rate);

	// get total price of meal
	total = meal_amount + tax_amount + tip_amount;

	// math.h correction to total due to binary being like this
	total = roundf(total*100)/100;

	// output to user
	cout << fixed;
	cout << setprecision(2);
	cout << "\n";
	cout << "Your Receipt\n";
	cout << setw(14) << "Meal Amount: $" << setw(5) << meal_amount << "\n";
	cout << setw(14) << "Sales Tax:   $" << setw(5) << tax_amount << "\n";
	cout << setw(14) << "Tip Amount:  $" << setw(5) << tip_amount << "\n";
	cout << setw(14) << "Total:       $" << setw(5) << total << "\n\n";
	cout << "Goodbye.";

	// return
	return 0;
}
