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

// Node of a general tree
typedef struct node
{
    int data;
    struct node * left;
    struct node * right;
} node;

// Node of a huffman tree
typedef struct huffman_node
{
    int freq;
    char data;
    struct huffman_node * left;
    struct huffman_node * right;
    
} huffnode;

void preOrder(node * root);
void postOrder(node * root);
void inOrder(node * root);
int height(node * root);
void printLeft(node * root);
void top_view(node * root);
void printLevel(node * root, int level);
void LevelOrder(node * root);
node * insert(node * root, int value);
#endif /* trees_h */
