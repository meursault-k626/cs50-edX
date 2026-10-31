#include <stdio.h>
#include <cs50.h>


void bricks(int n)
{
    for ( int i=0; i < n; i++)
    {
        // print steps
        for (int j = 0; j < n - 1 -i; j++)
            printf(" ");
        // lay bricks
        for (int j=0; j < i + 1; j++)
            printf("#");
        printf("\n");

    }
}


int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    bricks(n);
}
