#include <stdio.h>
#include <cs50.h>
#include <string.h>

// typedef: define a new type of..
// struct: a data structure
typedef struct
{
    // what makes up the new type 
    string name;
    string number;
} person; // the name of the new data type


int main(void)
{
    // create an array with the custom data type
    person people[3];

    // assign value based on the data type location
    people[0].name = "Kelly";
    people[0].number = "0000";

    people[1].name = "David";
    people[1].number = "0000";

    people[2].name = "Kelly";
    people[2].number = "0001";
    

    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        // (strcmp(string1, string2) == 0) means 1 and 2 are the same
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found: %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
}