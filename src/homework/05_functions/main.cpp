// include
#include<iostream>
#include<func.h>
#include<stdio.h>

// namespace
using std::cout; using std::cin;
/*
So much DNA stuff here.

*/
int main() 
{
	// variables
	int my_selection;
	int run_count;
	int my_count;
	string run_again;
	string my_dna;

	// initialize variables
	run_count = 0;
	my_count = 0;
	run_again = "y";

	while(run_again == "y")
	{
		// number of times program has run
		my_count++;

		// menu to select your poison
		cout << "\n\nMAIN MENU\n\n";
		cout << "1-Get GC Content\n";
		cout << "2-Get DNA Complement\n";
		cout << "3-Exit\n\n";

		// user selection
		cout << "My Selection: ";
		
		// user input with validation
		if(!(cin>>my_selection))
		{
			cin.clear();
			cin.ignore(10000,'\n');
			my_selection = 5;
		}

		switch(my_selection)
		{
			// user selects 1 or 2
			case 1 ... 2:
				// education is never wasted
				cout << "DNA is a self-replicating material that is present in nearly all living organisms\n";
				cout << "as the main constituent of chromosomes. It is the carrier of genetic information.\n";
				cout << "A, C, G, and T are the 'letters' of the DNA code; they stand for the chemicals\n";
				cout << "adenine (A), cytosine (C), guanine (G), and thymine (T), respectively, that make up\n";
				cout << "the nucleotide bases of DNA.\n\n";

				// get user input
				cout << "Enter a string of letters to denote DNA: ";
				cin >> my_dna;

				// convert to uppercase
				my_dna=convert_to_uppercase(my_dna);

				// selection is 1
				if(my_selection == 1)
				{
					// remind user what they selected to do
					cout << "\nYou chose to get the GC Content.\n";

					// get gc content
					double retanswer;
					retanswer = get_gc_content(my_dna);

					// output answer to user
					cout << "The GC content of " << my_dna << " is " << retanswer << "%.\n\n";
				}
				else
				{
					// remind user what they selected to do
					cout << "You chose to get the DNA complement\n.";

					// get dna complement
					string retanswer;
					retanswer=get_dna_complement(my_dna);

					// output answer to user
					cout << "The DNA complement of " << my_dna << " is " << retanswer << ".\n\n";
				}

				// get run count
				run_count++;

				// ask if user would like to run again
				cout<<"Would you like to do this again? ";
				cin>>run_again;
				break;
			// user chooses to exit the program
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
			// user makes invalid selection
			default:
				cout << "You made an invalid selection: try again.\n";
				break;

		}// end switch
		
		// convert to lowercase
		run_again=convert_to_lowercase(run_again);

	}// end while

	// conditional check
	string str_tm, str_tm2;
	str_tm = (run_count == 1) ? "time" : "times";
	str_tm2 = (my_count == 1) ? "time" : "times";

	// number of useful runs/total runs
	cout << "\nYou used this program for fancy DNA things " << run_count << " " << str_tm << ".\n";
	cout << "This program was run a total of " << my_count << " " << str_tm2 << ".\n";

	// end of program statement
	cout << "\nThis program will now exit.  Goodbye.\n";
	return 0;
}