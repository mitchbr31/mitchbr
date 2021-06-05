#include "DynamicArray.h"
#include "LinkedList.h"


#include <stdlib.h>
#include <stdio.h>

int hashFunction ( char *key)
{
    int hash = 0;
    for (int i = 0; key[i] != 0; i++)
    {
        hash += key[i];
    }
    return hash;
}

int main ()
{
    int x = hashFunction("hello");
    printf("%d\n", x);
}