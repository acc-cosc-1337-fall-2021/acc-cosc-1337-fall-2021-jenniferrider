//write include statements
#include<iostream>
#include<dna.h>
#include<string>
#include <stdio.h>

//write using statements
using std::cout; using std::cin; using std::string;

/*
Write code that prompts user to enter 1 for Factorial, or 2 for GCD.  The program will prompt user for a 
number to factor or two numbers for greatest common denominator and display the result. Program runs as long as 
user enters a y or Y.
*/
int main() 
{
	//constants
	const int secret1 = 12;
	const int secret2 = 2147483647;

	// variables
	string run_again;
	int my_selection;
	int my_answer;
	int num;
	int num1;
	int num2;

	// initialize
	run_again = "y";

	while(run_again == "y")
	{
		// menu to select your poison
		cout << "\n\nMAIN MENU\n\n";
		cout << "1-Factorial\n";
		cout << "2-Greatest Common Divisor\n";
		cout << "3-Exit\n\n";
		cout << "Enter your selection from the menu or 4 for an explanation of each option and limitations: ";
		cin >> my_selection;

		switch(my_selection)
		{
			// user chose 1 or 2
			case 1 ... 2:
				if(my_selection == 1)
				{
					// get user input for factorial
					cout<<"\nYou chose Factorial aka Adventures with Factorials.\n";
					cout<<"Enter a number to start your personal factorial adventure: ";
					cin>>num;
					if(num > secret1)
					{
						num = secret1;
					}
					my_answer=factorial(num);
				}
				else
				{
					// get user info for greatest common divisor
					cout<<"\nYou chose Greatest Common Divisor To Ever Exist in Mathematics\n";
					cout<<"Enter two numbers to get their greatest common divisor:\n";
					cout<<"First number: ";
					cin>>num1;
					if(num1 > secret2)
					{
						num1 = secret2;
					}
					cout<<"Second number: ";
					cin>>num2;
					if(num2 > secret2)
					{
						num2 = secret1;
					}
					my_answer=gcd(num1,num2);
				}
				// display answer
				cout<<"Your answer is " << my_answer << ".\n";

				// ask if user would like to run again
				cout<<"Would you like to do this again? ";
				cin>>run_again;
				break;
			// user chose to exit program
			case 3:
				cout << "\nYou chose to exit the program.\n";
				cout << "Are you sure you don't want to at least try? Enter 'y' to run again to  or 'n' to exit program: ";
				cin>>run_again;
				break;
			// user chose to explore their options
			case 4:
				cout << "\nMenu Option 1: Factorial\n";
				cout << "A factorial is a number's product and all the numbers proceeding it.\n";
				cout << "Example: 5:  1*2*3*4*5 = 120\n\n";
				cout << "Menu Option 2: Greatest Common Divisor\n";
				cout << "The greatest common divisor is the largest number that two integers can be divided by.\n";
				cout << "Example: 21 and 28: 7 is the greatest common divisor\n\n";
				cout << "Menu Option 3: Exit Program\n";
				cout << "Exit the program.\n\n";
				cout << "Note: the int data type only allows numbers up to 2,147,483,647.  So when entering a number for factorial \n";
				cout << "your effective limit is 12: for greatest common divisor, 2,147,483,647. I will drop your number to one of those \n";
				cout << "if needed, as otherwise, my program freezes and if you're using VSCode, you have to ctrl-C to get out.  Super annoying.\n";
				break;
			// user chose secret option which means you saw it in the code
			case 22:
				cout << "This is a secret option.  Clever.\n";
				cout << "Enter a number: ";
				cin >> num;
				my_answer=factorial(num);
				my_answer=gcd(num,my_answer);
				cout << "The answer is " << my_answer << ".\n";
				break;
			// user does not understand how to read a menu or unclear on numbers
			default: 
				cout << "\nYou made an invalid selection. Try again.\n";
				break;
		}
		
		//run again?
		if(run_again == "Y" || run_again == "y")
		{
			run_again = "y";
		}
		else
		{
			run_again = "n";
		}
	}
	// end of program statement
	cout << "\nThis program will now exit.  Goodbye.\n";
	return 0;
}