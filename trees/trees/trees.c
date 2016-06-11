//
//  trees.c
//  trees
//
//  Created by Cabana on 6/3/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include "trees.h"
#include <stdlib.h>

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

// Helper function for level order traverse
void printLevel(node * root, int level) {
    if(!root)
        return;
    if(level == 1) {
        printf("%d ", root->data);
    }
    else {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}

//         3
//       /   \
//      5     2
//     / \    /
//    1   4  6
// For this tree, the level order traversal
// is 3 -> 5 -> 2 -> 1 -> 4 -> 6
void LevelOrder(node * root)
{
    if(!root)
        return;
    int h = height(root);
    int i = 1;
    for( ; i <= h; i++) {
        printLevel(root, i);
    }
}

// Insert a new node into the tree
//        4                   4
//       / \     ins        /   \
//      2   7     6        2     7
//     / \       -->      / \   /
//    1   3              1   3 6
node * insert(node * root, int value)
{
    if(!root) {
        node * newNode = (node *) malloc(sizeof(node));
        newNode->data = value;
        return newNode;
    }
    else {
        if(value <= root->data) {
            root->left = insert(root->left, value);
        }
        else {
            root->right = insert(root->right, value);
        }
    }
    return root;
}

/*
 * Given a pointer to the root of a Huffman tree
 * and a binary coded string. Print the actual
 * string.
 *
 *               {ϕ,5}
 *            0 /     \ 1
 *           {ϕ,2}   {A,3}
 *          0/   \1
 *       {B,1}  {C,1}
 *
 *
 * S="1001011" should output ABACA
 */
void decode_huff(huffnode * root, char * s)
{
    if(!root) {
        return;
    }
    int i = 0;
    huffnode * temp = root;
    while(s[i] != '\0'){
        int currentInt = s[i] - '0';
        //printf("current int is %d\n", currentInt);
        if(currentInt == 1) {
            if(temp->right) {
                //printf("going right\n");
                temp = temp->right;
                if(!temp->left && !temp->right) {
                    printf("%c", temp->data);
                    temp = root;
                }
            }
        }
        else if(currentInt == 0) {
            if(temp->left) {
                //printf("going left\n");
                temp = temp->left;
                if(!temp->left && !temp->right) {
                    printf("%c", temp->data);
                    temp = root;
                }
            }
        }
        i++;
    }
}

