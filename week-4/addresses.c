#include <cs50.h>
#include <stdio.h>


// int main(void)
// {
//     int n = 50;
//     printf("%i\n", n);
// }


// print out address of the var
// int main(void)
// {
//     int n = 50;
//     printf("%p\n", &n);
// }

// use address to print out var instead of calling the var directly
int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%i\n", *p);
}