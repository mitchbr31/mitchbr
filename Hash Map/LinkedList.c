#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
struct linkedList *addNode (char *, int, struct linkedList *);
struct linkedList *traverseList (struct linkedList *);
void removeNode (struct linkedList *, char *);

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
        struct linkedList *tail = traverseList(head);
        tail->next = newNode;
    }

    return newNode;
};

struct linkedList
*traverseList (struct linkedList *currNode)
{
    while (currNode->next != NULL)
        currNode = currNode->next;
    return currNode;
}

void
removeNode (struct linkedList *head, char *key)
{
    while (strcmp(head->next->key, key))
    {
        head = head->next;
    }
    
    // Remove the node and free it from memory
    struct linkedList *tempNode = head->next;
    head->next = head->next->next;
    free(tempNode);
}
