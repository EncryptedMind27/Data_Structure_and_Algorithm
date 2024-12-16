#include "bst.h"

NODE createNode(element data){
	NODE node = (NODE)malloc(sizeof(struct node));
	if(node == NULL){
		printf("Node Allocatio Failed!\n");
		exit(1);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

NODE insert(NODE root,element data){
	if(root == NULL){
		return createNode(data); 
	} else if (data < root->data){
		root->left = insert(root->left,data);
	} else if (data > root->data){
		root->right = insert(root->right,data);
	}
	return root;
}

int findMax(NODE root){
	while(root && root->right != NULL)
		root = root->right;
	return root->data;
}

int findMin(NODE root){ 
	while(root && root->left)
		root = root->left;
	return root->data;
}

void preorder(NODE root ){
	if(root != NULL){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(NODE root){
	if(root != NULL){ 
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(NODE root){ 
	if(root != NULL){ 
		postorder(root->left);
		postorder(root->right); 
		printf("%d ",root->data);
	}
	
}

int computeHeight(NODE root) {
    // Base case: an empty tree has a height of -1 (edge-based)
    if (root == NULL)
        return 0;
    
    int leftHeight = computeHeight(root->left);
    int rightHeight = computeHeight(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

NODE deleteBST(NODE root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = deleteBST(root->left, data);
    } else if (data > root->data) {
        root->right = deleteBST(root->right, data);
    } else {
        // Node to be deleted found
        if (root->left == NULL) {
            NODE temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NODE temp = root->left;
            free(root);
            return temp;
        }

        NODE temp = root->right;
        while(temp && temp->left != NULL){ 
        	temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}