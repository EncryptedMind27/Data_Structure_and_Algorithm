#ifndef FINAL_H
#define FINAL_H
#include <stdlib.h>
#include <stdio.h>
// ====== SLL ======
typedef int element;
// ======= SINGLY LINKED LIST =======
typedef struct snode{
	struct snode* next; 
	element data; 
}*SNODE;

typedef struct sll{
	int size;
	SNODE head;
}*SLL;

// ======= DOUBLY LINKED LIST =======
typedef struct dnode{
	struct dnode* next;
	struct dnode* prev;
	element data;
}*DNODE;

typedef struct dll{
	DNODE head;
	DNODE tail;
	int size;
}*DLL;

// ======= CLL Functions =======
typedef struct cnode{
	struct cnode* next;
	element data; 
}*CNODE; 

typedef struct cll{
	CNODE tail;
	int size;
}*CLL;

// ======= Stack =======
typedef struct stack{
	element* arr;
	int size, capacity;
} *STACK;

// ======= SLL Functions =======
SLL createSLL(); //
void addFirstSLL(SLL,element); //
void addLastSLL(SLL,element); //  
void insertAtSLL(SLL,element,int); //
void deleteFirstSLL(SLL); //
void deleteLastSLL(SLL); //
void deleteAtSLL(SLL,int); //
void displaySLL(SLL); //

// ======= DLL Functions =======
DLL createDLL(); //
void addFirstDLL(DLL,element); //
void addLastDLL(DLL,element); //
void insertAtDLL(DLL,element,int); //
void deleteFirstDLL(DLL); //
void deleteLastDLL(DLL); //
void deleteAtDLL(DLL,int); //
void displayDLL(DLL); // 

// ======= CLL Functions =======
CLL createCLL(); //
CNODE createNode(element); //
void addFirstCLL(CLL,element); //
void addLastCLL(CLL,element); // 
void insertAtCLL(CLL,element,int); //
void deleteFirstCLL(CLL); //
void deleteLastCLL(CLL); //
void deleteAtCLL(); //
void displayCLL(CLL); //

// ======= Stack Functions =======
STACK createSTACK(int);
int isFull(STACK);
int isEmpty(STACK);
void push(STACK,element);
void pop(STACK,element);
void displaySTACK(STACK);


#endif 