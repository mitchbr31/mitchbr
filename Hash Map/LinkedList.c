#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listNode
{
    char *key;
    int value;
    struct listNode *next;
};

struct linkedList
{
    size_t length;
    struct listNode *head;
    struct listNode *tail;
};

struct linkedList *initList ()
{
    struct linkedList *newList = malloc(sizeof(struct linkedList));
    newList->head = malloc(sizeof(struct listNode));
    newList->tail = malloc(sizeof(struct listNode));

    newList->head->next = newList->tail;

    return newList;
};


int main ()
{
    struct listNode *testNode = malloc(sizeof(struct listNode));

    struct linkedList *dict = initList();
}
