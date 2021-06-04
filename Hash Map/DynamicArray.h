#include <stdlib.h>

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

struct dynamicArray;
void createArray (size_t max_length, struct dynamicArray *newArr);
void appendArray (struct dynamicArray *arr, int value);

#endif
