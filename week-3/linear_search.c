#include <cs50.h>
#include <stdio.h>


// main always in as it indicates exit status (1 for success, other num for failure)
int main(void)
{
    // no need to define how many elements in the array inside [] because
    // the curly braces already defines it
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};


    // asks input to get the number to search for from the array above
    int n = get_int("Number: ");

    // linear search using for loop
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");

            // tells machine that all's good can stop now 
            return 0;
        }

    }

    printf("Not found\n");
    return 1;
}