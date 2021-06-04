#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct dynamicArray
{
    int *array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};

void createArray (size_t max_length, struct dynamicArray *newArr);
void appendArray (struct dynamicArray *arr, int value);

#endif
