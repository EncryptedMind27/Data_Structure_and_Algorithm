#include "header.h"

STACK createStack(int capacity){
	STACK stack = (STACK)malloc(sizeof(struct stack));
	if(stack == NULL){
		printf("Stack Allocation Failed!\n");
		exit(1);
	}
	stack->capacity = capacity;
	stack->size = 0;
	stack->arr = (int*)malloc(sizeof(int)*capacity);

	return stack;
}

void push(STACK stack, element data){
	if(!isFull(stack)){
		stack->arr[stack->size++] = data;
	} else {
		printf("Stack is Full!\n");
		return;
	}
};

void pop(STACK stack){
	if(!isEmpty(stack)){
		stack->arr[stack->size--] = 0;
	} else {
		printf("Stack is Empty\n");
		return;
	}
}

int isFull(STACK stack){
	return (stack->size == stack->capacity);
}

int isEmpty(STACK stack){
	return (stack->size == 0);
}

void display(STACK stack){
	printf("[%d]: ",stack->size);
	for(int i = 0; i < stack->size; i++){
		printf("%d ",stack->arr[i]);
	}
	printf("\n");
}

QUEUE createQueue(int capacity){
	QUEUE queue = (QUEUE)malloc(sizeof(struct queue));
	if(queue == NULL){
		printf("Queue Allocation Failed! \n");
		exit(1);
	}

	queue->capacity = capacity;
	queue->size = queue->back = queue->front = 0;
	queue->arr = (int*)malloc(sizeof(int)*capacity);
	return queue;
}

int isEmptyQ(QUEUE queue){
	return (queue->size == 0);
}

int isFullQ(QUEUE queue){
	return (queue->size == queue->capacity); 
}

void enqueue(QUEUE queue, int data){
	if(!isFullQ(queue)){
		queue->arr[queue->back] = data;
		queue->back = (queue->back+1) % queue->capacity;
		queue->size++;
	} else {
		printf("Queue is Full!\n");
	}
}

void dequeue(QUEUE queue){
	if(!isEmptyQ(queue)){
		queue->front = (queue->front+1) % queue->capacity;
		queue->size--;
	} else {
		printf("Queue is Empty!\n");
	}
}

void displayQ(QUEUE queue) {
    printf("[%d]: ", queue->size);

    int tempFront = queue->front; 
    int size = queue->size;

    while (size--) {
        printf("%d ", queue->arr[tempFront]);
        tempFront = (tempFront + 1) % queue->capacity;
    }
    printf("\n");
}

