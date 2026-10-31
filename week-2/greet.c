#include <cs50.h>
#include <stdio.h>

// argc = argument count = number of argument used
// argv = index of argument (argument being an array)
int main(int argc, string argv[])
{
    //ifelse arg
    // if argument include filename and other input, up to 9 total
    if ( argc > 1 && argc < 9)
    {
        // On rowwise basis
        //print Hello
        printf("Hello, ");
        // use for loop to print every argument per index, quit up to 9 max arg
        // including invisible filename
        for(int i = 1; i < argc; i++)
        {
            printf("%s ", argv[i]);
        }
        // print line break
        printf("\n");
    }
    else
    {
        // if argc count ain't right
        printf("Hello, unknown user\n");
    }
}