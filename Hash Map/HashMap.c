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
    initArray(2, &newMap->buckets);
}

void addHashNode (size_t max_length, char *key, int value, struct hashMap *map)
{
    int hash = hashFunction(key);
    int index = hash % max_length;

    // Check if key exists

    // Add the node
    // Add a "Get at index" function?
    map->buckets; //= addNode(key, value, map->buckets[index]);
}
