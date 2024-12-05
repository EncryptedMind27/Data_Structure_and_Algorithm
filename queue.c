#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct _queue
{
	Element *arr;
	int size, capacity, front, rear;
} *QUEUE;

QUEUE createQueue(int);
void enqueue(QUEUE, Element);
void dequeue(QUEUE);
void displayQ(QUEUE);
int main()
{
	QUEUE q = createQueue(5);
	enqueue(q, 5);
	enqueue(q, 4);
	enqueue(q, 3);
	enqueue(q, 2);
	enqueue(q, 1);
	displayQ(q);

	dequeue(q);
	displayQ(q);

	return 0;
}
QUEUE createQueue(int capacity)
{
	QUEUE q = (QUEUE)malloc(sizeof(struct _queue));
	q->size = q->rear = q->front = 0;
	q->capacity = capacity;
	q->arr = (Element*)malloc(sizeof(Element) * q->capacity);

	return q;
}
void enqueue(QUEUE q, Element data)
{
	if(q->size < q->capacity)
	{
		q->arr[q->rear] = data;
		q->rear = (q->rear+1) % q->capacity;
		q->size++;
	}
	else
		printf("Full storage\n");	
}
void dequeue(QUEUE q)
{
	if(q->size < q->capacity)
	{
		printf("%d\n\n", q->arr[q->front]);
		q->front = (q->front + 1) % q->capacity;
		q->size--;
	}
}
void displayQ(QUEUE q)
{
	int size = q->size--;
	while(size--)
	{
		printf("%d->", q->arr[q->front]);
		q->front = (q->front + 1) % q->capacity;

	}
	printf("\n\n");
}
