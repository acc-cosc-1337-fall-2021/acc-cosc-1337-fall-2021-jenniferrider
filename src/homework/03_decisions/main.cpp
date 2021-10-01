// write include statements
#include <iostream>
#include <decisions.h>

// namespaces
using std::cout; using std::cin;

// main
int main() 
{
	// variables
	int num;
	int grade;
	string letter_grade;

	// menu to select your poison
	cout << "\n\nMAIN MENU\n\n";
	cout << "1-Letter Grade Using If\n";
	cout << "2-Letter Grade Using Switch\n";
	cout << "3-Exit\n\n";
	cout << "Enter your selection from the menu: ";
	cin >> num;

	switch(num)
	{
		case 1 ... 2:
			// if user selected 1 or 2, get user input for numerical grade
			cout << "Enter a numerical grade between 0 and 100: ";
			cin >> grade;

			// validate if number is legit
			if (grade < 0 || grade > 100)
			{
				cout << "\nThe number you entered is out of range.\n";
			}
			else
			{
				// if number was legit, run correct function using user input from menu
				switch (num)
				{
					case 1:
						cout << "\nYou chose the 'if' method of letter grade calculation.";
						letter_grade = get_letter_grade_using_if(grade);
						break;
					default:
						cout << "\nYou chose the 'switch' method of letter grade calculation.";
						letter_grade = get_letter_grade_using_switch(grade);
						break;
				}

				// output result to user
				cout << "\nThe numerical grade " << grade << " is the letter grade " << letter_grade << ".\n";
			}
			break;
		// user chose to exit program
		case 3:
			cout << "\nYou chose to exit the program.\n";
			break;
		// user does not understand how to read a menu or unclear on numbers
		default: 
			cout << "\nYou made an invalid selection.\n";
			break;
	}
	// end of program statement
	cout << "\nThis program will now exit.  Goodbye.\n";
	
	// return
	return 0;
}