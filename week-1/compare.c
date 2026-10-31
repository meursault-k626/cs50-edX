#include <cs50.h>
#include <stdio.h>
   
int main(void)
{
    int x = get_int("What's X matey?");
    int y = get_int("What's Y matey?");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x == y)
    {
        printf("arrr it the same matey\n");
    }
    else
    {
        printf("x is larger than y\n");
    }
}