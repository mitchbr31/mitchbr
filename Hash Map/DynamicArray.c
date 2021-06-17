#include "LinkedList.h"
#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

void initArray ( struct dynamicArray *, size_t);
struct linkedList *get (struct dynamicArray *, int);
void appendArray (struct dynamicArray *, struct linkedList *);
void addAtIndex (struct dynamicArray *, struct linkedList *, int);
void freeArray (struct dynamicArray *);


/* Initialize an empty array */
void
initArray (struct dynamicArray *newArr, size_t max_length)
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
        initArray(&newArr, arr->max_length * 2);
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

/* Insert a value into the array at a provided index */
void
addAtIndex (struct dynamicArray *arr, struct linkedList *value, int index)
{
    // Check the index is not outside the array length
    if (index > arr->max_length)
        printf("Index %d outside range of array\n", index);
    
    if (arr->array[index] == NULL)
    {
        // If this index has no nodes, create a new linked list and iterate the length
        arr->array[index] = value;
        arr->length++;
    }
    else
    {
        // Append the linked list if one exists at this index
        addNode(arr->array[index], value->key, value->value);
    }
}

/* Free the array and all linked lists within from memory */
void
freeArray (struct dynamicArray *arr)
{
    for (int i = 0; i < arr->length; i++)
        freeList(arr->array[i]);
    free(arr->array);
}
