#include "header.h"
void sllMain();
void dllMain();
void cllMain();
void stackMain();
int main(){
	//sllMain();
	//dllMain();
	//cllMain();
	stackMain();
	return 0;
}

void sllMain(){
	SLL list = createSLL();
	addFirstSLL(list,4);
	addFirstSLL(list,9);
	addFirstSLL(list,1);
	displaySLL(list);

	addLastSLL(list,10);
	addLastSLL(list,51);
	displaySLL(list);

	insertAtSLL(list,11,3);
	insertAtSLL(list,22,4);
	displaySLL(list);

	deleteFirstSLL(list);
	displaySLL(list);

	deleteLastSLL(list);
	displaySLL(list);

	deleteAtSLL(list,3);
	displaySLL(list);}
void dllMain(){
	DLL list = createDLL();

	addFirstDLL(list,2);
	addFirstDLL(list,42);
	addFirstDLL(list,69);
	displayDLL(list);

	addLastDLL(list,12);
	addLastDLL(list,22);
	displayDLL(list);

	insertAtDLL(list,99,4);
	insertAtDLL(list,10,2);
	displayDLL(list);

	deleteFirstDLL(list);
	displayDLL(list);

	deleteLastDLL(list);
	displayDLL(list);

	deleteAtDLL(list,4);
	displayDLL(list);} 
void cllMain(){
	CLL list = createCLL();
	addFirstCLL(list, 5);
	addFirstCLL(list, 4);
	addFirstCLL(list, 3);
	addFirstCLL(list, 5);
	addFirstCLL(list, 4);
	addFirstCLL(list, 3);
	displayCLL(list);	


	deleteAtCLL(list, 1);
	displayCLL(list);

	deleteAtCLL(list, 5);
	displayCLL(list);

	deleteAtCLL(list, 3);
	displayCLL(list);}
void stackMain(){
	STACK stack = createSTACK(5);
	push(stack,5);
	push(stack,4);
	push(stack,2);
	push(stack,1);
	push(stack,3);
	displaySTACK(stack);

	pop(stack);
	displaySTACK(stack);
}