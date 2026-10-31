#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int change;

    //request change
    do
    {
       change = get_int("Change owed: ");
    } 
    // ensure change is 1 or more
    while (change < 1);
    
    // get # of quarter to dispense
    int quarter = change / 25;
    change -= quarter* 25;
    
    // get # of dime to dispense 
    int dime = change / 10;
    change -= dime* 10;

    // get # of nickel to dispense
    int nickel = change / 5;
    change -= nickel*5;

    // get remaining balance in penny
    int penny = change;

    // sum total change to return
    printf("%i\n", quarter + dime + nickel + penny);
    
}