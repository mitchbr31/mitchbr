#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>

#ifndef HASH_MAP_H
#define HASH_MAP_H

struct hashMap
{
    struct linkedList   *buckets;
    size_t              capacity;
    size_t              size;
};

int hashFunction ( char *key);

#endif