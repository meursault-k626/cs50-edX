#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hash(char *word);

int main(void)
{
    char *word = get_string("Team: ");
    if (word[0] == ' ')
    {
        printf("Team name must start with a letter\n");
        return 2;
    }
    printf("Hash value: %i\n", hash(word));
}

int hash(char *word)
{
    if (word == NULL || strlen(word) == 0)
    {
        printf("Null value entered\n");
        return 2;
    }
    // word[n] is the equivalent of *(word + n)
    char c = word[0];

    if (isalpha(c))
    {
        c = toupper(c);
        return c - 'A';
    }
    return 2;
}