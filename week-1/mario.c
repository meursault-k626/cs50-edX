#include <stdio.h>

int main(void)
{
    for (int row= 0; row < 3; row++)
    {
        for (int columnar = 0; columnar < 3; columnar ++)
        {
            //print one brick
            printf("#");
        }
        printf("\n");
    }
}