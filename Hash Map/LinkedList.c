#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
struct linkedList *addNode (char *, int, struct linkedList *);
struct linkedList *traverseList (struct linkedList *);
void removeNode (struct linkedList *, char *);
int containsNode (struct linkedList *, char *);
int listLength (struct linkedList *);

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
        // Find the node with the matching key
        head = head->next;

    // Remove the node and free it from memory
    struct linkedList *tempNode = head->next;
    head->next = head->next->next;
    free(tempNode);
}

/* Look for a node with a provided key
 * returns:
 *    1 if node exits
 *    0 if node does not exist
 */
int
containsNode (struct linkedList *head, char *key)
{
    while (strcmp(head->key, key))
    {
        // Traverse the list until the node is found
        if (head->next == NULL)
            // If we reach the end of the list, return "False"
            return 0;
        else
            head = head->next;
    }
    // if the node is found, return "True"
    return 1;
}

int
listLength (struct linkedList *head)
{
    int length = 0;
    while (head != NULL)
    {
        head = head->next;
        length++;
    }
    return length;
}
