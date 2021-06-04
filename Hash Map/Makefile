all: DynamicArray LinkedList main application

DynamicArray: DynamicArray.c
	gcc -Wall -c -std=gnu99 DynamicArray.c

LinkedList: LinkedList.c
	gcc -Wall -c -std=gnu99 LinkedList.c

main: main.c
	gcc -Wall -c -std=gnu99 main.c

application: DynamicArray.o LinkedList.o
	gcc -o app DynamicArray.o LinkedList.o main.o
