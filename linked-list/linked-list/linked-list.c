//
//  linked-list.c
//  linked-list
//
//  Created by Cabana on 5/24/16.
//  Copyright © 2016 Cabana. All rights reserved.
//

#include "linked-list.h"
#include <stdlib.h>


/*
 Print elements of a linked list on console
 head pointer input could be NULL as well for empty list
 */
void Print(Node *head)
{
    if(!head) {
        return;
    }
    else {
        struct Node * tempPtr = head;
        while(tempPtr) {
            printf("%d\n", tempPtr->data);
            tempPtr = tempPtr->next;
        }
    }
}

/*
 Insert Node at the end of a linked list
 head pointer input could be NULL as well for empty list
 Return the head of the updated list
 */
Node* Insert(Node *head,int data)
{
    Node * tempPtr = head;
    if(tempPtr) {
        while(tempPtr->next) {
            tempPtr = tempPtr->next;
        }
        tempPtr->next = (Node *) malloc(sizeof(Node));
        tempPtr->next->data = data;
    }
    else {
        head = (Node *) malloc(sizeof(Node));
        head->data = data;
    }
    return head;
}
