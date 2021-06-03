#include <stdio.h>
#include <stdlib.h>

struct array
{
    int *array;
    size_t mem_size;
    size_t length;
};

struct array *createArray (size_t length)
{
    /* Initialize an empty array */
    struct array *newArr = malloc(length*sizeof(int)); // ONLY WORKS ON INTS
    return newArr;
}

struct array *appendArray (int *array, size_t mem_size, size_t length)
{
    /* Add elements to the array, reallocating as necessary */
    return 0;
}

int
main () {
    struct array *arr1 = createArray(4);
    return 0;
}
