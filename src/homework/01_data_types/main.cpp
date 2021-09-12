//write include statements
#include <iostream>
#include "data_types.h"

//write namespace using statement for cout
using std::cout; using std::cin;

/*
Call multiply_numbers with 10 and 10 parameter values and display function result
*/
int main()
{
	// variables
	int num;
	int num1;
	int result;

	// first run
	cout << "This program multiplies two numbers.\n";
	cout << "Enter a number: ";
	cin >> num;
	result = multiply_numbers(num);
	cout << "First Result: " << result << "\n";

	// second run
	num1 = 4;
	result = multiply_numbers(num1);
	cout << "Second Result: " << result << "\n";

	// return
	return 0;
}
