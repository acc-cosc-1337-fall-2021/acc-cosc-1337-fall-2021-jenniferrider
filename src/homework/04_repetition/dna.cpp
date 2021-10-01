//add include statements
#include<dna.h>

//add function(s) code here
int factorial(int num)
{
    int x=1;
    int numx;
    while(num > 0)
    {
        x = x * num;
        num = num - 1;
    }
    return x;
}

int gcd (int num1, int num2)
{
    int numx;
    while(num1 != num2)
    {
        if(num1 < num2)
        {
            numx = num1;
            num1 = num2;
            num2 = numx;
        }

        if(num2 < num1)
        {
            num1 = num1 - num2;
        }
    }
    return num1;
}