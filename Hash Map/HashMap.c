#include "HashMap.h"
#include "DynamicArray.h"
#include "LinkedList.h"


#include <stdlib.h>
#include <stdio.h>

int
hashFunction ( char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != 0; i++)
    {
        hash += key[i];
    }
    return hash;
}

void
initHashMap ( size_t max_length, struct hashMap *newMap)
{
    initArray(max_length, &newMap->buckets);
    newMap->capacity = max_length;
    newMap->size = 0;
}

void
addHashNode (char *key, int value, struct hashMap *map)
{
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    // Check if key exists

    // Add the node
    struct linkedList *head = malloc(sizeof(struct linkedList));
    head = addNode(key, value, head);
    addAtIndex(&map->buckets, head, index);
}

int
containsHashNode (char *key, struct hashMap *map)
{
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    return containsNode(map->buckets.array[index], key);
}
