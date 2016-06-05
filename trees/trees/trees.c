//
//  trees.c
//  trees
//
//  Created by Cabana on 6/3/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include "trees.h"

// Print the tree's preOrder traversal
void preOrder(node * root) {
    printf("%d ", root->data);
    if(root->left) {
        preOrder(root->left);
    }
    if(root->right) {
        preOrder(root->right);
    }
}

// Print the tree's postOrder traversal
void postOrder(node * root) {
    if(root->left) {
        postOrder(root->left);
    }
    if(root->right) {
        postOrder(root->right);
    }
    printf("%d ", root->data);
}

// Print the tree's inOrder traversal
void inOrder(node * root) {
    if(root->left)
        inOrder(root->left);
    printf("%d ", root->data);
    if(root->right)
        inOrder(root->right);
}

// Return the height of a tree
int height(node * root) {
    if(!root)
        return -1;
    int lh = height(root->left);
    int rh = height(root->right);
    return (((lh <= rh) ? lh : rh) + 1);
}