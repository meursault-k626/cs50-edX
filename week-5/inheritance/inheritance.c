// Simulate genetic inheritance of blood type
#define _DEFAULT_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
} person;

const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;

person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srandom(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person

    person *new_person = malloc(sizeof(person));

    // If there are still generations left to create
    if (generations > 1)
    {
        // Create two new parents for current person by recursively calling create_family
        person *parent0 = create_family(generations - 1);
        person *parent1 = create_family(generations - 1);

        // TODO: Set parent pointers for current person
        new_person->parents[0] = parent0;
        new_person->parents[1] = parent1;
        // TODO: Randomly assign current person's alleles based on the alleles of their parents
        new_person->alleles[0] = parent0->alleles[random() % 2];
        new_person->alleles[1] = parent1->alleles[random() % 2];
    }

    // If there are no generations left to create
    else
    {
        // TODO: Set parent pointers to NULL
        new_person->parents[0] = NULL;
        new_person->parents[1] = NULL;
        // TODO: Randomly assign alleles
        new_person->alleles[0] = random_allele();
        new_person->alleles[1] = random_allele();
    }

    // TODO: Return newly created person
    return new_person;
}

// ======================================================================
// [LEVEL 0] SHOHEI (p = Shohei, was malloc'd)
// ======================================================================
//   Line 1: if (p == NULL) -> FALSE (Shohei exists, keep going)
//   Line 2: free_family(p->parents[0]);
//           |
//           |  >>> DIG DOWN 1 LEVEL >>>
//           v
//   ====================================================================
//   [LEVEL 1] MOM (p = Mom, was malloc'd)
//   ====================================================================
//     Line 1: if (p == NULL) -> FALSE (Mom exists, keep going)
//     Line 2: free_family(p->parents[0]);
//             |
//             |  >>> DIG DOWN 1 LEVEL >>>
//             v
//     ==================================================================
//     [LEVEL 2] GRANDMA M (p = Grandma M, was malloc'd)
//     ==================================================================
//       Line 1: if (p == NULL) -> FALSE (Grandma exists, keep going)

//       Line 2: free_family(p->parents[0]); // Mom's Mom's Mom (NULL!)
//               |
//               |  >>> DIG DOWN >>> free_family(NULL)
//               |  - Great-Grandma was NEVER malloc'd (does not exist!)
//               |  - if (p == NULL) is TRUE!
//               |  - Hits 'return;' -> NEVER calls free()!
//               |  <<< RETURN: Stop digging, climb back up to Grandma!
//               v
//       Grandma resumes! Steps to Line 3:

//       Line 3: free_family(p->parents[1]); // Mom's Mom's Dad (NULL!)
//               |
//               |  >>> DIG DOWN >>> free_family(NULL)
//               |  - Great-Grandpa was NEVER malloc'd (does not exist!)
//               |  - if (p == NULL) is TRUE!
//               |  - Hits 'return;' -> NEVER calls free()!
//               |  <<< RETURN: Stop digging, climb back up to Grandma!
//               v
//       Grandma resumes! Both parent calls returned without freeing.
//       Now Grandma frees herself!
//       Line 4: free(p);  <=== [1st REAL FREE: Grandma M released!]
//     ==================================================================
//             |
//             |  <<< RETURN: Stop digging, climb back up to Mom!
//             v
//   Mom resumes! (Mom's Line 2 is done, steps to Line 3)
//   Line 3: free_family(p->parents[1]);
//           - Digs down to Grandpa M (Level 2)
//           - Grandpa's parents are NULL (never malloc'd -> no free!)
//           - free(Grandpa M)  <=== [2nd REAL FREE: Grandpa M released!]
//           - <<< RETURN: Stop digging, climb back up to Mom!
//   Line 4: free(p);           <=== [3rd REAL FREE: Mom released!]
//   ====================================================================
//           |
//           |  <<< RETURN: Stop digging, climb back up to Shohei!
//           v
// Shohei resumes! (Shohei's Line 2 is done, steps to Line 3)
// Line 3: free_family(p->parents[1]);
//         |
//         |  >>> DIG DOWN 1 LEVEL >>> (Dad's branch)
//         v
//         - Dad digs down to Grandma D & Grandpa D (Level 2)
//         - Their parents are NULL (never malloc'd -> no free!)
//         - Grandma D & Grandpa D free themselves [4th & 5th REAL FREE]
//         - Dad frees himself                     [6th REAL FREE]
//         - <<< RETURN: Stop digging, climb back up to Shohei!
//         v
// Shohei resumes! (Shohei's Line 3 is done, steps to Line 4)
// Line 4: Both Mom & Dad are gone. Shohei is LAST MAN STANDING.
//         free(p);             <=== [7th REAL FREE: Shohei released!]
// ======================================================================

void free_family(person *p)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Free parents recursively
    free_family(p->parents[0]);
    free_family(p->parents[1]);

    // Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    if (generation == 0)
    {
        printf("Child (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else if (generation == 1)
    {
        printf("Parent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }
    else
    {
        for (int i = 0; i < generation - 2; i++)
        {
            printf("Great-");
        }
        printf("Grandparent (Generation %i): blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    }

    // Print parents of current generation
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = random() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
