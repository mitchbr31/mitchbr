#include "LinkedList.h"

#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct dynamicArray
{
    struct linkedList **array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};

void initArray (struct dynamicArray *newArr, size_t max_length);
void appendArray (struct dynamicArray *arr, struct linkedList *value);
void addAtIndex (struct dynamicArray *arr, struct linkedList *value, int index);
void freeArray (struct dynamicArray *arr);

#endif
