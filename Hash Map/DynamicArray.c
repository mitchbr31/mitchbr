#include "LinkedList.h"
#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

void initArray (size_t, struct dynamicArray *);
void appendArray (struct dynamicArray *, struct linkedList *);
void freeArray (struct dynamicArray *);


/* Initialize an empty array */
void
initArray (size_t max_length, struct dynamicArray *newArr)
{
    newArr->array = malloc(max_length * sizeof(struct linkedList*));
    newArr->max_length = max_length;
    newArr->length = 0;
}

/* Add elements to the array, reallocating as necessary */
void
appendArray (struct dynamicArray *arr, struct linkedList *value)
{
    if (arr->max_length == arr->length)
    {
        // Reallocate when the array is full
        struct dynamicArray newArr;
        initArray(arr->max_length * 2, &newArr);
        newArr.length = arr->length;
        for (int i = 0; i < arr->length; i++)
            // Move values into the new array
            newArr.array[i] = arr->array[i];
        *arr = newArr;
    }

    // Append the new value
    arr->array[arr->length] = value;
    arr->length++;
}

void
freeArray (struct dynamicArray *arr)
{
    for (int i = 0; i < arr->length; i++)
        freeList(arr->array[i]);
    free(arr->array);
}
