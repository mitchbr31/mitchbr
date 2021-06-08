#include "HashMap.h"
#include "DynamicArray.h"
#include "LinkedList.h"

#include <stdlib.h>
#include <stdio.h>

void
TestLinkedList ()
{
    printf("------------------\nBegin Linked List Tests:\n");
    // Initialize list and add some nodes
    struct linkedList *head1 = malloc(sizeof(struct linkedList));
    head1 = addNode("a1key", 1, head1);
    struct linkedList *tail1 = addNode("a2key", 2, head1);
    tail1 = addNode("a3key", 3, head1);
    tail1 = addNode("a4key", 4, head1);

    // Print list contents
    printf("------------------\nInitial List Contents:\n");
    struct linkedList *currNode = head1;
    while (currNode != NULL)
    {
        printf("%s\n", currNode->key);
        currNode = currNode->next;
    }

    // Remove a Node
    printf("------------------\nRemove a3key:\n");
    removeNode(head1, "a3key");
    currNode = head1;
    while (currNode != NULL)
    {
        printf("%s\n", currNode->key);
        currNode = currNode->next;
    }

    // Test contains with true and false tests
    printf("------------------\nContains a1key:\n");
    int key1 = containsNode(head1, "a1key");
    printf("Contains value: %d\n", key1);

    printf("------------------\nDoes not contain a3key:\n");
    key1 = containsNode(head1, "a3key");
    printf("Does not contain value: %d\n", key1);

    // Test length
    printf("------------------\nTest length:\n");
    int len = listLength(head1);
    printf("Length of the list: %d\n", len);

    printf("Conclude Linked List Tests\n------------------\n");
}

void
TestDynamicArray ()
{
    printf("------------------\nBegin Dynamic Array Tests:\n");
    // Set up an array of size 2
    struct dynamicArray arr;
    initArray(2, &arr);

    printf("------------------\nTest List Length Reallocation:\n");
    printf("%zu, %zu\n", arr.length, arr.max_length);

    struct linkedList *head1 = malloc(sizeof(struct linkedList));
    head1 = addNode("a1key", 1, head1);
    appendArray(&arr, head1);

    struct linkedList *head2 = malloc(sizeof(struct linkedList));
    head2 = addNode("a2key", 2, head2);
    appendArray(&arr, head2);

    printf("%zu, %zu\n", arr.length, arr.max_length);    
    
    struct linkedList *head3 = malloc(sizeof(struct linkedList));
    head3 = addNode("a3key", 3, head3);
    appendArray(&arr, head3);

    printf("%zu, %zu\n", arr.length, arr.max_length);

    printf("------------------\nTest Add at Index:\n");
    struct linkedList *head4 = malloc(sizeof(struct linkedList));
    head4 = addNode("a1key", 1, head4);
    addAtIndex(&arr, head4, 3);

    printf("%zu, %zu\n", arr.length, arr.max_length);

    printf("Conclude Dynamic Array Tests\n------------------\n\n");

    freeArray(&arr);
}

void
TestHashMap ()
{
    printf("------------------\nBegin Hash Map Tests:\n");
    struct hashMap map1;
    initHashMap(2, &map1);

    printf("------------------\nAdd a node:\n");
    addHashNode( map1.capacity, "a1key", 1, &map1);
}

int
main ()
{
    //TestLinkedList();
    TestDynamicArray();
    TestHashMap();

    return 0;
}
