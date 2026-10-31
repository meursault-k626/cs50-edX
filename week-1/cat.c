#include <stdio.h>
#include <cs50.h>

void meow(int times);

int main(void)
{
    int n = get_int("How many meowths? ");
    meow(n);
}

void meow(int times)
{
    for (int i=0; i <= times; i++)
    {
        printf("meow\n");
    }
}