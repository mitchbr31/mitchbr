#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Structure to set up linked list nodes */
struct linkedList
{
    char                *key;
    int                 value;
    struct linkedList   *next;
};

struct linkedList *addNode (char *key, int value, struct linkedList *head);
struct linkedList *traverseList (struct linkedList *currNode);

#endif
