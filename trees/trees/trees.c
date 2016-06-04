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
void postOrder(node *root) {
    if(root->left) {
        postOrder(root->left);
    }
    if(root->right) {
        postOrder(root->right);
    }
    printf("%d ", root->data);
}
