#include <stdio.h>
#include <cs50.h>
#include <string.h>

// ask name to return num
int main(void)
{
    string names[] = {"Kelly", "David", "John"};
    string numbers[] = {"0000", "0000", "0001"};

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // (strcmp(string1, string2) == 0) means 1 and 2 are the same
        if (strcmp(names[i], name) == 0)
        {
            printf("Found: %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
}