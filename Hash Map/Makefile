all: DynamicArray LinkedList main

DynamicArray: DynamicArray.c
	gcc -Wall -c -std=gnu99 DynamicArray.c

LinkedList: LinkedList.c
	gcc -Wall -c -std=gnu99 LinkedList.c

main: 
	gcc -o main DynamicArray.o LinkedList.o
