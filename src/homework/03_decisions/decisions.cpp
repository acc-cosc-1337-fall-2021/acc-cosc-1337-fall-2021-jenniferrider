//write include statement for decisions header
#include <decisions.h>
#include <stdio.h>

//Write code for function(s) code here
string get_letter_grade_using_if(int grade)
{
    // if function decision tree to get grade
    if (grade <= 100 && grade >= 90)
    {
        return "A";
    }
    else
    {
        if (grade <= 89 && grade >= 80)
        {
            return "B";
        }
        else
        {
            if (grade <= 79 && grade >= 70)
            {
                return "C";
            }
            else
            {
                if(grade <=69 && grade >= 60)
                {
                    return "D";
                }
                else
                {   
                    if(grade <=59 && grade >= 0)
                    {
                        return "F";
                    }
                    else
                    {
                        return "Invalid number.";
                    }
                }
            }
        }
    }
}

string get_letter_grade_using_switch(int grade)
{
    // switch function used to get grade
    switch(grade)
    {
        case 90 ... 100:
            return "A";
            break;
        case 80 ... 89:
            return "B";
            break;
        case 70 ... 79:
            return "C";
            break;
        case 60 ... 69:
            return "D";
            break;
        default:
            return "F";
    }
}