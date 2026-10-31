#include <stdio.h>
#include <stdlib.h>

// Static memory allocation (Hardcoded, permanent)
// int main(void)
// {
//     int list[3];

//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;

//     for (int i = 0; i < 3; i++)
//     {
//         printf("%i\n",list[i]);
//     }
// }


// dynamic memory allocation with malloc

int main(void)
{
    // use pointer to allocate memory for 3 int
    // pointer points to the first element only
    int *list = malloc(3 * sizeof(int));

    // failsafe, exit if there are no memory left to assign
    if (list == NULL)
    {
        return 1;
    }

    // w/ syntactic sugar
    // use bracket notation to assign each int
    // compiler rewrites list[i] to *(list + i)
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // w/o them sugar; hardcoded
    // same assignments using raw pointer arithmetic
    // offset address by i * sizeof(int) then dereference
    // *list = 1;
    // *(list + 1) = 2;
    // *(list + 2) = 3;

    // what if array size expands?

    // poor move
    // list = malloc(4 * sizeof(int));

    // will cause memory leak:
    // malloc 4 gives list a new address
    // the old 3-int block still exists in memory
    // but the programme lost track of its address
    // it can't use it or free it, but is still charged for it
    // "leak" = memory that seeps out of the programme's control
    
    // use tmp instead to assign new malloc
    // free malloc 3 as well
    // int *tmp = malloc(4 * sizeof(int));
    // if (tmp == NULL)
    // {
    //     free(list);
    //     return 1;
    // }

    // // copy old list onto new
    // for (int i = 0; i < 4; i++)
    // {
    //     tmp[i] = list[i];
    // }

    // skip the extra steps and use realloc
    // realloc args (current memory to realloc, size)
    // realloc tries to expand the block in place
    // if the bytes right after malloc 3 are free, it just extends
    // if something else occupies that space, realloc:
    //   1. allocates a new block elsewhere big enough for 4 ints
    //   2. copies the old data (1, 2, 3) into it
    //   3. frees the old block
    //   4. returns the new address
    // that's why we use tmp — if realloc fails it returns NULL
    // but the old block is still intact, so we can free it safely
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // realloc handled the old block already
    // just reassign list to tmp
    list = tmp;
    list[3] = 4;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n",list[i]);
    }

    // free before exit
    free(list);

    // terminate programme
    return 0;
}