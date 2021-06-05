all: DynamicArray LinkedList test TestApp

DynamicArray: DynamicArray.c
	gcc -Wall -c -std=gnu99 DynamicArray.c

LinkedList: LinkedList.c
	gcc -Wall -c -std=gnu99 LinkedList.c

test: TestScript.c
	gcc -Wall -c -std=gnu99 TestScript.c

TestApp: DynamicArray.o LinkedList.o TestScript.o
	gcc -o TestApp DynamicArray.o LinkedList.o TestScript.o
