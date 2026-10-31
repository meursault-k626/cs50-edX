#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    
    draw(height);    
}

void draw(int n)
{
    // establish the base of pyramid
    if (n <= 0)
    {
        return;
    }

    // print a pyramid of height n -1
    draw(n - 1);
    
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    
    printf("\n");
}