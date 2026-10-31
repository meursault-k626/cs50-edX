#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string answer = get_string("What's your name? ");
    printf("Hello, %s,\nHow it's hanging \n", answer);
    string weather = get_string("What's the weather today, %s?", answer);
    if (strcmp(weather, "sunny") == 0 ||strcmp(weather, "Sunny") == 0)
        {
            printf("Ah, it's lovely day for sailing innit matey\n");
        }
    else if (strcmp(weather, "rainy")==0)
        {
            printf("Arrr 'tis not good day for sailing, %s\n", answer);
        }
    else
        {
            printf("I tell you what %s, I fancy summere more than %s\n", answer, weather);
        }
}