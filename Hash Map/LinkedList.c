#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Adds nodes to the end of the linked list */
struct linkedList
*addNode (char *key, struct dynamicArray *value, struct linkedList *head)
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
