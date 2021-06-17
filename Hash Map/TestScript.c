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
    head1 = addNode(head1, "a1key", 1);
    struct linkedList *tail1 = addNode(head1, "a2key", 2);
    tail1 = addNode(head1, "a3key", 3);
    tail1 = addNode(head1, "a4key", 4);

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
    removeNode(&head1, "a3key");
    currNode = head1;
    while (currNode != NULL)
    {
        printf("%s\n", currNode->key);
        currNode = currNode->next;
    }
    removeNode(&head1, "a1key");
    printf("Remove the head:\n");
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
    //freeList(head1);
}

void
TestDynamicArray ()
{
    printf("------------------\nBegin Dynamic Array Tests:\n");
    // Set up an array of size 2
    struct dynamicArray arr;
    initArray(&arr, 8);

    printf("------------------\nTest List Length Reallocation:\n");
    printf("%zu, %zu\n", arr.length, arr.max_length);

    for (int i = 0; i < 8; i++)
    {
        struct linkedList *head1 = malloc(sizeof(struct linkedList));
        head1 = addNode(head1, "a1key", 1);
        appendArray(&arr, head1);
    }

    struct linkedList *head2 = malloc(sizeof(struct linkedList));
    head2 = addNode(head2, "a2key", 2);
    appendArray(&arr, head2);

    printf("%zu, %zu\n", arr.length, arr.max_length);    
    
    struct linkedList *head3 = malloc(sizeof(struct linkedList));
    head3 = addNode(head3, "a3key", 3);
    appendArray(&arr, head3);

    printf("%zu, %zu\n", arr.length, arr.max_length);

    printf("------------------\nTest Add at Index:\n");
    struct linkedList *head4 = malloc(sizeof(struct linkedList));
    head4 = addNode(head4, "a1key", 1);
    addAtIndex(&arr, head4, 3);

    printf("%zu, %zu\n", arr.length, arr.max_length);

    printf("------------------\nRemoving a LL Node:\n");
    removeNode(&arr.array[0], "a1key");
    printf("%d\n", containsNode(arr.array[0], "a1key"));

    printf("Conclude Dynamic Array Tests\n------------------\n\n");

    freeArray(&arr);
}

void
TestHashMap ()
{
    printf("------------------\nBegin Hash Map Tests:\n");
    struct hashMap map1;
    initHashMap(&map1, 20);

    printf("------------------\nAdd a node:\n");
    char *testKey = "a1key";
    addHashNode(&map1, testKey, 5);
    int newHash = hashFunction(testKey);
    int newI = newHash % map1.capacity;
    printf("added node key: %s, node index: %d\n", map1.buckets.array[newI]->key, newI);
    char *key2 = "a2key";
    addHashNode(&map1, key2, 3);

    printf("------------------\nCheck if hash contains key:\n");
    int containsKey = containsHashNode(&map1, testKey);
    printf("Should print 1: %d\n", containsKey);

    printf("------------------\nCheck if hash contains additional key on one linked list:\n");
    /*addHashNode(&map1, "keya1", 7);
    containsKey = containsHashNode(&map1, "keya1");
    printf("Should print 1: %d\n", containsKey);
*/
    containsKey = containsHashNode(&map1, "badKey");
    printf("Should print 0: %d\n", containsKey);

    printf("------------------\nRetrieve a node value:\n");
    int retVal = getHashNode(&map1, testKey);
    printf("Get node got: %d\n", retVal);

    printf("------------------\nRemove a node :\n");
    containsKey = containsHashNode(&map1, key2);
    printf("Should print 1: %d\n", containsKey);
    removeHashNode(&map1, key2);
    containsKey = containsHashNode(&map1, key2);
    printf("Should print 0: %d\n", containsKey);

}

int
main ()
{
    //TestLinkedList();
    //TestDynamicArray();
    TestHashMap();

    return 0;
}
