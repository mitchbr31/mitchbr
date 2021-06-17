#include "HashMap.h"
#include "DynamicArray.h"
#include "LinkedList.h"


#include <stdlib.h>
#include <stdio.h>

/* Standard hash function
 * values are the sum of ASCII values from the chars in the key
 */
int
hashFunction ( char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != 0; i++)
    {
        // Sum up the ASCII values from the key chars
        hash += key[i];
    }
    return hash;
}

/* Initialize an empty has map */
void
initHashMap (struct hashMap *newMap, size_t max_length)
{
    initArray(&newMap->buckets, max_length);
    newMap->capacity = max_length;
    newMap->size = 0;
}

/* Add a node into the hash map */
void
addHashNode (struct hashMap *map, char *key, int value)
{
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    // Check if key exists

    // Add the node
    struct linkedList *head = malloc(sizeof(struct linkedList));
    head = addNode(head, key, value);
    addAtIndex(&map->buckets, head, index);
}

/* Check if a key exists in the hash map */
int
containsHashNode (struct hashMap *map, char *key)
{
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    return containsNode(map->buckets.array[index], key);
}

/* Retrieve the value of a node given the key */
int
getHashNode (struct hashMap *map, char *key)
{
    // Find the index of the key
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    // Make sure they key exists in the hash map
    return getNode(map->buckets.array[index], key);
}

/* Remove a node from the hash map */
void
removeHashNode (struct hashMap *map, char *key)
{
    // Find the index of the key
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    // Make sure they key exists in the hash map
    int exists = containsNode(map->buckets.array[index], key);
    if (exists)
        removeNode(&map->buckets.array[index], key);
    else
        printf("Node does not exists\n");
        // Need to implement return value
}

void
dispHashMap(struct hashMap *map)
{
    for (int i = 0; i < map->capacity; i++)
    {
        if (map->buckets.array[i] != NULL)
        {
            dispList(map->buckets.array[i]);
        }
    }
}
