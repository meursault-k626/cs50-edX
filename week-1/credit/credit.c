#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    long number;
    int num_len;
    char num_temp[20];
    int i;
    int sum = 0;
    int position = 0;

    do
    {
        number = get_long("Number: ");
        sprintf(num_temp, "%ld", number);
        num_len = strlen(num_temp);
    } while (
        num_len != 13 && num_len != 15 && num_len != 16
    );

    int first = num_temp[0] - '0';
    int first_two = (num_temp[0] - '0') * 10 + (num_temp[1] - '0');

    while (number != 0)
    {
        i = number % 10;
        if (position % 2 == 1)
        {
            i *= 2;
            if (i > 9)
            {
                i -= 9;
            }
        }
        sum += i;
        position++;
        number = number / 10;
    }

    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (num_len == 15 && (first_two == 34 || first_two == 37))
    {
        printf("AMEX\n");
    }
    else if (num_len == 16 && first_two >= 51 && first_two <= 55)
    {
        printf("MASTERCARD\n");
    }
    else if ((num_len == 13 || num_len == 16) && first == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}