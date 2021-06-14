#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>

#ifndef HASH_MAP_H
#define HASH_MAP_H

struct hashMap
{
    struct dynamicArray     buckets;
    size_t                  capacity;
    size_t                  size;
};

int hashFunction (char *key);
void initHashMap (struct hashMap *newMap, size_t max_length);
void addHashNode (struct hashMap *map, char *key, int value);
int containsHashNode (struct hashMap *map, char *key);
int getHashNode (struct hashMap *map, char *key);
void removeHashNode (struct hashMap *map, char *key);

#endif