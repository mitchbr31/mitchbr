#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    struct linkedList *head = NULL;
    struct linkedList *tail = NULL;
    struct dynamicArray arr1;
    createArray(4, &arr1);
    appendArray(&arr1, 1);
    struct dynamicArray arr2;
    createArray(4, &arr2);
    appendArray(&arr2, 2);
    struct dynamicArray arr3;
    createArray(4, &arr3);
    appendArray(&arr3, 3);
    struct dynamicArray arr4;
    createArray(4, &arr4);
    appendArray(&arr4, 4);

    head = addNode("a", &arr1, head);
    tail = addNode("b", &arr2, head);
    tail = addNode("c", &arr3, head);
    tail = addNode("d", &arr4, head);

    struct linkedList *currNode = head;
    while (currNode != NULL)
    {
        printf("%s, %d\n", currNode->key, currNode->value->array[0]);
        currNode = currNode->next;
    }

    return 0;
}
