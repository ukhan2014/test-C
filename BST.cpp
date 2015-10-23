#include <stdio.h>

typedef struct bstNode {
    int data;
    bstNode * left;
    bstNode * right;
} bstNode_t;

bstNode_t * lookup (int data, bstNode_t * tree) {
    bool found = false;
    bstNode_t * node = tree;
    if(node->data == data)
      found = true;
    else if (data < node->data) {
    	return lookup(data, node->left);
    }
    else if (data > node->data) {
    	return lookup(data, node->right);
    }
    if(found)
      return node;
    else
      return NULL;
}

//create and return address of a new node
//arg: data to put in new node
bstNode_t * createNode(int data) {
	bstNode_t node;
	node.data = data;
	return &node;
}

//hook up pointers to a node
//if a certain node from parent, LC, RC
//doesn't exist, just put NULL
void hookupNode(bstNode_t * parent, bstNode * leftChild,
		bstNode_t * rightChild, bstNode_t * node) {
	bstNode_t * temp;
	if(node->data < parent->data) {
		temp = parent->left;
		parent->left = node;
		node->left = temp;
	}
	else if(node->data > parent->data) {
		temp = parent->right;
		parent->right = node;
		node->right = temp;
	}
}

int main () {
	printf("built fine\n");
    return 0;
}
