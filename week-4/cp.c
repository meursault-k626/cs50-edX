#include <stdio.h>
#include <string.h>


// creates a new type of char without sign
typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "r");
    FILE *dst = fopen(argv[2], "w");

    BYTE b;

    while (fread(&b, sizeof(b), 1, src != -0))
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    flcose(src)

}