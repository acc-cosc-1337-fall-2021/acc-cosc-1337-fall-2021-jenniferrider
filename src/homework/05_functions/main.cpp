// include
#include <iostream>
#include<func.h>
#include<stdio.h>

// namespace
using std::cout; using std::cin; using std::toupper;
/*
So much DNA stuff here.

*/
int main() 
{
	// variables
	int my_selection;
	int num;
	int num1;
	int num2;
	int run_count;
	string run_again;
	string my_dna;

	// initialize variables
	run_count = 0;
	run_again = "y";

	while(run_again == "y")
	{
		run_count++;
		cout << "\n" << run_count << "\n\n";
		// menu to select your poison
		cout << "\n\nMAIN MENU\n\n";
		cout << "1-Get GC Content\n";
		cout << "2-Get DNA Complement\n";
		cout << "3-Exit\n\n";

		cout << "My Selection: ";
		cin >> my_selection;

		switch(my_selection)
		{
			case 1 ... 2:
				cout << "DNA is a self-replicating material that is present in nearly all living organisms\n";
				cout << "as the main constituent of chromosomes. It is the carrier of genetic information.\n";
				cout << "A, C, G, and T are the 'letters' of the DNA code; they stand for the chemicals\n";
				cout << "adenine (A), cytosine (C), guanine (G), and thymine (T), respectively, that make up\n";
				cout << "the nucleotide bases of DNA.\n\n";

				cout << "Enter a string of letters to denote DNA: ";
				cin >> my_dna;

				// convert to uppercase
				my_dna=convert_to_uppercase(my_dna);

				// select is 1
				if(my_selection == 1)
				{
					double retanswer;
					cout << "\nYou chose to get the GC Content.";
					retanswer = get_gc_content(my_dna);
					cout << "The GC content of " << my_dna << " is " << retanswer << ".\n\n";
				}
				else
				{
					string retanswer;
					cout << "You chose to get the DNA complement.";
					retanswer=get_dna_complement(my_dna);
					cout << "The DNA complement of " << my_dna << " is " << retanswer << ".\n\n";
				}
				// ask if user would like to run again
				cout<<"Would you like to do this again? ";
				cin>>run_again;
				break;
			case 3:
				cout << "\nYou chose to exit the program.\n";

				// conditional
				if(run_count < 1)
				{
					cout << "Are you sure you don't want to try at least once? Enter 'y' to run again to  or 'n' to exit program: ";
					cin>>run_again;
				}
				else
				{
					run_again = "n";
				}
				break;
			default:
				cout << "Invalid entry: try again.\n";
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
	cout << "\nYou ran this program " << run_count << " " << "time(s)" << ".\n";
	cout << "\nThis program will now exit.  Goodbye.\n";
	return 0;
}