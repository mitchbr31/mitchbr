#include <stdio.h>
#include <stdlib.h>

struct dynamicArray
{
    int *array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};

struct dynamicArray *createArray (size_t max_length)
{
    /* Initialize an empty array */
    struct dynamicArray *newArr = malloc(sizeof(struct dynamicArray));
    newArr->array = malloc(max_length*sizeof(int)); // ONLY WORKS ON INTS
    newArr->max_length = max_length;
    newArr->length = 0;

    return newArr;
}

void appendArray (struct dynamicArray *arr, int value)
{
    /* Add elements to the array, reallocating as necessary */
    arr->array[arr->length] = value;
    arr->length++;
}

int
main () {
    struct dynamicArray *arr1;
    arr1 = createArray(4);
    appendArray(arr1, 1);
    printf("%d\n", arr1->array[0]);
    return 0;
}
