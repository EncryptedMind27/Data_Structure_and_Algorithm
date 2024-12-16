#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct node {
	element data;
	struct node* left;
	struct node* right;
} *NODE;	

NODE createNode(element);
NODE insert(NODE,element);
int findMax(NODE);
int findMin(NODE);
void preorder(NODE);
void inorder(NODE);
void postorder(NODE);
int computeHeight(NODE);
NODE deleteBST(NODE,element);


#endif // BST_H
