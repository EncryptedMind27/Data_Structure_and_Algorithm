#include "header.h"
#include "bst.h"

int main(){
	// STACK stack = createStack(5);
	// push(stack,1);
	// push(stack,9);
	// push(stack,3);
	// display(stack);

	// pop(stack);
	// display(stack);

	// QUEUE queue = createQueue(5);
	// enqueue(queue,7);
	// enqueue(queue,2);
	// enqueue(queue,5);
	// enqueue(queue,3);
	// enqueue(queue,1);
	// displayQ(queue);

	// dequeue(queue);
	// displayQ(queue);

	// dequeue(queue);
	// displayQ(queue);

	// enqueue(queue,4);
	// enqueue(queue,8);
	// displayQ(queue);

	// enqueue(queue,3);

	NODE root = NULL;
	root = insert(root,10);
	root = insert(root,5);
	root = insert(root,2);
	root = insert(root,7);
	root = insert(root,20);
	root = insert(root,15);
	root = insert(root,25);

	printf("Pre-Order: ");
	preorder(root); printf("\n");

	printf("In-Order: ");
	inorder(root); printf("\n");

	printf("Post-Order: ");
	postorder(root); printf("\n");

	printf("Height: %d\n",computeHeight(root));
	printf("Max Value: %d\n",findMax(root));
	printf("Max Value: %d\n",findMin(root));

	root = deleteBST(root,20);
	printf("Pre-Order: ");
	preorder(root); printf("\n");

	printf("In-Order: ");
	inorder(root); printf("\n");

	printf("Post-Order: ");
	postorder(root); printf("\n");


	return 0;
}