//
//  trees.h
//  trees
//
//  Created by Cabana on 6/3/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#ifndef trees_h
#define trees_h

#include <stdio.h>

typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
} node;

void preOrder(node * root);
void postOrder(node * root);
void inOrder(node * root);
int height(node * root);
void printLeft(node * root);
void top_view(node * root);
void printLevel(node * root, int level);
void LevelOrder(node * root);

#endif /* trees_h */
