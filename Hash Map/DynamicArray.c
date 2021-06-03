#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *array; // The array
    size_t max_length; // Maximum length of the currently allocated static array
    size_t length; // Current length of the array
};

struct array *createArray (size_t max_length, struct array *oldArr)
{
    /* Initialize an empty array */
    struct array *newArr = malloc(sizeof(struct array));
    newArr->array = malloc(max_length*sizeof(int)); // ONLY WORKS ON INTS
    newArr->max_length = max_length;
    newArr->length = 0;

    if (oldArr != NULL)
    {
        for (int i = 0; i == oldArr->length; i++)
        {
            newArr->array[i] = oldArr->array[i];
            newArr->length++;
        }
    }
    
    return newArr;
}

struct array *appendArray ()
{
    /* Add elements to the array, reallocating as necessary */
    return 0;
}

int
main () {
    struct array *arr1 = createArray(4, NULL);
    arr1->array[0] = 1;
    printf("%zu\n", arr1->length);
    return 0;
}
