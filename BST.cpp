 ,#include <stdio.h>

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
    else if (node->)
    if(found)
      return node;
    else
      return NULL;
}

int main () {
    
    return 0;
}
