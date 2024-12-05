#include "header.h"

SLL createSLL(){
	SLL list = (SLL)malloc(sizeof(struct sll));
	list->size = 0;
	list->head = NULL;

	return list;
}

void addFirstSLL(SLL list, element data){
	SNODE node = (SNODE)malloc(sizeof(struct snode));
	node->data = data;
	node->next = list->head;
	list->head = node;
	list->size++;
}

void addLastSLL(SLL list, element data){
	SNODE node = (SNODE)malloc(sizeof(struct snode));
	node->data = data;
	node->next = NULL;
	if(list->head == NULL){
		list->head = node;
	} else {
		SNODE current = list->head;
		while(current->next != NULL)
			current = current->next;

		current->next = node;
	}
	list->size++; 
}

void insertAtSLL(SLL list,element data, int position){
	if(position == 1){
		addFirstSLL(list,data);
	} else if(position > list->size){
		addLastSLL(list,data);
	} else {
		SNODE node = (SNODE)malloc(sizeof(struct snode));
		node->data = data;

		SNODE current = list->head;
		position -= 1;
		while(--position)
			current = current->next;

		node->next = current->next;
		current->next = node;
		list->size++;
	}
}

void deleteFirstSLL(SLL list){
	SNODE del = list->head;
	list->head = list->head->next;
	free(del);
	del = NULL;
	list->size--;
}

void deleteLastSLL(SLL list){
	SNODE current = list->head;
	while(current->next->next!=NULL)
		current = current->next;

	SNODE del = current->next;
	current->next = NULL;
	list->size--; 
	free(del);
	del = NULL;	
}

void deleteAtSLL(SLL list, int position){
	if(position == 1){
		deleteFirstSLL(list);
	} else if(position == list->size){
		deleteLastSLL(list);
	} else {
		SNODE current = list->head;
        for (int i = 1; i < position - 1; i++)
            current = current->next;

        SNODE del = current->next;
        current->next = del->next;

        free(del);
        del = NULL;
        list->size--;
	} 
}

void displaySLL(SLL list){
	SNODE current = list->head;
	printf("[%d]: ",list->size);
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

DLL createDLL(){
	DLL list = (DLL)malloc(sizeof(struct dll));
	list->head = NULL;
	list->tail = NULL; 
	list->size = 0; 
	return list;
}	

void addFirstDLL(DLL list, element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode)); 
	node->data = data;
	node->prev = NULL;
	if(list->size == 0){
		list->head = list->tail = node;
		node->next = NULL;
	} else {
		node->next = list->head;
		list->head->prev = node;
		list->head = node;
	}
	list->size++;
}

void addLastDLL(DLL list,element data){
	DNODE node = (DNODE)malloc(sizeof(struct dnode));
	node->data = data;
	node->next = NULL;

	if(list->size == 0){
		list->head = list->tail = node;
		node->prev = NULL;
	}else{
		node->prev = list->tail;
		list->tail->next = node;
		list->tail = node; 
	}
	list->size++;
}

void insertAtDLL(DLL list,element data, int position){
	if(position == 1){
		addFirstDLL(list,data);
	} else if(position > list->size){
		addLastDLL(list,data); 
	} else {
		position -= 1;
		DNODE node = (DNODE)malloc(sizeof(struct dnode));
		DNODE current = list->head;
		while(--position)
			current = current->next;
		
		node->data = data; 
		node->prev = current;
		node->next = current->next;

	 	current->next->prev = node;
	 	current->next = node;
	 	list->size++;
	}
}

void deleteFirstDLL(DLL list){ 
	DNODE del = list->head;
	list->head = del->next; 
	list->head->prev = NULL;
	list->size--;
	free(del);
	del = NULL;
}

void deleteLastDLL(DLL list){
	DNODE del = list->tail;
	list->tail = del->prev;
	list->tail->next = NULL;
	list->size--;
	free(del); 
	del = NULL;
}

