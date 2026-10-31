#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// int main(void)
// {
//     char *s = get_string("s: ");
//     char *t = s;

//     t[0] = toupper(t[0]);

//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

// s is defined as an address, not value, ergo the transformation carried 
// out in s will be carried over to t, since both vars refer to the same
// address


// maloc n stuff
# include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");
    char *t = malloc(strlen(s)+1);

    //  use i <= strlen(s)  instead of =
    //  to iterate copy paste null terminator as well
    for (int i = 0, n = strlen(s); i <= n; i++)
    {
        t[i] = s [i];

    }
    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    // free() to prevent memory leak
    free(t)
}