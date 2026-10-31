#include <stdio.h>
#include <string.h>

// 1. We must define the 'person' struct first, so the queue knows what it is.
typedef struct {
    char name[50];
    int age;
} person;

const int CAPACITY = 50;

// 2. Now we define the 'queue' struct, which contains an array of 'person' structs.
typedef struct {
    person people[CAPACITY]; // Array to hold the person elements
    int size;                // Number of elements currently in the queue
} queue;

int main() {
    // Create an instance of our queue and initialize its size to 0
    queue myQueue;
    myQueue.size = 0;

    // Create a new person instance
    person Alice;
    strcpy(Alice.name, "Alice");
    Alice.age = 30;

    // Add Alice to the queue
    if (myQueue.size < CAPACITY) {
        myQueue.people[myQueue.size] = Alice; // Store Alice in the array at index 0
        myQueue.size++;                       // Increment size to 1
    }

    // Create and add another person
    person Bob;
    strcpy(Bob.name, "Bob");
    Bob.age = 25;

    if (myQueue.size < CAPACITY) {
        myQueue.people[myQueue.size] = Bob;   // Store Bob in the array at index 1
        myQueue.size++;                       // Increment size to 2
    }

    // Print the queue details
    printf("Queue size: %d\n", myQueue.size);
    for (int i = 0; i < myQueue.size; i++) {
        printf("Person %d: %s (%d years old)\n", i + 1, myQueue.people[i].name, myQueue.people[i].age);
    }

    return 0;
}