void deleteAtDLL(DLL list,int position){
	if(position == 1){
		deleteFirstDLL(list);
	} else if(position == list->size){
		deleteLastDLL(list); 
	} else {
		position -= 1;
		DNODE current = list->head; 
		while(--position)
			current = current->next; 

		DNODE del = current->next;
		del->next->prev = current;
		current->next = del->next;
		list->size--;
	}
}

void displayDLL(DLL list){
	DNODE current = list->head;
	printf("[%d]: ",list->size);
	while(current != NULL){
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

CLL createCLL()
{
	CLL list = (CLL)malloc(sizeof(struct cll));
	list->tail = NULL;
	list->size = 0;

	return list;
}
CNODE createNode(element data)
{
	CNODE node = (CNODE)malloc(sizeof(struct cnode));
	node->next = NULL;
	node->data = data;

	return node;
}
void addFirstCLL(CLL list, element data)
{
	CNODE node = createNode(data);
	if(list->tail == NULL)
	{
		list->tail = node;
		node->next = list->tail;
	}
	else
	{
		node->next = list->tail->next;
		list->tail->next = node;
	}
	list->size++;
}
void addLastCLL(CLL list, element data)
{
	CNODE node = createNode(data);
	if(list->tail == NULL)
	{
		list->tail = node;
		node->next = list->tail;
	}
	else
	{
		node->next = list->tail->next;
		list->tail->next = node;
		list->tail = node;
	}
	list->size++;
}
void insertAtCLL(CLL list, element data, int position)
{
	if(list->tail != NULL)
	{
		if(position == 1)
			addFirstCLL(list, data);
		else if(position == list->size + 1)
			addLastCLL(list, data);
		else
		{
			CNODE node = createNode(data);
			CNODE temp = list->tail;
			while(position--)
				temp = temp->next;
			node->next = temp->next;
			temp->next = node;
			list->size++;
		}
	}
}
void deleteFirstCLL(CLL list)
{
	if(list->tail != NULL){
		CNODE current = list->tail;
		CNODE del = current->next;
		current->next = del->next;

		free(del);
		del = NULL;
		list->size--;
		if(list->size == -1)
			list->size = 0;
	}
}

void deleteLastCLL(CLL list)
{
	
	if(list->tail != NULL){
		int pos = list->size;
		CNODE current = list->tail;
		while(--pos)
			current = current->next;

		CNODE del = current->next;
		list->tail = current;
		list->tail->next = del->next;
		free(del);
		del = NULL;
		list->size--;	
	}
	
}
void deleteAtCLL(CLL list, int position)
{
	if(list->tail != NULL)
	{
		if(position == 1)
			deleteFirstCLL(list);
		else if(position == list->size)
			deleteLastCLL(list);
		else
		{
			CNODE temp = list->tail->next;
			position -= 1;
			while(--position)
				temp = temp->next;

			CNODE del = temp->next;
			temp->next = del->next;
			free(del);
			list->size--;
		}
	}
}
void displayCLL(CLL list)
{
	CNODE temp = list->tail->next;
	printf("[%d]: ", list->size);
	int pos = list->size; 
	
	while(pos--){
		printf("%d ",temp->data);
		temp = temp->next;
	}
		
	printf("\n");
}

STACK createSTACK(int capacity){
	STACK stack = (STACK)malloc(sizeof(struct stack));
	stack->capacity = capacity;
	stack->size = 0;
	stack->arr = (element*)malloc(sizeof(element)*capacity);
	return stack;
}

int isFull(STACK stack){
	return (stack->size == stack->capacity);
}

int isEmpty(STACK stack){
	return (stack->size == 0);
}

void push(STACK stack, element data){
	if(!isFull(stack)){
		stack->arr[stack->size++] = data;
	}
}

void pop(STACK stack){
	if(!isEmpty(stack)){
		stack->arr[stack->size--] = 0;
	}
}

void displaySTACK(STACK stack){
	printf("[%d]: ",stack->size);
	for(int i=0;i<stack->size;i++)
		printf("%d ",stack->arr[i]);
	printf("\n");
}