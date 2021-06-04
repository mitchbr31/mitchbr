#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    struct dynamicArray arr;
    createArray(4, &arr);
    struct linkedList *head1 = malloc(sizeof(struct linkedList));
    head1 = addNode("a1key", 1, head1);
    appendArray(&arr, head1);

    printf("%s\n", arr.array[0]->key);

    return 0;
}
