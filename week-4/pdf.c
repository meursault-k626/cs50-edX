#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("wrong input dumbass\n");
        return 1;
    }

    // first fopen arg is taken from input when executing the programme
    // r for read-only
    FILE *pdf = fopen(argv[1], "r");

    // to check how many byte to process as per project requirement
    //(check the first four bytes of a file to see if it's a pdf or nahh)
    uint8_t buffer[4];

    // signature of a pdf file
    uint8_t signature[] = {0x25, 0x50, 0x44, 0x46};

    fread(buffer, 1, 4, pdf);
    fclose(pdf);

    // use loop to compare the first four bytes of the file against pdf
    // signature

    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("PDF? Not!!!!!!!!\n");
            return 0;
        }
    }
    
    printf("WAWAWEEWAA IT'SA PDF!!! YAKSHEMASH\n");

}