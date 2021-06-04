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
    newArr->array = (int*) malloc(max_length * sizeof(int));
    newArr->max_length = max_length;
    newArr->length = 0;
}

void appendArray (struct dynamicArray *arr, int value)
{
    /* Add elements to the array, reallocating as necessary */
    if (arr->max_length == arr->length)
    {
        printf("reallocating\n");
        struct dynamicArray newArr;
        createArray(arr->max_length * 2, &newArr);
        newArr.length = arr->length;
        for (int i = 0; i < arr->length; i++)
            newArr.array[i] = arr->array[i];
        *arr = newArr;
    }

    arr->array[arr->length] = value;
    arr->length++;
}

int
main () {
    struct dynamicArray arr1;
    createArray(4, &arr1);
    appendArray(&arr1, 1);
    appendArray(&arr1, 2);
    appendArray(&arr1, 3);
    appendArray(&arr1, 4);
    appendArray(&arr1, 5);
    appendArray(&arr1, 6);

    for (int i = 0; i < arr1.length; i++)
    {
        printf("%d, %d\n", i, arr1.array[i]);
    }
    printf("%zu\n", arr1.max_length);

    return 0;
}
