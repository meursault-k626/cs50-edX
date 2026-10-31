#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int number;
    struct node *next;
} node;

int CAP = 3;

int main(void)
{
    node *list = NULL;

    for (int i = 0; i < CAP; i++)
    {
        int x = get_int("Number: ");

        node *n = malloc(sizeof(node));

        if (n == NULL)
        {
            printf("Malloc failed :(\n");
            return 1;
        }

        n->number = x;
        n->next = list;

        list = n;
    }

    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%i\n", ptr->number);
    }

    // Go to the latest node
    node *ptr = list;

    // // Loop until the address is NULL
    // while (ptr != NULL)
    // {
    //     // Stash the current node
    //     node *tmp = ptr;

    //     // Take the address to the next node and move there
    //     ptr = ptr->next;

    //     // Nuke the stashed node
    //     free(tmp);
}
