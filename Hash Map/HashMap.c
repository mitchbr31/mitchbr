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
initHashMap ( size_t max_length, struct hashMap *newMap)
{
    initArray(max_length, &newMap->buckets);
    newMap->capacity = max_length;
    newMap->size = 0;
}

/* Add a node into the hash map */
void
addHashNode (char *key, int value, struct hashMap *map)
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
containsHashNode (char *key, struct hashMap *map)
{
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    return containsNode(map->buckets.array[index], key);
}

/* Retrieve the value of a node given the key */
int
getNode (char *key, struct hashMap *map)
{
    // Find the index of the key
    int hash = hashFunction(key);
    int index = hash % map->capacity;

    // Make sure they key exists in the hash map
    int exists = containsNode(map->buckets.array[index], key);
    if (exists)
        return map->buckets.array[index]->value;
    else
        printf("Node does not exists\n");
        // Need to implement return value
}
