#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // assign raw name to s
    string s = get_string("Before: ");
    // print "After: "
    printf("After: ");
    // i is char index for str array s
    // if n determines the str length
    // i less than n continues until it his max index
    // increase index i by 1
    // loop to print each char uppered
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }
    printf("\n");
}