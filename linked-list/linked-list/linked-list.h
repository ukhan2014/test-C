//
//  linked-list.h
//  linked-list
//
//  Created by Cabana on 5/24/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void Print(Node *head);
Node * Insert_at_end(Node *head,int data);
Node * Insert_at_beginning(Node * head, int data);
Node* InsertNth(Node *head, int data, int position);
Node* Delete(Node *head, int position);
void ReversePrint(Node *head);
Node* Reverse(Node *head);
Node* ReverseRecursive(Node *head);
int CompareLists(Node *headA, Node* headB);

#endif /* linked_list_h */
