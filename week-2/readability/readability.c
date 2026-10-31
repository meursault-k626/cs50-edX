#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// prototypes
int count_letter(string text);
int count_word(string text);
int count_sent(string text);

int main(void)
{
    string text = get_string("Text: ");

    float letter_tally_main = count_letter(text);
    float word_tally_main = count_word(text);
    float sent_tally_main = count_sent(text);

    // ratio per 100 words
    float letter_per = letter_tally_main / word_tally_main * 100;
    float sent_per = sent_tally_main / word_tally_main * 100;

    // index calculation
    int col_liau_ind = round(0.0588 * letter_per - 0.296 * sent_per - 15.8);

    // output with three main outcomes
    if (col_liau_ind < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (col_liau_ind >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", col_liau_ind);
    }
    
}


int count_letter(string text)
{  
    float letter_tally = 0;

    for (int i = 0; i < strlen(text); i++)
    {

        if (isalpha(text[i]))
        {
            letter_tally++;
        }
    }

    // return float for in-main index calculation
    return letter_tally;

}

int count_word(string text)
{
    float word_tally = 1;


    // use isspace() to get the num of space
    for (int i = 0; i <strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            word_tally++;
        }

    }

    return word_tally;
}

int count_sent(string text)
{
    float sent_tally = 0;


    // use bitwise to calculate special chars indicating sentence count
    for (int i = 0; i <strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sent_tally++;
        }

    }

    return sent_tally;
}