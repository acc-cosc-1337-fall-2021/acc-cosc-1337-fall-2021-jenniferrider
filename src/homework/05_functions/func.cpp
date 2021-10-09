//add include statements
#include<func.h>

// namespace
using std::string; using std::toupper;

//add function code here
string convert_to_uppercase(string dna)
{
    int i;
    int strleg;
    string letr = "";

    // initialize variables
    letr = "";

    // get string length
    strleg = dna.length();

    // change to uppercase
    for(i=0;i<strleg;i++)
    {
        dna[i] = toupper(dna[i]);
    }

    //return
    return dna;
}

double get_gc_content(const string& dna)
{
    // variables
    int i;
    int strleg;
    int cnt;
    double retval;
    string letr;

    // initialize
    cnt = 0;

    // get length of string
    strleg = dna.length();

    // count with loop
    for (i = 0; i < strleg; i++)
    {
        letr = dna[i];
        if(letr == "C" || letr == "G")
        {
            cnt=cnt+1;
        }
    }

    // divide count by length to get percentage
    retval = static_cast<double>(cnt)/strleg;

    // get percentage
    return retval;
}

string get_reverse_string(string dna)
{
    // variables
    int i;
    int strleg;
    string letr;
    string revdna;

    //initialize variables
    revdna = "";

    // get length of string
    strleg = dna.length();

    // reverse string
    for(i = strleg-1;i>=0;i--)
    {
        revdna = revdna + dna[i];
    }

    // return
    return revdna;
}

string get_dna_complement(string dna)
{
    // variables
    int i;
    int strleg;
    string letr;
    string revdna;
    string intdna;

    // initialized variables
    letr = "";
    revdna = "";
    intdna = "";

    // get string length
    strleg = dna.length();

    // get reverse
    revdna = get_reverse_string(dna);

    // replace letters
    for(i=0;i<strleg;i++)
    {
        letr = revdna[i];
        if(letr == "A")
        {
            letr = "T";
        }
        else if(letr == "T")
        {
            letr = "A";
        }
        else if(letr == "C")
        {
            letr = "G";
        }
        else if(letr == "G")
        {
            letr = "C";
        }
        else
        {
            letr = letr;
        }

        // add letter to string
        intdna = intdna + letr;
    }

    // return
    return intdna;
}