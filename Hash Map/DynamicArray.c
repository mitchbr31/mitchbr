#include "LinkedList.h"
#include "DynamicArray.h"

#include <stdio.h>
#include <stdlib.h>

/*
struct dynamicArray
{
    int *array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};
*/

/* Initialize an empty array */
void createArray (size_t max_length, struct dynamicArray *newArr)
{
    newArr->array = malloc(max_length * sizeof(struct linkedList*));
    newArr->max_length = max_length;
    newArr->length = 0;
}

/* Add elements to the array, reallocating as necessary */
void appendArray (struct dynamicArray *arr, struct linkedList *value)
{
    if (arr->max_length == arr->length)
    {
        // Reallocate when the array is full
        struct dynamicArray newArr;
        createArray(arr->max_length * 2, &newArr);
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
