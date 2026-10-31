#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

// define node-type for int-based linked list
// define node early for prototype
    typedef struct node
    {    // holds the actual data (in this case int)
        int number;
        // pointer to the next node in the linked list
        struct node *next;
    } node;

int main(void)
{
    // create the first block of the linked-list
    node *list = NULL;
    
    for (int i = 0; i < 3; i++)
    {
        // loop 3 times to create three nodes
        node *n = malloc(sizeof(node));

        // sanity check/exit ramp
        if (n==NULL)
        {
            return 1;
        }
        // goes inside the node
        // assign number by pulling inline args
        n->number = get_int("Number: ");
        // set pointer for next node to null
        n->next = NULL;

        // insert the node to the list

        // link new node to current head of list
        n->next = list;
        // make new node the new head
        list = n;

        // first iteration (num = 1):
        // list is NULL, so n->next = NULL
        // n->next = list;
        // list now points to node 1   
        // list = n;          

        // list
        //   |
        //   V
        //   +---+------+
        //   | 1 | NULL |
        //   +---+------+
        //   num   next


        // second iteration (num = 2):

        // n->next = list;    n->next grabs address of node 1
        // list = n;          list now points to node 2

        // list
        //   |
        //   v
        //   +---+------+    +---+------+
        //   | 2 |      |---→| 1 | NULL |
        //   +---+------+    +---+------+
        //   num   next       num   next
    }

    // Print numbers

    node *ptr = list;
    
    // use while cause it's more readable
    // since the final nodes' next val is NULL
    // while stops when it reaches that
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr ->next;
    }

    // for loop variant
    // for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    // {
    //     printf("%i\n", ptr->number);
    // }


    return 0;
}