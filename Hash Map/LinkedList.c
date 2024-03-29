#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function prototypes */
struct linkedList *addNode (struct linkedList *, char *, int);
struct linkedList *traverseList (struct linkedList *);
int getNode (struct linkedList *, char *);
void removeNode (struct linkedList **, char *);
int containsNode (struct linkedList *, char *);
int listLength (struct linkedList *);
void dispList(struct linkedList *);
void freeList (struct linkedList *);

/* Adds nodes to the end of the linked list */
struct linkedList
*addNode (struct linkedList *head, char *key, int value)
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

/* Grab the node at the end of the linked list */
struct linkedList
*traverseList (struct linkedList *currNode)
{
    while (currNode->next != NULL)
        currNode = currNode->next;
    return currNode;
}

/* Retrieve the value of a node given the key */
int
getNode (struct linkedList *head, char *key)
{
    while (head != NULL)
    {
        // Iterate until the key or end of the list is found
        if (strcmp(head->key, key) == 0)
            return head->value;

        head = head->next;
    }

    // Return -1 if the end of the list is reached
    return -1;
}

/* Remove a node from the linked list given a key */
void
removeNode (struct linkedList **head, char *key)
{
    struct linkedList *tempNode = *head;

    if (tempNode != NULL && strcmp(tempNode->key, key) == 0)
    {
        // The head is to be removed
        *head = tempNode->next;
        //free(tempNode);
        return;
    }
    
    while (tempNode->next->key != key)
        // Find the node with the matching key
        tempNode = tempNode->next;

    //tempNode = tempNode->next;

    // Remove the node and free it from memory
    tempNode->next = tempNode->next->next;
    
    //free(tempNode);
}

/* Look for a node with a provided key
 * returns:
 *    1 if node exits
 *    0 if node does not exist
 */
int
containsNode (struct linkedList *head, char *key)
{
    while (head != NULL && strcmp(head->key, key) != 0)
    {
        head = head->next;
    }

    if (head == NULL)
        // The node was not found, return "False"
        return 0;
    else
        // The node was found, return "True"
        return 1;
}

/* Find the number of nodes in the linked list */
int
listLength (struct linkedList *head)
{
    int length = 0;
    while (head != NULL)
    {
        // Travers through the nodes, incrementing length with each node
        head = head->next;
        length++;
    }
    return length;
}

/* Print the contents of the linked list */
void
dispList(struct linkedList *head)
{
    printf("{ ");
    while (head->next != NULL)
    {
        printf("'%s': %d, ", head->key, head->value);
        head = head->next;
    }
    printf("'%s': %d }\n", head->key, head->value);
}

/* Free the linked list from memory */
void
freeList (struct linkedList *head)
{
    while (head != NULL)
    {
        struct linkedList *tempNext = head->next;
        free(head);
        head = tempNext;
    }
}
