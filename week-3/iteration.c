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
    // row-wise printing
    for (int i = 0; i < n; i++)
    {
        // column-wise printing
        //  j < i +1 because i starts from zero;
        // without + 1 it'll print zero brick
        // index shit
        for (int j= 0; j < i + 1; j++ )
        {
            printf("#");
        }

        printf("\n");
    }
}