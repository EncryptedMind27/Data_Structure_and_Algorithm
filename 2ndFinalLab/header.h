#ifndef HEADER_H
#define HEADER_H
#include <stdlib.h>
#include <stdio.h>

typedef int element;
typedef struct stack {
	int* arr; 
	int capacity,size; 
} *STACK;


typedef struct queue {
	int* arr;
	int capacity,size,back,front;
} *QUEUE; 

QUEUE createQueue(int);
void enqueue(QUEUE,element);
void dequeue(QUEUE);
int getFront(QUEUE);
int isFullQ(QUEUE);
int isEmptyQ(QUEUE);
void displayQ(QUEUE);

STACK createStack(int); 
void push(STACK,element);
void pop(STACK);
int peek(STACK);
int isFull(STACK);
int isEmpty(STACK);
void display(STACK);

#endif 