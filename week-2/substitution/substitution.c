#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>


// establish prototype
void cipher_func(string cipher_key, string plaintext, char cipher_output[]);

// argc = the total count of arguments (words typed)
// argv[i] = the actual word/text at index 'i'; index 0 is always the filename
int main(int argc, string argv[])
{
    // check if command line arg contains exactly file name and an array of key
    if (argc !=2)
    {
        // throw error on how to do it properly
        printf("Enter cipher key after './substitution'\n");

        // return 1 to stop the programme
        return 1;
    }

    string cipher_key = argv[1];
    
    int key_length = strlen(cipher_key);

    // if key is included, check if it represents the whole alphabet
    if (key_length < 26 || key_length > 26)
    {
        // if not throw error message
        printf("Cipher key must contains exactly 26 alphabetical characters");

        // and return to stop the programme 
        return 1;
    } 
    else {

        // if it contains all 26,

        for (int i = 0; i < 26; i++)
        {    
            // make sure only alphabet is in using isalpha
            if (isalpha(cipher_key[i]) == 0)
            {
               printf("Cipher key must contains exactly 26 alphabetical characters");
               
               return 1;
            }
            
            // duplicate check using dual index
            for (int j = 0; j < 26; j++)
            {
                if (i != j && tolower(cipher_key[i]) == tolower(cipher_key[j]))
                {
                    printf("Duplicate detected. Return distinct alphabets as key\n");
                    return 1;
                }
            }

        }
    }

    // request text to encrypt
    string plaintext = get_string("plaintext: ");

    // create an array of char (NOT STRING!!!), with array length determined by the length of plaintext
    char cipher_output[strlen(plaintext)+1];
    
    cipher_func(cipher_key, plaintext, cipher_output);

    printf("ciphertext: %s\n", cipher_output);

    return 0;
       
} 
    
void cipher_func(string cipher_key, string plaintext, char cipher_output[])
{

    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            int plaintext_order = plaintext[i] - 65;

            cipher_output[i] = toupper(cipher_key[plaintext_order]); 

        } else if (islower(plaintext[i]))
        {
            int plaintext_order = plaintext[i] - 97;

            cipher_output[i] = tolower(cipher_key[plaintext_order]); 
        } 
        else 
        {
            cipher_output[i] = plaintext[i];
        }
    }

    cipher_output[strlen(plaintext)] = '\0';
}