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
    struct linkedList *tail1 = addNode("a2key", 2, head1);
    tail1 = addNode("a3key", 3, head1);
    tail1 = addNode("a4key", 4, head1);
    appendArray(&arr, head1);

    struct linkedList *currNode = arr.array[0];
    while (currNode != NULL)
    {
        printf("%s\n", currNode->key);
        currNode = currNode->next;
    }

    removeNode(head1, "a3key");
    currNode = arr.array[0];
    while (currNode != NULL)
    {
        printf("%s\n", currNode->key);
        currNode = currNode->next;
    }

    return 0;
}
