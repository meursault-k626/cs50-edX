#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    // input string to search
    string s = get_string("String: ");

    for (int i = 0; i < 6; i++)
    {
        // == won't work because a string variable only stores the starting 
        // memory address (pointer) of the text, not the actual word.
        // == can compare those addresses, but it has no idea what's actually
        // in it.

        // if (strings[i] == s)
        // {
        //     printf("Found\n");
        //     return 0;
        // }

        // use strcmp (string compare) to get into that address, and properly
        // compare what's in it.
        // compare the actual characters inside.
        // strcmp returns an integer in three forms:
        //  0 if the strings are identical (success)
        // <0 (negative) if the first string comes before the second (asciibetically)
        // >0 (positive) if the first string comes after the second (asciibetically)

        if (strcmp(strings[i], s) == 0)
        {
             printf("Found\n");
            return 0;           
        }
    }

    printf("Not found\n");
    return 1;
}