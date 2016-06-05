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

// Helper function for top_view()
void printLeft(node * root) {
    if(!root) {
        return;
    }
    printLeft(root->left);
    printf("%d ", root->data);
    return;
}

// Print the nodes that are visible if
// tree is viewed from the top down
//        3
//      /   \
//     5     2
//    / \   / \
//   1   4 6   7
//    \       /
//     9     8
// Top View : 1 -> 5 -> 3 -> 2 -> 7
void top_view(node * root)
{
    if(!root) {
        return;
    }
    printLeft(root);
    node * tmp = root;
    while(tmp->right) {
        tmp = tmp->right;
        printf("%d ", tmp->data);
    }
}
