#include "DynamicArray.h"

#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/* Structure to set up linked list nodes */
struct linkedList
{
    
    char                *key;
    struct dynamicArray *value;
    struct linkedList   *next;
};

struct linkedList *addNode (char *key, struct dynamicArray *value, struct linkedList *head);

#endif
