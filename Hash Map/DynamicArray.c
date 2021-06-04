#include <stdio.h>
#include <stdlib.h>

struct dynamicArray
{
    int *array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};

void createArray (size_t max_length, struct dynamicArray *newArr)
{
    /* Initialize an empty array */
    newArr->array = malloc(max_length * sizeof(int));
    newArr->max_length = max_length;
    newArr->length = 0;
}

void appendArray (struct dynamicArray *arr, int value)
{
    /* Add elements to the array, reallocating as necessary */
    arr->array[arr->length] = value;
    arr->length++;
}

int
main () {
    struct dynamicArray *arr1 = malloc(sizeof(struct dynamicArray));
    createArray(4, arr1);
    appendArray(arr1, 1);
    appendArray(arr1, 2);
    appendArray(arr1, 3);
    appendArray(arr1, 4);
    appendArray(arr1, 5);
    for (int i = 0; i < arr1->length; i++)
    {
        printf("%d\n", arr1->array[i]);
    }
    printf("%lu\n", sizeof(arr1->array));

    return 0;
}
