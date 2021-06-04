#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

int main ()
{
    struct linkedList *head = NULL;
    struct linkedList *tail = NULL;

    head = addNode("a", 1, head);
    tail = addNode("b", 2, head);
    tail = addNode("c", 3, head);
    tail = addNode("d", 4, head);


    struct linkedList *currNode = head;
    while (currNode->next != NULL)
    {
        printf("%s, %d\n", currNode->key, currNode->value);
        currNode = currNode->next;
    }
    printf("%s, %d\n", currNode->key, currNode->value);
    

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
