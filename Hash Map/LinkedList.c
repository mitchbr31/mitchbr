#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure to set up linked list nodes */
struct linkedList
{
    
    char              *key;
    int               value;
    struct linkedList *next;
};

/* Adds nodes to the end of the linked list */
struct linkedList
*addNode (char *key, int value, struct linkedList *head)
{
    // Import the new data to a new node
    struct linkedList *newNode = malloc(sizeof(struct linkedList));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        // The list is empty, initialize the head with the new node
        head = newNode;
    }
    else
    {
        // The list has values, traverse to the end and add the new node
        struct linkedList *currNode = head;
        while (currNode->next != NULL)
        {
            currNode = currNode->next;
        }
        currNode->next = newNode;
    }

    return newNode;
};


int main ()
{
    struct linkedList *head = NULL;
    struct linkedList *tail = NULL;

    head = addNode("a", 1, head);
    tail = addNode("b", 2, head);
    tail = addNode("c", 3, head);
    tail = addNode("d", 4, head);


    struct linkedList *currNode = head;
    while (currNode->next != NULL)
    {
        printf("%s, %d\n", currNode->key, currNode->value);
        currNode = currNode->next;
    }
    printf("%s, %d\n", currNode->key, currNode->value);
    

    struct dynamicArray arr1;
    createArray(4, &arr1);
    appendArray(&arr1, 1);
    appendArray(&arr1, 2);
    appendArray(&arr1, 3);
    appendArray(&arr1, 4);
    appendArray(&arr1, 5);
    appendArray(&arr1, 6);

    for (int i = 0; i < arr1.length; i++)
    {
        printf("%d, %d\n", i, arr1.array[i]);
    }
    printf("%zu\n", arr1.max_length);

    return 0;
}
